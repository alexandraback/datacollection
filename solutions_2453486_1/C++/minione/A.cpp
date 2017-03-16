#include<iostream>
#include<cstdio>
using namespace std;
string st[4];
int T;

bool CheckColumn(char ch)
{
    int s,t;
    for (int i=0; i<4; ++i)
    {
        s=t=0;
        for (int j=0; j<4; ++j)
        {
            if (st[i][j]==ch) s++;
            if (st[i][j]=='T') t++;
        }
        if ((s==4) || ((s==3) && (t==1))) return true;
    }
    return false;
}

bool CheckRow(char ch)
{
    int s,t;
    for (int i=0; i<4; ++i)
    {
        s=t=0;
        for (int j=0; j<4; ++j)
        {
            if (st[j][i]==ch) s++;
            if (st[j][i]=='T') t++;
        }
        if ((s==4) || ((s==3) && (t==1))) return true;
    }
    return false;
}
bool CheckDiago(char ch)
{
    int s,t;
    s=t=0;
    for (int i=0; i<4; ++i)
    {
        if (st[i][i]==ch) s++;
        if (st[i][i]=='T') t++;
    }
    if ((s==4) || ((s==3) && (t==1))) return true;
    s=t=0;
    for (int i=0; i<4; ++i)
    {
        if (st[i][3-i]==ch) s++;
        if (st[i][3-i]=='T') t++;
    }
    if ((s==4) || ((s==3) && (t==1))) return true;
    return false;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    cin>>T;
    for (int t=1; t<=T; ++t)
    {
        for (int i=0; i<4; ++i) cin>>st[i];
        /*    for (int i=0; i<4; ++i)
            {
                for (int j=0; j<4; ++j) cout<<st[i][j];
                cout<<endl;
            }*/
        bool Owin,Xwin;
        Owin=Xwin=false;
        Owin=Owin | CheckColumn('O');
        Owin=Owin | CheckRow('O');
        Owin=Owin | CheckDiago('O');
        Xwin=Xwin | CheckColumn('X');
        Xwin=Xwin | CheckRow('X');
        Xwin=Xwin | CheckDiago('X');
        if ((Owin) || (Xwin))
        {
            cout<<"Case #"<<t<<": ";
            if (Owin) cout<<"O won"<<endl;
            else cout<<"X won"<<endl;
        }
        else
        {
            bool flag=true;
            for (int i=0; i<4; ++i)
                for (int j=0; j<4; ++j)
                    if (st[i][j]=='.') flag=false;
            cout<<"Case #"<<t<<": ";
            if (flag) cout<<"Draw"<<endl;
            else cout<<"Game has not completed"<<endl;
        }

    }
    return 0;
}
