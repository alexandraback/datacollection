#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOREACH(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define FILL(a, b) memset(a, b, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define SZ(c) ((int)(c).size())
#define X(p) (p).first
#define Y(p) (p).second
#define debug(x) cerr << #x << " = " << x << "\n";
//#define debugv(v) cerr << #v << " = "; FOREACH(it, v) cerr << *it << ",\n";

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<string, string> PSS;
typedef vector<int> VI;
typedef vector<VI> VII; 
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<PII> VPII;

const int inf = 1000000000;
const LL infll = LL(inf) * LL(inf);
const double PI = 4 * atan(1.0);
const int dx[] = {-1, -1, -1, 0, 1, 1,  1,  0};
const int dy[] = {-1,  0,  1, 1, 1, 0, -1, -1};

template<class T> string i2s(T x) { ostringstream ss; ss << x; return ss.str(); }
int s2i(string s) { istringstream ss(s); int x; ss >> x; return x;}
LL s2ll(string s) { istringstream ss(s); LL x; ss >> x; return x;}

inline double dist(double x1, double y1, double x2, double y2) { return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); }

int dict[200000][7];

int main() {
	//ifstream in("C-large.in");
	//ofstream out("output.out");
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int s[10];
	FOR(i, 10, 200000) {
		int t = i;
		int len = 0;
		while (t) {
			s[len++] = t % 10;
			t /= 10;
		}
		int cnt = 0;
		FOR(j, 1, len-1) {
			int d = 0;
			FOR(k, j, j+len-1) {
				d = d * 10 + s[len-k%len-1];
			}
			REP(k, cnt) if ( d == dict[i][k]) {
				goto next;
			}
			if ( d > i ) {
				dict[i][cnt++] = d;
			}
next:
			;
		}
	}

	int T;
	scanf("%d", &T);
	REP(i, T) {
		int A, B;
		scanf("%d %d", &A, &B);
		int ans = 0;
		FOR(j, A, B) {
			for (int k = 0; dict[j][k] > 0; ++k) {
				if ( dict[j][k] >= A && dict[j][k] <= B) {
					++ans;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, ans);
	}
	return 0;
}
