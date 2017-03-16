/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include <bits/stdc++.h>
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
#define mp make_pair
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN(105);

int a[2505];

void solve(int test){

    int n;
    S("%d",&n);

    FOR(i,1,2500)
        a[i] = 0;

    REP(i,2*n-1)
        REP(j,n)
        {
            int x;
            S("%d",&x);
            a[x]++;
        }

    P("Case #%d: ",test);

    FOR(i,1,2500)
    {
        if(a[i]&1)
            P("%d ",i);
    }

    P("\n");

}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);

    FOR(i,1,t)
        solve(i);

}
