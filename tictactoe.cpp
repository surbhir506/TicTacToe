#include<iostream>
using namespace std;

int greetings()
{
    string ff;
    cout<<"\nWould you like to play again? (Y/N): ";
    cin>>ff;

    if(ff == "Y")
    {
        return 1;
    }
    else if(ff == "N")
    {
        cout<<"Byee!!";
        return 0;
    }
    else
    {
        cout<<endl<<ff<<" is not a valid answer.";
        return greetings();
    }
}

int win(char ar[3][3],char s[2],string *st,int i)
{
    if(ar[0][0] == ar[0][1] && ar[0][1] == ar[0][2] && ar[0][0] != '.')
    {
        cout<<"Game Over!!"<<endl;
        if(ar[0][0] == s[0])
        {
            cout<<st[0]<<" Wins."<<endl;
            return 1;
        }
        else
        {
            cout<<st[1]<<" Wins."<<endl;
            return 1;
        }
    }
    else if(ar[1][0] == ar[1][1] && ar[1][1] == ar[1][2] && ar[1][0] != '.')
    {
        cout<<"Game Over!!"<<endl;
        if(ar[1][0] == s[0])
        {
            cout<<st[0]<<" Wins."<<endl;
            return 1;
        }
        else
        {
            cout<<st[1]<<" Wins."<<endl;
            return 1;
        }
    }
    else if(ar[2][0] == ar[2][1] && ar[2][1] == ar[2][2] && ar[2][0] != '.')
    {
        cout<<"Game Over!!"<<endl;
        if(ar[2][0] == s[0])
        {
            cout<<st[0]<<" Wins."<<endl;
            return 1;
        }
        else
        {
            cout<<st[1]<<" Wins."<<endl;
            return 1;
        }
    }
    else if(ar[0][0] == ar[1][0] && ar[1][0] == ar[2][0] && ar[0][0] != '.')
    {
        cout<<"Game Over!!"<<endl;
        if(ar[0][0] == s[0])
        {
            cout<<st[0]<<" Wins."<<endl;
            return 1;
        }
        else
        {
            cout<<st[1]<<" Wins."<<endl;
            return 1;
        }
    }
    else if(ar[0][1] == ar[1][1] && ar[1][1] == ar[2][1] && ar[0][1] != '.')
    {
        cout<<"Game Over!!"<<endl;
        if(ar[0][1] == s[0])
        {
            cout<<st[0]<<" Wins."<<endl;
            return 1;
        }
        else
        {
            cout<<st[1]<<" Wins."<<endl;
            return 1;
        }
    }
    else if(ar[0][2] == ar[1][2] && ar[1][2] == ar[2][2] && ar[0][2] != '.')
    {
        cout<<"Game Over!!"<<endl;
        if(ar[0][2] == s[0])
        {
            cout<<st[0]<<" Wins."<<endl;
            return 1;
        }
        else 
        {
            cout<<st[1]<<" Wins."<<endl;
            return 1;
        }
    }
    else if(ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2] && ar[0][0] != '.')
    {
        cout<<"Game Over!!"<<endl;
        if(ar[0][0] == s[0])
        {
            cout<<st[0]<<" Wins."<<endl;
            return 1;
        }
        else
        {
            cout<<st[1]<<" Wins."<<endl;
            return 1;
        }
    }
    else if(ar[0][2] == ar[1][1] && ar[1][1] == ar[2][0] && ar[0][2] != '.')
    {
        cout<<"Game Over!!"<<endl;
        if(ar[0][2] == s[0])
        {
            cout<<st[0]<<" Wins."<<endl;
            return 1;
        }
        else
        {
            cout<<st[1]<<" Wins."<<endl;
            return 1;
        }
    }
}

int printt(char ar[3][3])
{
    cout<<ar[0][0]<<" | "<<ar[0][1]<<" | "<<ar[0][2]<<endl; 
    cout<<"----------\n";
    cout<<ar[1][0]<<" | "<<ar[1][1]<<" | "<<ar[1][2]<<endl;
    cout<<"----------\n";
    cout<<ar[2][0]<<" | "<<ar[2][1]<<" | "<<ar[2][2]<<endl;
}

int inputt(int x,int y,int i,char ar[3][3],char s[2])
{
    cout<<"\nChoose a row number (0 to 2):";
    cin>>x;
    if(x < 0 || x > 2)
    {
        cout<<x<<" is not a valid row.\n";
        return inputt(x,y,i,ar,s);
    }
    cout<<"\nChoose a column number (0 to 2):";
    cin>>y;
    if(y < 0 || y > 2)
    {
        cout<<y<<" is not a valid column.\n";
        return inputt(x,y,i,ar,s);
    }

    if(ar[x][y] == '.')
    {
        if(i%2 == 1)
        {
            ar[x][y] = s[0];
        }
        else
        {
            ar[x][y] = s[1];
        }
    }
    else
    {
        cout<<"The Cell is already occupird. Try Again.";
        return inputt(x,y,i,ar,s);
    }
}

int steps(char ar[3][3],char s[2],string *st)
{
    
     for(int i=1;i<10;i++)
    {
        int x,y;
        printt(ar);

        int a = win(ar,s,st,i);
        if(a == 1)
        {
            return 1;
        }

        if(i%2 == 1)
        {
            cout<<"Player of current turn: "<<st[0];
        }
        else
        {
            cout<<"Player of current turn: "<<st[1];
        }

        inputt(x,y,i,ar,s); 
    }
    cout<<"Draw!!"<<endl;
    return 1;
}

void firstplayer(string *st,char *s)
{
    string fp;
    cout<<"Who plays first, "<<st[0]<<" or "<<st[1]<<"?\n";
    cin>>fp;
    if(fp == st[0])
    {
        
    }
    else if(fp == st[1])
    {
        string temp;
        temp = st[0];
        st[0] = st[1];
        st[1] = temp;

        s[0] = 'Y';
        s[1] = 'X';
    }
    else
    {
        cout<<fp<<" is not a registered player.\n";
        return firstplayer(st,s);
    }
}

int main()
{
    char ar[3][3] = {'.','.','.','.','.','.','.','.','.'};

    string st[2];
    char s[2] = {'X','Y'};
    cout<<"Enter a name for the X player: ";
    cin>>st[0];
    cout<<"Enter a name for the Y player: ";
    cin>>st[1];

    firstplayer(st,s);

    steps(ar,s,st);

    if(greetings())
    {
        main();
    }

    return 0;
}