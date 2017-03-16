#include <algorithm> //sort,lower_bound,next_permutation
#include <bitset>	 //sieve of Eratosthenes
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>	 //math routines: abs,pow...
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>   //char routines: isalpha...
#include <deque>
#include <fcntl.h>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>	 //io routines
#include <iterator>
#include <limits>
#include <list>
#include <map>		 //balanced BST (RB Tree) for key-val pairs
#include <memory.h>
#include <memory>
#include <numeric>
#include <queue>	 //queue & priority_queue
#include <set>		 //balanced BST (RB Tree) with key only
#include <sstream>
#include <stack>
#include <string>    //C++ class string
#include <unistd.h>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <utility>
#include <vector>	 //resizable array

using namespace std;
typedef long long 			LL;  //<=10^18
typedef unsigned long long 	ULL; //<=10^19
typedef long double 		LD;

typedef pair<int,int> 		PII; //(x,y)
typedef pair<double,double> PDD;
typedef pair<int,double> 	PID;
typedef pair<LL,LL> 		PLL;
typedef pair<int,PII> 		TRI; //(x,y,z)

typedef set<int>			SI;

typedef vector<bool>        VB;	 //[T,F]
typedef vector<int> 		VI;
typedef vector<LL> 			VL;
typedef vector<string> 		VS;
typedef vector<PII> 		VII; //[(x,y)]
typedef vector<PID> 		VID;
typedef vector<PLL> 		VLL;
typedef vector<TRI> 		VT;
typedef vector<VI> 			VVI;
typedef vector<VL> 			VVL;
typedef vector<VII> 		VVII;
typedef vector<VLL> 		VVLL;
typedef vector<VT> 			VVT;

typedef map<int, int>		MII; //{x:y}
typedef map<string, int>	MSI; //{"x":y}

typedef complex<double> 	PT;
typedef complex<LL> 		PTI;
const long double PI = acos(-1);
const int ui[4]={1, 0, -1, 0};
const int uj[4]={0, 1, 0, -1};
const int dx[8]={1, 1, 0, -1, -1, -1,  0,  1};
const int dy[8]={0, 1, 1,  1,  0, -1, -1, -1};
const int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int leap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

#define INF 2147483647 // 2^31-1
#define NINF -INF
#define oo  0x3F3F3F3F
#define EPS (1E-9)
#define MEMSET_INF 127     // ~2B
#define MEMSET_HALF_INF 63 // ~1B
// init shortest path distances, set INF = 127
//memset(dist, MEMSET_INF, sizeof dist);
// init DP memoization table
//memset(dp_memo, -1, sizeof dp_memo);
// clear array of ints
//memset(arr, 0, sizeof arr);

#define ISSETBIT(bmask,i) ((bmask&(1<<i))!=0)
#define SETBIT(bmask,i)   (bmask|=(1<<i))
#define UNSETBIT(bmask,i) (bmask&=~(1<<i))
#define NEGMOD(x,mod)     ((x+mod)%mod)

#define FILL(arr,val) memset((arr),(val),sizeof(arr))
#define CLR(a)        memset((a),0,sizeof(a))
#define CPY(dest,src) memcpy((dest),(src),sizeof(dest))

#define FOR(i,a,b)   for(int(i)=int(a);(i)<int(b);(i)++)
#define FOREQ(i,a,b) for(int(i)=int(a);(i)<=int(b);(i)++)
#define RFOR(i,a,b)  for(int(i)=(a),_b(b);(i)>=_b;--(i))
#define FORS(i,a,b,s) for(int(i)=int(a);(i)<int(b);(i)+=s)
#define RFORS(i,a,b,s) for(int(i)=(a),_b(b);(i)>=_b;(i)-=s)
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define FOREACHN(c,itr,i,n) \
	for(__typeof((c).begin()) itr=(c).begin(),int(i)=0;itr!=(c).end()&&(i)<int(n);itr++,(i)++)
#define RFOREACH(c,itr) for(__typeof((c).rbegin()) itr=(c).rbegin();itr!=(c).rend();itr++)

#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)(a).size())
#define UNIQ(a)  sort(all(a)); (a).erase(unique(all(a)),(a).end())
#define IDX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())

#define PRESENT(c,x)  ((c).find(x) != (c).end())    /** set/map */
#define CPRESENT(c,x) (find(all(c),x) != (c).end())

#define ABS(x)   ((x)<0?-(x):(x))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN3(a,b,c) (MIN(a,MIN(b,c)))
#define MAX3(a,b,c) (MAX(a,MAX(b,c)))
#define SQR(a)   ((a)*(a))
#define SUM(a)   accumulate(all(a),string())

#define fst first
#define snd second
#define pb  push_back
#define mp  make_pair
#define tri(a,b,c) mp(a,mp(b,c))

/** debugger */
struct debugger
{
 template<typename T> debugger& operator,(const T& v)
 {
  cerr<<v<<" ";
  return *this;
 }
} dbg;
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#define debug(args...) {dbg,args; cerr<<endl;}
#define DLINE cerr<<endl
#define DPRINT(format,args...) if(is_debug){printf(format,##args);}
#define ASSERT(x,var) \
	if (!(x)) \
	{ \
		cout << "ERROR!! Assert " << #x << " failed" << endl \
			 << " value = " << var << endl \
			 << " on line " << __LINE__  << endl \
			 << " in file " << __FILE__ << endl;  \
		exit(1); \
	}
#ifdef DEBUG
	#define cvar(x) cerr << "<" << #x << ": " << x << ">"
	#define evar(x) cvar (x) << endl
	template<class T> void DISP(const char *s, T x, int n) {
		cerr << "[" << s << ": ";
		FOR(i,0,n) cerr << x[i] << " ";
		cerr << "]" << endl;}
	#define disp(x,n) DISP(#x " to " #n, x, n)
#else
	#define cvar(...) ({})
	#define evar(...) ({})
	#define disp(...) ({})
#endif
#ifndef ONLINE_JUDGE
	inline void compare(int test_number, stringstream& input,
	 stringstream& output, stringstream& solution)
	{
		if (solution.str() != output.str())
		{
			cout << "Test #" << test_number << ": " << input.str() << endl
				 << "    Expected: #" << solution.str() << "#" << endl
				 << "    Received: #" << output.str() << "#" << endl;
		}
	}
#endif

#define REDIRECT_INPUT	freopen("input.txt", "r", stdin)
// Math //
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}

// iterative
template<typename T> inline T gcd(T x, T y) {for (T t; x; t=x, x=y%x, y=t); return y;}
inline LL gcd_iter(int a, int b) {
	LL cnt;int t;
	while (b!=0) {cnt+=a/b;t=b;b=a%b;a=t;}
	return cnt;
}
inline LL gcd_fast(int a, int b) {
	LL cnt;
    for(;;){
		cnt+=MAX(a,b)/MIN(a,b);
		if ((a%=b)==0) return b;
        if ((b%=a)==0) return a;
    }
	return cnt;
}

template<typename T> inline T lcm(T x, T y) {return x==0&&y==0?0:ABS(x*y/gcd(x,y));}

// returns (b^e)%m
template<typename T> inline T pow(T b, T e, T m) {
	T t=1; for(;e;e>>=1,b*=b%m) e&1?t*=b%m:0; return t;
}
template<typename T> inline bool is_prime(T m) {
	T u=sqrt(m); for(T i=2; i<=u+1; i++) {if(m%i==0) return false;}
	return true;}
inline bool is_equal(double v1, double v2) {return ABS(v1-v2)<EPS;}
inline bool is_less(double v1, double v2)  {return v1-v2<=EPS;}
template <class T> inline T num_digits(T num)
{
    int digits = 0;
    if (num < 0) digits = 1; // remove if '-' counts as a digit
    while (num) { num/=10; digits++; }
    return digits;
}

// Containers //
template<class T> inline bool pair_compare(const T &x, const T &y)
{ return x.snd < y.snd; }
template<class T> inline typename T::const_iterator map_max_element(const T &A)
{
    typedef typename T::value_type pair_type;
    return max_element(ALL(A), pair_compare<typename T::value_type>);
}
template<class T> inline typename T::const_iterator map_min_element(const T &A)
{
    typedef typename T::value_type pair_type;
    return min_element(ALL(A), pair_compare<typename T::value_type>);
}
// map<T1,T2>::const_iterator it = map_max_element(<map>);
template<template <typename> class P = std::less >
struct compare_pair_second {
    template<class T1, class T2> bool operator()
		(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right)
	{ return P<T2>()(left.snd, right.snd); }
};
template<typename A, typename B> inline pair<B,A> flip_pair(const pair<A,B> &p)
{ return pair<B,A>(p.snd, p.fst); }
template<typename A, typename B> inline map<B,A> flip_map(const map<A,B> &src)
{
    map<B,A> dst;
    transform(ALL(src), inserter(dst, dst.begin()), flip_pair<A,B>);
    return dst;
}
typedef pair<string, int> mypair;
struct int_cmp {
    bool operator()(const mypair &lhs, const mypair &rhs)
	{ return lhs.snd < rhs.snd; }
};
// demo
inline void print10(const map<string,int> &mymap) {
    vector<mypair> myvec(mymap.begin(), mymap.end());
    assert(myvec.size() >= 10);
    partial_sort(myvec.begin(), myvec.begin() + 10, myvec.end(), int_cmp());
    for (int i = 0; i < 10; ++i) {
        cout << i << ": " << myvec[i].first 
            << "-> " << myvec[i].second << "\n";
    }
}

// Graph //
template<class edge> struct Graph
{
	vector<vector<edge> > adj;
	Graph(int n) {adj.clear (); adj.resize (n + 5);}
	Graph() {adj.clear (); }
	void resize(int n) {adj.resize (n + 5); }
	void add(int s, edge e){adj[s].push_back (e);}
	void del(int s, edge e) {adj[s].erase (find (iter (adj[s]), e)); }
	vector<edge>& operator [](int t) {return adj[t];}
};

// Geometry //
// atan2(): principal value of arctan of y/x in rad
struct Point {int x,y;};
inline bool operator<(Point a,Point b) {return (a.x==b.x)?(a.y<b.y):(a.x<b.x);}

struct point { double x, y; };
point operator-(point a, point b) { point p = {a.x-b.x, a.y-b.y}; return p; }
class angle_sort
{
    point m_origin, m_dreference;
    static double xp(point a, point b) { return a.x * b.y - a.y * b.x; }
public:
    angle_sort(const point origin, const point reference):m_origin(origin),m_dreference(reference - origin) {}
    bool operator()(const point a, const point b) const
    {
        const point da = a - m_origin, db = b - m_origin;
        const double detb = xp(m_dreference, db);
        if (detb == 0) return false;
        const double deta = xp(m_dreference, da);
        if (deta == 0) return true;
        if (deta * detb > 0) {
            // both on same side of reference, compare to each other
            return xp(da, db) > 0;
        }
        return deta > 0;
    }
};
/** USAGE
	point po = { 1.5, 2.5 };
	point p0 = { -3.5, -2 };
	const angle_sort cmp(po, p0);
	cout << "po < p0: " << cmp(po, p0) << endl;
*/
inline void ro_vector(const vector<int>& v) {}
inline void rw_vector(vector<int>& v) { /*v[0]++;*/ }
template<class T> inline void proc_digits(T num) {
	do {
		int digit = num%10;
		// ... process ...
		num/=10;
	} while (num>0);
}
struct triplet {
	int x,y; LL z;
	triplet(int _x,int _y,LL _z) : x(_x),y(_y),z(_z) {}
};

static int T,N,X,Y;
int choose[30005][35];

int main()
{
	srand(unsigned(time(NULL)));
	ios_base::sync_with_stdio(false);
	for(int i = 0; i<=30000; ++i)
	{
		if (i > 30) continue;
		choose[i][0] = choose[i][i] = 1;
	}
	for(int i = 1; i<=30000; ++i)
		for(int j = 1; j < i; ++j)
		{
			if (j > 30) continue;
			choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
		}

	scanf("%d", &T);
	FOREQ(t,1,T)
	{
		scanf("%d%d%d", &N,&X,&Y);
		X = ABS(X);
		if (X == 0 && Y == 0)
		{
			printf("Case #%d: %f\n", t, 1.0);
			continue;
		}
		int lim_s = (X+Y-1)*(X+Y)/2 + Y;
		int lim_l = (X+Y-1)*(X+Y)/2 + X + 2*Y + 1;
		if (X > 0)
		{
			if (N <= lim_s)
			{
				printf("Case #%d: %f\n", t, 0.0);
				continue;
			}
			else if (N >= lim_l)
			{
				printf("Case #%d: %f\n", t, 1.0);
				continue;
			}
			else
			{
				int K = N - lim_s;
				if (K>=30)
				{
					printf("Case #%d: %f\n", t, 0.0);
					continue;
				}
				else
				{
					int c = 0;
					FOREQ(i,1,K)
					{	
						if ((K+Y)>30000||(Y+i)>30) continue;
						c+=choose[(K+Y)][Y+i];
					}		
//					printf("%d C %d ", (K+Y), (Y+1));
					double ans = pow(0.5,(K+Y)) * (double)c;
					printf("Case #%d: %f\n", t, ans);
					continue;
				}
			}
		}
		else
		{
			if (N >= lim_l)
			{
				printf("Case #%d: %f\n", t, 1.0);
				continue;
			}
			else
			{
				printf("Case #%d: %f\n", t, 0.0);
				continue;
			}
		}
	}
	return 0;
}
