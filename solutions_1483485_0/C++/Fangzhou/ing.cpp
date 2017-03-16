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

int main() {
	ifstream in("A-small-attempt0.in");
	freopen("output.out", "w", stdout);
	char f[] = {'y', ' ', 'e', 's', 'o', 'c',
				'v', 'x', 'd', 'u', 'i', 'g',
				'l', 'b', 'k', 'r', 'z', 't',
				'n', 'w', 'j', 'p', 'f', 'm',
				'a', ' '};

	int t;
	in >> t; getline(in, string());
	string s[30];
	REP(i, t) {
		getline(in, s[i]);
	}
	int b = 0;
	int z = 0;
	REP(i, t) {
		REP(j, SZ(s[i])) {
			if ( s[i][j] == 'b' ) {
				++b;
			}
			if ( s[i][j] == 'z' ) {
				++z;
			}
		}
	}
	if ( b > z ) {
		f[1] = 'h';
		f[25] = 'q';
	}
	else {
		f[1] = 'q';
		f[25] = 'h';
	}

	REP(i, t) {
		printf("Case #%d: ", i+1);
		REP(j, SZ(s[i])) {
			if ( s[i][j] == ' ' ) printf(" ");
			else printf("%c", f[ s[i][j]-'a' ]);
		}
		cout << endl;
	}
	return 0;
}
