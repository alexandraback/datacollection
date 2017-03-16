#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<bitset>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;

#define PB push_back
#define MP make_pair
#define SIZE(X) (int)(X).size()

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, l, h) for(int i = (l); i < (h); i++)
#define RREP(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define FORD(i, l, h) for(int i = (int)(h-1); i >= (l); i--)

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string>VS;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef __int64 ll;

const ll oo = (1LL)<<40;
const int MAXN = 105;
const int MOD = 1000000007;
const double eps = 1e-8;
int N;
ll P, Q;

ll gcd(ll a, ll b) {
	if(a == 0 || b == 0) return a+b;
	//cout << b << " " << a << endl;
	return gcd(b, a%b);
}
 
int main()
{
	int T;
	//freopen("a-small.in", "r", stdin);
	//freopen("a-small.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	cin >> T;
	FOR(_, 1, T+1) {
		scanf("%I64d/%I64d", &P, &Q);
//		cin >> P >> Q;
	//	if(P > (1LL<<32)) cout << P << endl;
		ll g = gcd(P, Q);
		P /= g; Q /= g;

		//cout << P << " " << Q << " " << g << endl;
		cout << "Case #" << _ << ": ";
		if(((Q-1)&Q)) {
			cout << "impossible" << endl;
		} else {
			ll ans = 0;
			while(P < Q) {
				Q /= 2;
				ans ++;
			}
			cout << ans << endl;
		}
		
		
	}
	return 0;
}

/*

*/
