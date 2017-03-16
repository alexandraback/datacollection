#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;
typedef vector<string> VS;

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(),x.end()
#define CLR(x, v) memset((x),v,sizeof (x))
#define gcd(a, b) __gcd(a, b)
#define PB push_back 
#define MP make_pair
#define INF 0x3f3f3f3f

int toInt(string s){ istringstream sin(s); int t; sin>>t; return t; }
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str(); }
template<class T> inline std::ostream& operator<<(ostream& os, const vector<T>& v) { FORE(it,v) os << *it << " "; return os; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

//#define DEBUG
#ifdef DEBUG
#define ASSERT(x) assert(x)
#else
#define ASSERT(x)
#endif

// -
int r,n,m,k;
int a[110];

// -

// input
void init()
{
	cin>>r>>n>>m>>k;
}

bool check(int x)
{
	int d[3];
	d[0]=x/100;
	d[1]=x%100/10;
	d[2]=x%10;
	int i;
	FOR(i,0,3) if(d[i]<2||d[i]>5) return false;
	set<int> st;
	st.insert(1);
	st.insert(d[0]);
	st.insert(d[1]);
	st.insert(d[2]);
	st.insert(d[0]*d[1]);
	st.insert(d[1]*d[2]);
	st.insert(d[0]*d[2]);
	st.insert(d[0]*d[1]*d[2]);
	FOR(i,0,k) if(st.find(a[i])==st.end()) break;
	if(i<k) return false;
	return true;
}

void solve()
{
	init();
	int i;
	cout << endl;
	while(r--) {
		FOR(i,0,k) {
			cin>>a[i];
		}
		VI v;
		FOR(i,222,1000) if(check(i))
			v.PB(i);
		random_shuffle(ALL(v));
		if(v.size())
			cout<<v[0]<<endl;
		else cout<<"222"<<endl;
	}
}

int main()
{
	int T;
	cin>>T;
	for(int cs = 1; cs <= T; cs++) {
		cout << "Case #" << cs << ": ";
		clock_t start, finish;
		start = clock();   
		solve();
		finish = clock();   
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;  
#ifdef DEBUG 
		cout << "Running time: " << duration << endl;
#endif
	}
	return 0;
}
