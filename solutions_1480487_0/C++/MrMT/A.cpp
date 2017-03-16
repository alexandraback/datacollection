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

int n;
vector<int> s[102];
double ret[102];

int main(void) {

	int casos = 0;
	cin >> casos;
	forn(t, 1, casos + 1) {

		forn(i, 0, 102) s[i].clear();
		forn(i, 0, 102) ret[i] = -10.;

		cin >> n;
		int X = 0, x;
		forn(i, 0, n) {
			cin >> x;
			X += x;
			s[x].PB(i);
		}

		for(int i=100 ; i>=0 ; i--) if(SZ(s[i]) > 0){
			
			int sum = 0, cnt = 0;
			forn(j, 0, i) {
				sum += j*SZ(s[j]), cnt += SZ(s[j]);
			}

//			cout << i << " " << sum << " " << cnt << endl;

			double cada = ((double)sum + X) / ((double)cnt);
			if(sum + X <= i*cnt) ret[i] = 0.;
			else break;
		}

		int sum = 0, cnt = 0;
		forn(i, 0, 101) if(ret[i] < -1.) {
			sum += i*SZ(s[i]);
			cnt += SZ(s[i]);
		}
		double cada = ((double)X+sum) / ((double)cnt);
		forn(i, 0, 101) if(ret[i] < -1.) {
			ret[i] = ((double)cada - i) / X;
		}
		
		vector<double> sol(n, 0.);
		forn(i, 0, 101) forn(j, 0, SZ(s[i])) {
			sol[s[i][j]] = ret[i];
		}
		
		printf("Case #%d:", t);
		forn(i, 0, n) printf(" %.6lf", sol[i]*100.);
		printf("\n");

	}
	return 0;
}
