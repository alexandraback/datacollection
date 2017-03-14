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

const double eps = 1e-6;
const int inf = 1000000000;
const LL infll = LL(inf) * LL(inf);
const double PI = 4 * atan(1.0);
const int dx[] = {-1, -1, -1, 0, 1, 1,  1,  0};
const int dy[] = {-1,  0,  1, 1, 1, 0, -1, -1};

template<class T> string i2s(T x) { ostringstream ss; ss << x; return ss.str(); }
int s2i(string s) { istringstream ss(s); int x; ss >> x; return x;}
LL s2ll(string s) { istringstream ss(s); LL x; ss >> x; return x;}

inline double dist(double x1, double y1, double x2, double y2) { return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); }

const int n = 50;

int main() {
	//ifstream in("C-large.in");
	//ofstream out("output.out");
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	REP(t, T) {
		int H, W, D;
		scanf("%d %d %d", &H, &W, &D); getchar();
		char ch;
		double x, y;
		vector<PDD> points;
		REP(h, H) {
			REP(w, W) {
				scanf("%c", &ch);
				if ( ch == 'X' ) {
					x = w-0.5; y = h-0.5;
				}
			}
			getchar();
		}
		double dx[] = { (W-2-x)*2, (x)*2 };
		double dy[] = { (H-2-y)*2, (y)*2 };

		points.pb( mp(x, y) );
		double lx = x;
		double ly = y;
		double nx, ny;
		REP(i, n) {
			nx = lx + dx[i&1];
			ny = ly;
			lx = nx; ly = ny;
			points.pb( mp(nx, ny) );
		}
		REP(i, n) {
			double lx = points[i].first;
			double ly = points[i].second;
			double nx, ny;
			REP(j, n) {
				nx = lx;
				ny = ly + dy[j&1];
				lx = nx; ly = ny;
				points.pb( mp(nx, ny) );
			}
		}

		int sz = SZ(points);
		REP(i, sz) {
			double xx = points[i].first;
			double yy = points[i].second;
			points.pb( mp(xx, -yy) );
			points.pb( mp(-xx, yy) );
			points.pb( mp(-xx, -yy) );
		}

		vector<double> cost;
		REP(i, SZ(points)) {
			double d = dist(x, y, points[i].first, points[i].second);
			cost.push_back(d);
		}
		int ans = 0;
		FOR(i, 1, SZ(cost)-1) if ( cost[i] <= D + eps ) {
			double x1 = points[i].first;
			double y1 = points[i].second;
			++ans;
			FOR(j, 1, SZ(cost)-1) if (i != j && cost[j] < cost[i]) {
				double x2 = points[j].first;
				double y2 = points[j].second;
				if ( (x1-x)*(y2-y) == (x2-x)*(y1-y) ) {
					--ans;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
