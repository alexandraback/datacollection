#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, a, b) for(int i=(a);i<int(b);i++)
#define PB push_back
#define MP(X,Y) make_pair(X,Y)
#define SZ(X) ((int)(X.size()))
#define ALL(x)   (x).begin(),(x).end()
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
#define F first
#define S second
#define CLEAR(A, V) memset(A, V, sizeof(A))

typedef  long long   ll;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef pair<ll,ll> LL;
typedef vector<II> VII;

typedef pair<int,LL> PIL;

template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline T gcd(T a, T b){ return b?gcd(b, a%b):a;}
const double EPS = 1e-9;
const double PI = acos(-1.0);

map<PIL, ll> mem;

int n, m;
ll as[102], bs[102];
int tipoa[102], tipob[102];

ll doit(int i, int j, ll ca, ll cb) {

	if(i == n || j == m) return 0;
	PIL stat = PIL(i*1000 + j, LL(ca, cb));

	map<PIL, ll>::iterator r = mem.find(stat);
	if( r != mem.end()) return r->S;

	ll ret = 0;

	if(tipoa[i] != tipob[j]) {
		ret = max(doit(i, j+1, ca, bs[j+1]), doit(i+1, j, as[i+1], cb));
	} else {
		if(ca == cb) {
			ret = doit(i+1, j+1, as[i+1], bs[j+1]) + ca;
		} else if(ca < cb) {
			ret = doit(i+1, j, as[i+1], cb-ca) + ca;
		} else {
			ret = doit(i, j+1, ca-cb, bs[j+1]) + cb;
		}
	}

	mem[stat] = ret;
	return ret;
}


int main(void) {

	int casos;
	cin >> casos;
	forn(t, 0, casos) {
		mem.clear();
		cin >> n >> m;
		forn(i, 0, n) cin >> as[i] >> tipoa[i];
		forn(i, 0, m) cin >> bs[i] >> tipob[i];

		cout << "Case #" << t+1 << ": " << doit(0, 0, as[0], bs[0]) << endl;
	}
	return 0;
}
