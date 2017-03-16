#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <forward_list>
#include <stack>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <utility>
#include <sstream>

using namespace std;
typedef unsigned long long int ulint;
typedef long long int lint;
typedef pair<int,int> pi;
typedef pair<lint,lint> pl;
typedef vector<int> vi;
struct dbg_ {
	template<typename T> dbg_ & operator ,(const T & x) {
		cout << x << ' ';
		return *this;
	}
} dbg_t;

#define EPS 0.0000001
#define REP(i,a,b) for(int i=a;i<b;i++)
#define PER(i,a,b) for(int i=a;i>b;i--)
#define REPi(type,cont,a) for (type<int>::iterator a = cont.begin(); a!=cont.end(); ++a)
#define REPs(cont,a) for (set<int>::iterator a = cont.begin(); a!=cont.end(); ++a)
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define MIN(X, Y)  ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y)  ((X) > (Y) ? (X) : (Y))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define MP make_pair
#define PB push_back
#define ALL(a) a.begin(), a.end()
#define HAS(a,b) (a.find(b) != a.end())
#define x first
#define y second
#ifdef SLONICHOBOT
	#undef dbg
	#undef tu
	#define tu cout << "#line: " << __LINE__ << endl
	#define dbg(args ...) { cout << "|" << __LINE__ << "| "; dbg_t,args;cout << endl; }
	#define dbgg(X) cerr << #X ": " << X << endl
#else
	#define tu
	#define dbg
	#define dbgg
#endif

void solve() {
	int J; cin >> J;
	int P; cin >> P;
	int S; cin >> S;
	int K; cin >> K;
	map<pair<int,int>,int> did1;
	map<pair<int,int>,int> did2;
	map<pair<int,int>,int> did3;
	vector<pair<int,pair<int,int>>> ret;
	REP(i,0,J) {
		REP(j,0,P) {
			REP(k,0,S) {
				if (did1[{i,j}] >= K) continue;
				if (did2[{k,j}] >= K) continue;
				if (did3[{i,k}] >= K) continue;
				did1[{i,j}]++;
				did2[{k,j}]++;
				did3[{i,k}]++;
				ret.PB({i+1,{j+1,k+1}});
			}
		}
	}
	cout << ret.size() << endl;
	for(auto i : ret) {
		cout << i.first << " " << i.second.first << " " << i.second.second << endl;
	}
}

int main()
{
	int T; cin >> T;
	REP(i,0,T) {
		cout << "Case #" << (i+1) << ": ";
		solve();
	}

	return 0;
}
