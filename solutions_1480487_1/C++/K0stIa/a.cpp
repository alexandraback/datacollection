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

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("A-small-attempt5.in","r",stdin);
        freopen("A-small-attempt5.txt","w",stdout);
	#endif

    const double EPS = 1e-9;

    int T;
    cin >> T;

    rep(cs,T)
    {
        int N;
        cin >> N;

        VI s(N);
        rep(i,N) cin >> s[i];

        double X = 0, rem;
        vector<double> ans(N,-1);

        rep(i,N) X += s[i];
        rem = X;

        int T = N;

        for(bool ok = false; ok;)
        {
            ok = false;
            rep(i,N)
            {
                if (ans[i]!=-1) continue;

                if ((X+rem)/(X*T) - s[i]/X<0 || fabs((X+rem)/(X*T) - s[i]/X)<EPS)
                {
                    ans[i]=0;
                    T--;
                    rem -= s[i];
                    ok = true;
                    break;
                }
            }
        }

        rep(i,N)
        {
            if (ans[i]==-1)
                ans[i]= 100*((X+rem)/(X*T) - s[i]/X);
        }

        printf("Case #%d: ", cs+1);
        rep(i,N) printf("%.6f ", ans[i]);
        printf("\n");
    }

	return 0;
}
