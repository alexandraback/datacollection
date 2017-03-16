#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
#define Nobody_Won 999

int check(string s)
{
    string O = "OOOO";
    string X = "XXXX";
    if(s.size()==4)
    {
        int k=999;
        for(int i=0;i<4;i++)
            if(s[i]=='T')
            {
                k=i;
                s[i]='X';
            }

        if(X==s) return 2;
        if(k!=999)
            s[k]='O';

        if(O==s) return 3;
    }
    return Nobody_Won;

}

int Check_Board(string b[])
{
    int ans;
    string temp;
    for(int i=0;i<4;i++)
    {
        ans=check(b[i]);
        if(ans==2||ans==3)
            return ans;
    }
    for(int i=0;i<4;i++)
    {
        temp="";
        for(int j=0;j<4;j++)
        {
            temp+=b[j][i];
        }
        ans=check(temp);
        if(ans==2||ans==3)
            return ans;
    }

    temp="";
    for(int i=0;i<4;i++)
        temp+=b[i][i];
    ans=check(temp);
    if(ans==2||ans==3)
        return ans;

    temp="";
    for(int j=3,i=0; j>=0; j--,i++)
        temp+=b[i][j];

    ans=check(temp);
    if(ans==2||ans==3)
        return ans;



    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(b[i][j]=='.')
                return 1;



    return 0;

}

int main()
{
    freopen("A-small-attempt3.in", "r", stdin);
    freopen("A-small-attempt3.out", "w", stdout);
    int T, result;
    string board[4], b[4];
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        for(int i=0;i<4;i++)
            cin>>board[i];

        result=Check_Board(board);

        cout<<"Case #"<<t<<": ";
        if(result==0)
            cout<<"Draw"<<endl;
        else if(result==1)
            cout<<"Game has not completed"<<endl;
        else if(result==2)
            cout<<"X won"<<endl;
        else
            cout<<"O won"<<endl;

    }

}
