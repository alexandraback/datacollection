#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define nmax 110
#define INF 1000000007
using namespace std;

typedef long long llint;
typedef pair<llint,int> LI;

//VARIABLES
int n,m;
LI a[nmax],b[nmax];
llint f[nmax][nmax];
//FUNCTION PROTOTYPES

void Init();
void Process(int test);

//MAIN
int main()
{
	int test;
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       scanf("%d",&test);
       for (int i=1;i<=test;++i)
       {
            Init();
            Process(i);
       }
       return 0;
}

//FUNCTIONS AND PROCEDURES
void Init()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld%d",&a[i].first,&a[i].second);
    for (int i=1;i<=m;i++) scanf("%lld%d",&b[i].first,&b[i].second);
}

void solve(int x,int y,int v,llint start){
    LI sa[nmax],sb[nmax];
    int na=0,nb=0;
    sa[0]=sb[0]=make_pair(0ll,0);
    for (int i=x;i<=n;i++) if (a[i].second==v)
        sa[++na]=make_pair(sa[na-1].first+a[i].first,i);
    for (int j=y;j<=m;j++) if (b[j].second==v)
        sb[++nb]=make_pair(sb[nb-1].first+b[j].first,j);
    int ii,jj;
    for (int i=1;i<=na;i++)
        for (int j=1;j<=nb;j++){
            ii=sa[i].second+1; jj=sb[j].second+1;
            f[ii][jj]=max(f[ii][jj],start+min(sa[i].first,sb[j].first));
        }
}

void Process(int test)
{
    memset(f,0,sizeof f);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            f[i+1][j]=max(f[i+1][j],f[i][j]);
            f[i][j+1]=max(f[i][j+1],f[i][j]);
            if (a[i].second==b[j].second)
                solve(i,j,a[i].second,f[i][j]);
        }
    llint res=0;
    for (int i=1;i<=n+1;i++)
        for (int j=1;j<=m+1;j++) res=max(res,f[i][j]);
	printf("Case #%d: %lld\n",test,res);
}
