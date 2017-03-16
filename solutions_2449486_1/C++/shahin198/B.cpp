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
int A[105][105];
char T[105][105];
int r=0,N,M;

int main(){
    //FILEIO("B-small-practice");
   freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int max=0,p;

    RI(n);
    LPI(i,n)
    {
        MS0(T);
        max=0;
        RII(x,y);
        N=x;M=y;
        LPI(j,x)
        {
            LPI(k,y)
            {
                RI(m);
                A[j][k]=m;
                max=MAX(max,m);
            }
        }
        LPI(j,x)
        {
            LPI(q,max+1)
            {
            p=0;
            LPI(k,y)
            {if(A[j][k]>q+1)
            break;
            p++;
            }
            if(p==y)
            {
                LPI(k,y)
                if(A[j][k]==q+1)
                T[j][k]=1;
            }
            }
        }
        LPI(j,y)
        {
            LPI(q,max+1)
            {
            p=0;
            LPI(k,x)
            {
                if(A[k][j]>q+1)
                break;
            p++;
            }
            if(p==x)
            {
                LPI(k,x)
                if(A[k][j]==q+1)
                T[k][j]=1;
            }
            }
        }
        r=0;
        LPI(j,x)
        {
            LPI(k,y)
            {
                if(T[j][k]==0)
                {
                    r=1;
                    j=x;
                    break;
                }
            }
        }
        if(r==1)
        printf("Case #%d: NO\n",i+1);
        else
        printf("Case #%d: YES\n",i+1);

    }
    return 0;
}


