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

vector< vector<char> > ans[2];
vector<char> v;
int l;
char a[2][107];

void dfs(int i, int p)
{
	if(i == l) {

		ans[p].PB(v);
		return ;
	}

	if(a[p][i] != '?') {
		
		v.PB(a[p][i]);
		dfs(i + 1, p);
		v.pop_back();
	}
	else {
		for(int j = 0; j <= 9; j ++) {

			v.PB(j + '0');
			dfs(i + 1, p);
			v.pop_back();
		}
	}
}

int main()
{
#ifdef kfoozminus
	freopen("jam1BB", "w", stdout);
#endif
	int tc, cs, i, j, ii, jj, iii, jjj, sz, sz1, sz2, sz3, k, n, m, mn;

	scanf("%d", &tc);
	for(cs = 1; cs <= tc; cs ++) {

		scanf("%s %s", a[0], a[1]);

		l = strlen(a[0]);
		dfs(0, 0);
		l = strlen(a[1]);
		dfs(0, 1);

		mn = INF;

		for(i = 0, sz1 = ans[0].size(); i < sz1; i ++) {
			for(j = 0, sz2 = ans[1].size(); j < sz2; j ++) {
				
				n = 0;
				for(k = 0, sz3 = ans[0][i].size(); k < sz3; k ++) n = (n * 10) + ans[0][i][k] - '0';

				m = 0;
				for(k = 0, sz3 = ans[1][j].size(); k < sz3; k ++) m = (m * 10) + ans[1][j][k] - '0';

				//dbg(n, m);
				
				int diff = abs(n - m);
				if(diff < mn) {

					mn = abs(n - m);
					ii = i;
					jj = j;
					iii = n;
					jjj = m;
				}
				else if(mn == diff) {
					if(iii > n) {

						ii = i;
						jj = j;
						iii = n;
						jjj = m;
					}
					else if(iii == n) {

						if(jjj > m) {

							ii = i;
							jj = j;
							iii = n;
							jjj = m;
						}
					}
				}
			}
		}
		printf("Case #%d: ", cs);
		for(i = 0, sz = ans[0][ii].size(); i < sz; i ++) printf("%c", ans[0][ii][i]);
		printf(" ");
		for(i = 0, sz = ans[1][jj].size(); i < sz; i ++) printf("%c", ans[1][jj][i]);
		printf("\n");
		ans[0].clear();
		ans[1].clear();
	}
        return 0;
}

