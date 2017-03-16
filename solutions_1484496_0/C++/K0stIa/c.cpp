#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>

using namespace std;

#define pb push_back
#define INF 101111111
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define rep(i,n) FOR(i,0,n)
#define ford(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define CL(a,v) memset((a),(v),sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;

const int maxn = 555;
ll x[maxn];
const int NN = (1<<20)+ 20;
ll dp[NN];
pair<ll,int> from[NN];

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("C-small-attempt0.in","r",stdin);
        freopen("C-small-attempt0.txt","w",stdout);
	#endif

    int T;
    cin >> T;


    FOR(cs,1,T+1)
    {
        int N;
        cin >> N;

        rep(i,N) cin >> x[i];

        CL(dp,0);

        rep(s,1<<N)
        {
            rep(k,N)
            {
                int nxt = (1<<k)|s;

                if(nxt == s) continue;

                dp[nxt] = dp[s] + x[k];
            }
        }

        rep(s,1<<N) from[s] = mp(dp[s],s);

        sort(from,from+(1<<N));
        int m = unique(from,from+(1<<N)) - from;

        int s1 = -1, s2 = -1;

        FOR(i,1,m)
        {
            if(from[i].X == from[i-1].X)
            {
                s1 = from[i].Y, s2 = from[i-1].Y;
                break;
            }
        }

        printf("Case #%d:\n",cs);

        if(s1 == -1)
        {
            printf("Impossible\n");
        }
        else
        {
            rep(k,N) if((1<<k)&s1) printf("%d ",x[k]); printf("\n");
            rep(k,N) if((1<<k)&s2) printf("%d ",x[k]); printf("\n");
        }
    }

	return 0;
}
