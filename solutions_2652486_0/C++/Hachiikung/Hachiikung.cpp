/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<utility>
using namespace std;
#define REP(i,FN) for(int i=0;i<FN;i++)
#define FOR(i,ST,FN) for(int i=ST;i<=FN;i++)
#define FORD(i,FN,ST) for(int i=FN;i>=ST;i--)
#define FORX(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();i++)
#define pause system("pause")
#define S scanf
#define P printf
#define X first
#define Y second
#define pb push_back
#define PII pair<int,int>
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN(205);

int a[20],b[20],exist[MAXN],pr;

int DFS(int c,int n,int m,int k){

    if(c==n)
    {
        memset(exist,0,sizeof(exist));

        REP(i,1<<n)
        {
            bool ok=1;
            int product=1;

            REP(j,n)
             if(i&(1<<j))
              product*=a[j];

            exist[product]=1;
        }

        REP(i,k)
         if(!exist[b[i]])
          return 0;

        if(!pr)
        {
            pr=1;
            REP(i,n)
             P("%d",a[i]);
            P("\n");
        }

        return 0;
    }

    FOR(i,2,m)
    {
        a[c]=i;
        DFS(c+1,n,m,k);
    }

}

void solve2(int n,int m,int k){

    REP(i,k)
     S("%d",&b[i]);

    pr=0;

    DFS(0,n,m,k);

    if(!pr)
    {
        REP(i,n)
         P("1");
        P("\n");
    }

}

void solve(int t){

    int r,n,m,k;
    S("%d%d%d%d",&r,&n,&m,&k);

    P("Case #%d:\n",t);

    while(r--)
     solve2(n,m,k);

}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
     solve(i);

}
