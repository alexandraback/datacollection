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
typedef vector<II> VII;

template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline T gcd(T a, T b){ return b?gcd(b, a%b):a;}
const double EPS = 1e-9;
const double PI = acos(-1.0);

inline bool pal(ll n){

	string s = "";
	while(n) {
		s += ('0'+n%10);
		n /= 10;
	}
	int len = s.size();
	for(int i=0 ; i<len/2 ; i++) if(s[i] != s[len-i-1]) return false;

	return true;
}

int main () {

	int casos;
	cin >> casos;

	forn(t, 0, casos) {
		ll A, B;
		cin >> A >> B;

		ll ret = 0;
		for(ll i = 1 ; i*i<=B ; i++) {
			ll n = i*i;
			if(A<= n and n<=B) {
				ret += pal(i) && pal(n);
			}
		}
	
		cout << "Case #" << t+1 << ": "	<< ret << endl;
	}
	return 0;
}
