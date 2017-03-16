//#define PROB "test"           /* Comment to use standard I/O everywhere    */
//#define STDIO               /* Uncomment to use standard I/O on local PC */

//{{{ Preamble
#if !defined(LOCAL_PC) && !defined(NDEBUG)
#define NDEBUG
#endif
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;typedef long long ll;typedef unsigned long long ull;static
struct _{ios_base::Init i;_(){cin.sync_with_stdio(false);cin.tie(NULL);}}_;
const double pi=3.14159265358979323846;const double E=2.7182818284590452354;
#if defined(PROB) && (!defined(LOCAL_PC) || !defined(STDIO))
static struct __{__(){cin.rdbuf(a.open(PROB".in",ios::in));cout.rdbuf(b.open(
PROB".out",ios::out));}~__(){cin.rdbuf(NULL);cout.rdbuf(NULL);}filebuf a,b;}__;
#endif
#define _O    static inline ostream&operator<<(ostream&o,
#define _W(f) o<<"[ ";while(!s.empty()){o<<s.f()<<" ";s.pop();}return o<<"]";
template<class T>struct _f{typedef typename T::iterator t;};template<class T>
struct _f<const T>{typedef typename T::const_iterator t;};template<class T>_O
stack<T>s){_W(top)}template<class T>_O queue<T>s){_W(front)}namespace std{
template<class A,class B>_O const pair<A,B>&p){return o<<p.first<<"="<<p.second
;}}template<class T>static inline ostream&_o(ostream&o,const T&c){o<<"[ ";copy(
c.begin(),c.end(),ostream_iterator<typename T::value_type>(o," "));return o<<
"]";}template<class T,class A,template<class T,class A>class C>_O const C<T,A>&
c){return _o(o,c);}template<class T>_O const set<T>&s){return _o(o,s);}template
<class K,class V>_O const map<K,V>&m){return _o(o,m);}template<class T,size_t M
,size_t N>_O const T(&a)[M][N]){for(size_t j=0;j<M;j++){o<<"\n"<<string(14,' ')
<<"\t";for(size_t i=0;i<N;i++)o<<a[j][i]<<" ";}return o;}static inline ostream&
endl(ostream&os){return os<<"\n";}
#if defined(_MSC_VER) && _MSC_VER >= 1600
#  define __typeof__ decltype
#endif
#define FOREACH(i,c) for(_f<__typeof__(c)>::t i=c.begin();i!=c.end();++i)
#define pb           push_back
#define mp           make_pair
#ifdef LOCAL_PC
#define BLOG cerr<<std::right<<setw(9)<<__FUNCTION__<<" "<<setw(3)<<__LINE__<<":"
#define DOLOG(x) <<std::left<<"\t"<<#x<<" = "<<(x)
#define ELOG     <<std::endl
#else
#define BLOG     0
#define DOLOG(x)
#define ELOG
#endif
#define LOG(x)      static_cast<void>(BLOG DOLOG(x) ELOG)
#define LOG2(x,y)   static_cast<void>(BLOG DOLOG(x) DOLOG(y) ELOG)
#define LOG3(x,y,z) static_cast<void>(BLOG DOLOG(x) DOLOG(y) DOLOG(z) ELOG)
//}}}

int h, n, m;

int cache[100][100][10000];
bool seen[100][100][10000];

int fl[100][100], ce[100][100];

const int inf = 400000000;

int dfs(int x, int y, int water)
{
	if (x == m-1 && y == n-1)
		return 0;
	if (water < 0)
		water = 0;
	if (seen[x][y][water])
		return cache[x][y][water];
	seen[x][y][water] = true;
	cache[x][y][water] = inf;

	int res = inf;

	const int d[][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
	for (int q = 0; q < 4; q++)
	{
		int x2 = x+d[q][0], y2 = y+d[q][1];
		if (x2 < 0 || m <= x2 || y2 < 0 || n <= y2)
			continue;
		if (fl[y][x] > ce[y2][x2]-50 || fl[y2][x2] > ce[y2][x2]-50)
			continue;
		if (fl[y2][x2] > ce[y][x]-50)
			continue;

		if (water == h && water <= ce[y2][x2]-50)
			res = min(res, dfs(x2, y2, water));
		int drop = max(0, water - (ce[y2][x2]-50));
		int move_time = (water-drop >= fl[y][x]+20) ? 10 : 100;
		res = min(res, drop + move_time + dfs(x2, y2, water-drop-move_time));
	}

	cache[x][y][water] = res;
	return res;
}

int main()
{
	int z;
	cin >> z;
	for (int t = 1; t <= z; t++)
	{
		memset(seen, 0, sizeof(seen));
		cin >> h >> n >> m;
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
				cin >> ce[j][i];
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
				cin >> fl[j][i];
		}

		int ans = dfs(0, 0, h);
		cout << "Case #" << t << ": " << ans/10 << "." << ans%10 << endl;
	}
}
