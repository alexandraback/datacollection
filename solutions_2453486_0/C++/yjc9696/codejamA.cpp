#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,k,l,n,m,s,an,sum;
int ok;
int w[5][2];
char a[5][5];
void work(int x,int y,int k)
{
    if (an!=-1) return;
    int s0,s1,s2;
    s0=s1=s2=0;
    for (int i=1;i<=4;i++)
    {
        if (a[x][y]=='X') s0++;
        if (a[x][y]=='O') s1++;
        if (a[x][y]=='T') s2++;
        x+=w[k][0];y+=w[k][1];
    }
    if (s0+s2==4) {an=1;return;}
    if (s1+s2==4) {an=2;return;}
}
int main()
{
    freopen("a1.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    scanf("%d",&T);
    w[0][0]=0;
    w[0][1]=1;
    w[1][0]=1;
    w[1][1]=0;
    w[2][0]=1;
    w[2][1]=1;
    w[3][0]=1;
    w[3][1]=-1;
    for (int t=1;t<=T;t++)
    {
        for (int i=1;i<=4;i++)
        {
            getchar();
            scanf("%s",a[i]+1);
            //for (int j=1;j<=4;j++)
            //if (a[i][j]!='.') an=4;
        }
    an=-1;
    for (int i=1;i<=4;i++)
    work(i,1,0);
    for (int i=1;i<=4;i++)
    work(1,i,1);
    work(1,1,2);
    work(1,4,3);
    if (an==-1)
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
        if (a[i][j]=='.') an=4;
    printf("Case #%d: ",t);
    if (an==1) printf("X won\n");
    if (an==2) printf("O won\n");
    if (an==-1) printf("Draw\n");
    if (an==4) printf("Game has not completed\n");
    }
    //system("pause");
    return 0;

}
