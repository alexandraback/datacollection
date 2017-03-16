#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
long test,cas;
string s[5];
long a[5][5];
long n,x,i,j;
bool flag;
int main()
{
    n=4;
    for (cin>>test,cas=1;cas<=test;cas++)
    {
        flag=1;
        for (i=0;i<4;i++) cin>>s[i];
        cout<<"Case #"<<cas<<": ";
        for (i=0;i<4;i++)
            for (j=0;j<4;j++)
            {
                a[i][j]=0;
                if (s[i][j]=='X') a[i][j]=1;
                if (s[i][j]=='O') a[i][j]=2;
                if (s[i][j]=='T') a[i][j]=3;
                if (s[i][j]=='.') flag=0;
            }
        for (i=0;i<4;i++)
        {
            x=3;
            for (j=0;j<4;j++) x&=a[i][j];
            if (x==1) goto Xwin;
            if (x==2) goto Owin;
            x=3;
            for (j=0;j<4;j++) x&=a[j][i];
            if (x==1) goto Xwin;
            if (x==2) goto Owin;
        }
        x=a[0][0]&a[1][1]&a[2][2]&a[3][3];
            if (x==1) goto Xwin;
            if (x==2) goto Owin;
        x=a[0][3]&a[1][2]&a[2][1]&a[3][0];
            if (x==1) goto Xwin;
            if (x==2) goto Owin;
        if (flag) goto draw;
        cout<<"Game has not completed\n";
        if (0) draw:cout<<"Draw\n";
        if (0) Xwin:cout<<"X won\n";
        if (0) Owin:cout<<"O won\n";
    }
//    system("PAUSE");
    return 0;
}
