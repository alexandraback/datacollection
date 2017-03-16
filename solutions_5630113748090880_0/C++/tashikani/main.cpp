#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef tuple<int, int, int> TIII;
typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define MT make_tuple
#define SZ(a) int((a).size())
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()

const double EPS = 1e-10;
const double PI  = acos(-1.0);

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	FOR(test, 1, T + 1){
		cout << "Case #" << test << ": ";

		int N;
		cin >> N;
		map<int, int> m;

		REP(i, 2 * N - 1){
			REP(j, N){
				int a;
				cin >> a;
				m[a]++;
			}
		}

		VI ret;
		EACH(a, m){
			if(a.second % 2 == 1){
				ret.push_back(a.first);
			}
		}

		SORT(ret);

		EACH(r, ret) cout << r << " ";

		cout << endl;
	}


	return 0;
}
