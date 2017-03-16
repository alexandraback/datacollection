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

int main()
{
	int z;
	cin >> z;
	for (int t = 1; t <= z; t++)
	{
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << "Case #" << t << ":" << endl;

		map<int, int> m;
		bool found = false;
		for (int s = 1; s < 1<<n; s++)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (s & (1 << i))
					sum += arr[i];
			}
			map<int, int>::iterator it = m.find(sum);
			if (it != m.end())
			{
				found = true;
				for (int i = 0; i < n; i++)
				{
					if (s & (1 << i))
						cout << arr[i] << " ";
				}
				cout << endl;
				for (int i = 0; i < n; i++)
				{
					if (it->second & (1 << i))
						cout << arr[i] << " ";
				}
				cout << endl;

				break;
			}
			else
				m[sum] = s;
		}
		if (!found)
			cout << "Impossible" << endl;
	}
}
