//
/*
ID: kfoozmi1
LANG: C++
TASK:
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef kfoozminus
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

void faltu() {
	cerr << endl;
}

template <typename T>
void faltu(T a[], int n) {
	for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
	cerr << endl;
}

template <typename First, typename ... hello>
void faltu(First arg, const hello&... rest) {
	cerr << arg << ' ';
	faltu(rest...);
}
#else
#define dbg(args...)
#endif

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define vsort(v) sort(v.begin(), v.end())
#define PQ priority_queue
#define PI acos(-1)
#define EPS 1e-9

#define B1 43
#define B2 43

#define MOD1 1000000007
#define MOD2 1000000009

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
int dxx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dyy[] = {0, +1, 0, -1, +1, -1, +1, -1};

inline bool checkBit(ll n, int i) { return n & (1LL << i); }
inline ll setBit(ll n, int i) { return n | (1LL << i); }
inline ll resetBit(ll n, int i) { return n & (~ (1LL << i)); }
inline bool EQ(double a, double b) { return fabs(a-b) < EPS; }

#define INF 100000000
#define MOD  1000000007
#define MX 100007

ll bigMod(ll a, ll b)
{
	ll r = 1;
	while(b) {
		if(b & 1) (r *= a) %= MOD;
		b >>= 1;
		(a *= a) %= MOD;
	}
	return r;
}

vector<string> v;
vector<int> ans;
int cnt[507];
char s[20007];

int main()
{
#ifdef kfoozminus
	freopen("jam1BA", "w", stdout);
#endif
	v.PB("ZERO");
	v.PB("TWO");
	v.PB("FOUR");
	v.PB("SIX");
	v.PB("EIGHT");
	v.PB("ONE");
	v.PB("THREE");
	v.PB("FIVE");
	v.PB("SEVEN");
	v.PB("NINE");

	int a[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

	int tc, cs, i, j, sz;

	scanf("%d", &tc);
	for(cs = 1; cs <= tc; cs ++) {

		scanf("%s", s);
		for(i = 'A'; i <= 'Z'; i ++) cnt[i] = 0;

		for(i = 0; s[i]; i ++) {

			cnt[ s[i] ] ++;
		}

		printf("Case #%d: ", cs);

		for(i = 0; i <= 9; i ++) {

			while(true) {
				for(j = 0, sz = v[i].size(); j < sz; j ++) if(cnt[ v[i][j] ] == 0) break;
				if(j < sz) break;
				for(j = 0; j < sz; j ++) cnt[ v[i][j] ] --;
				ans.PB( a[i] );
			}
		}

		vsort(ans);
		for(j = 0, sz = ans.size(); j < sz; j ++) printf("%d", ans[j]); printf("\n");

		ans.clear();
	}
        return 0;
}

