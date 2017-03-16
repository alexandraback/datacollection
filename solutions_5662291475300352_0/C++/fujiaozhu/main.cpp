// program c
#include <bits/stdc++.h>
using namespace std;

#define PB              push_back
#define SIZE(x)         (int)x.size()
#define clr(x,y)        memset(x,y,sizeof(x))
#define MP(x,y)         make_pair(x,y)
#define RS(n)           scanf ("%s", n)
#define ALL(t)          (t).begin(),(t).end()
#define FOR(i,n,m)      for (int i = n; i <= m; i ++)
#define ROF(i,n,m)      for (int i = n; i >= m; i --)
#define IT              iterator
#define FF              first
#define SS              second

typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long      ull;
typedef vector<int>             vint;
typedef vector<string>          vstring;
typedef pair<int, int>          PII;


const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

int main (){
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("data.out", "w", stdout);
	int T;
	cin >> T;
	FOR (cas, 1, T){
		int n;
		cin >> n;
		vector<PII> vec;
		FOR (i, 1, n){
			int d, t, m;
			cin >> d >> t >> m;
			if (t == 1){
				vec.PB (MP (d, m));
			}else{
				vec.PB (MP (d, m));
				vec.PB (MP (d, m+1));
			}
		}
		double x1 = (360.0-vec[0].FF)/360.0*vec[0].SS;
		double x2 = (360.0-vec[1].FF)/360.0*vec[1].SS;
		double x3 = (720.0-vec[0].FF)/360.0*vec[0].SS;
		double x4 = (720.0-vec[1].FF)/360.0*vec[1].SS;
		int ans = 1;
		if (x1 < x2 && x3 > x2){
			ans = 0;
		}
		if (x2 < x1 && x4 > x1){
			ans = 0;
		}
		printf ("Case #%d: %d\n", cas, ans);
	}
	return 0;
}


