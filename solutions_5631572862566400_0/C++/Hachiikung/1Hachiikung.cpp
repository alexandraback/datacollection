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
const int MAXN(1005);

int f[MAXN];

void solve(int test){

    int n;
    S("%d",&n);
    FOR(i,1,n)
        S("%d",&f[i]);

    int ans = 0;

    REP(i,1<<n)
    {
        vector<int>a;

        REP(j,n)
        {
            if(i&(1<<j))
                a.pb(j+1);
        }

        do
        {
            bool fail = false;

            int m = a.sz;

            REP(j,m)
            {
                if(!(a[(j+1)%m] == f[a[j]] || a[(j-1+m)%m] == f[a[j]]))
                {
                    fail = true;
                    break;
                }
            }

            if(!fail)
            {
                ans = max(ans, m);
            }

        }while(next_permutation(a.begin(),a.end()));

    }

    P("Case #%d: %d\n",test,ans);

}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);

    FOR(i,1,t)
        solve(i);

}
