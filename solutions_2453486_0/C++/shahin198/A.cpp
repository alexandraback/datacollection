//DER.......
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<functional>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

// #defines
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define LPI(i,n) for(int i=0;i<(n);i++)
#define LPI1(i,a,b) for(int i=(a);i<=(b);i++)
#define LPIL(i,x) for(int i=0;x[i];i++)
#define LPD(i,n) for(int i=(n)-1;i>=0;i--)
#define LPD1(i,a,b) for(int i=(a);i>=(b);i--)
#define I(x) scanf("%d",&x)
#define RI(x) int x;I(x)
#define II(x,y) scanf("%d%d",&x,&y)
#define RII(x,y) int x,y;II(x,y)
#define III(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define RIII(x,y,z) int x,y,z;III(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
char A[10][10];
int main(){
    //FILEIO("B-small-practice");
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int i,j,xt,ot,t,x,o;
        RI(b);
        LPI(e,b)
        {
            scanf("%s%s%s%s",A[0],A[1],A[2],A[3]);
            printf("Case #%d:",e+1);
            xt=0;ot=0;
            for(i=0;i<4;i++)
            {
                x=0;o=0;t=0;
                for(j=0;j<4;j++)
                {if(A[i][j]=='X')
                x++;
                else if(A[i][j]=='O')
                o++;
                else if(A[i][j]=='T')
                t=1;
                }
            if(x==4)
            {
                printf(" X won\n");
                break;
            }
            if(o==4)
            {
                 printf(" O won\n");
                break;
            }
            if(t==1&&x==3)
            xt=1;
            if(t==1&&o==3)
            ot=1;
            }
            if(x==4||o==4)
            continue;
            for(j=0;j<4;j++)
            {
                 x=0;o=0;t=0;
            for(i=0;i<4;i++)
            if(A[i][j]=='X')
            x++;
            else if(A[i][j]=='O')
            o++;
            else if(A[i][j]=='T')
                t=1;

            if(x==4)
            {
                printf(" X won\n");
                break;
            }
            if(o==4)
            {
                 printf(" O won\n");
                break;
            }
            if(t==1&&x==3)
            xt=1;
            if(t==1&&o==3)
            ot=1;
            }
            if(x==4||o==4)
            continue;

            x=0;o=0;
            for(i=0;i<4;i++)
            if(A[i][i]=='X')
            x++;
            else if(A[i][i]=='O')
            o++;
            else if(A[i][i]=='T')
                t=1;
            if(x==4)
            {
                printf(" X won\n");
            }
            if(o==4)
            {
                 printf(" O won\n");
            }
            if(t==1&&x==3)
            xt=1;
            if(t==1&&o==3)
            ot=1;
            if(x==4||o==4)
            continue;

            x=0;o=0;
            for(i=0;i<4;i++)
            if(A[i][3-i]=='X')
            x++;
            else if(A[i][3-i]=='O')
            o++;
            else if(A[i][3-i]=='T')
                t=1;
            if(x==4)
            {
                printf(" X won\n");
            }
            if(o==4)
            {
                 printf(" O won\n");
            }
            if(t==1&&x==3)
            xt=1;
            if(t==1&&o==3)
            ot=1;
            if(x==4||o==4)
            continue;
               if(xt==1&&ot==1)
               printf(" Draw\n");
               else if(xt==1)
               printf(" X won\n");
               else if(ot==1)
               printf(" O won\n");
               else
               {
                   for(i=0;i<4;i++)
                   for(j=0;j<4;j++)
                   if(A[i][j]=='.')
                   {
                       i=100;
                       break;
                   }
                   if(i==4)
                   printf(" Draw\n");
                   else
                   printf(" Game has not completed\n");
               }

        }
    return 0;
}


