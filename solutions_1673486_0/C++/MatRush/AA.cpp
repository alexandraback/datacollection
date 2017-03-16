#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INF = 0X3F3F3F3F;
const double PI = acos(-1.0); //3.1415926535897932384626433832795;
const double EPS = 1e-11;
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1}; //4 direction

#define PB push_back
#define MP make_pair
#define SZ size()
#define V vector
#define A first
#define B second
#define FOR(i,s,e) for(int i=(s);i<=(int)(e);++i)
#define FORD(i,s,e) for(int i=(s);i>=(int)(e);--i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define rep(i,s,e) for(int i=(s);i<(int)(e);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define FIT(it,x) for(typeof((x).begin()) it = (x).begin();it != (x).end();it++)
#define FITD(it,x) for(typeof((x).rbegin()) it = (x).rbegin();it != (x).rend();it++)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x),0,sizeof(x))
#define MEM(a,b) memset((a),b,sizeof(a));
#define EXIST(a,b) (find(all(a),b)!=a.end())
#define DEBUG(x) cerr << #x << ":" << x << '@' << endl
#define PRV(v) REP(vi,v.size()) cout << v[vi] << ' ';cout << endl

inline int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
inline string tolower(string s){ REP(i,s.SZ) s[i] = tolower(s[i]); return s; }
inline string toupper(string s){ REP(i,s.SZ) s[i] = toupper(s[i]); return s; }
template<class T> inline T sqr(const T& x) { return x * x; }
template<class T> inline int toint(const T& x){ stringstream ss; ss << x; int r; ss >> r; return r; } 
template<class T> inline int todouble(const T& x){ stringstream ss; ss << x; double r; ss >> r; return r; } 
template<class T> inline string tostr(const T& x) { ostringstream os(""); os << x; return os.str(); }
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}//NOTES:stov(
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

typedef long long LL;
typedef double DB;
typedef stringstream SS;
typedef set< int > SI;
typedef pair< int, int > PII;
typedef vector< int > VI;
typedef vector< VI > VVI;
typedef vector< string > VS;
typedef map< string, int > MSI;
typedef map< int, int > MII;

const int MAXN = 111111;

double pro[MAXN], e[MAXN];
double prod[MAXN], nprod[MAXN];

//double dp[MAXN][MAXN];
//double dp2[MAXN][2];//有无错

int main() {
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	int T, cas = 0, n, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		prod[0] = 1;
		rep (i, 1, a + 1) {
			scanf("%lf", &pro[i]);
			prod[i] = prod[i - 1] * pro[i];
			nprod[i] = nprod[i - 1] * (1 - pro[i]);
		}
		//memset(dp, 0, sizeof(dp));
		/*dp[0][0] = 1.0;
		rep (i, 0, a) {
			rep (j, 0, i + 1) {
				dp[i + 1][j + 1] += dp[i][j] * (1 - pro[i + 1]);
				dp[i + 1][j] += dp[i][j] * pro[i + 1];
			}
		}
		dp2[0][0] = 1.0;*/
		/*int x, y;
		while (cin >> x >> y)
			cout << dp[x][y] << endl;*/
		double ans = 1e10;
		double sum = 0;
		rep (i, 0, a + 1) {
			double tmp = a - i;
			//dp2[i + 1][1] = dp2[i][1] + dp2[i][0] * (1 - pro[i + 1]);
			//dp2[i + 1][0] = dp2[i][0] * pro[i + 1];
			//dp2[i + 1][1] = dp2[i][1] * (b - (i + 1) + b + 2) + dp2[i][0] * pro[i + 1] * (1 - pro[i + 1]);
			if (i) sum = (1 - prod[i]) * (b - i + b + 2);
			//if (i) tdp = tdp + dp[i][i];
			/*rep (j, 1, i + 1) {//先enter 再打完
				tmp += dp[i][j] * (b - i + b + 2);
				//dp[i - 1][j] * (b - i  + b + 3);
				//cout << ' ' << dp[i][j] * (b - i + b + 2);
			}*/
			tmp += sum + prod[i] * (b - i + 1);
			//tmp += dp[i][0] * (b - i + 1);
			//cout << ' ' << tmp << '@' << sum << endl;
			ans = min(ans, tmp);
		}
		ans = min(ans, 1.0 * (2 + b));
		printf("Case #%d: %.6lf\n", ++cas, ans);
	}
}
