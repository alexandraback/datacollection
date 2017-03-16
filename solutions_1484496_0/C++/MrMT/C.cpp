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

int nums[21];
int mem[1<<20];

int main(void) {

	int casos;
	cin >> casos;
	forn(t, 0, casos) {
	
		int n;
		cin >> n;
		forn(i, 0, n) cin >> nums[i];

		for(int i=0 ; i<1<<n ; i++) {
			mem[i] = 0;
			forn(j, 0, n) if(i&(1<<j))mem[i] += nums[j];
		}

		printf("Case #%d:\n", t+1);
		bool found = false;
		for(int mask=1 ; mask<1<<n && !found; mask++) {
			int nmask = ((1<<n)-1)^mask;
			for(int m=nmask ; m>0 && !found; m = (m-1) & nmask ) {
				if(mem[mask] == mem[m]) {
					forn(j, 0, n) if(mask&(1<<j)) printf("%d ", nums[j]);
					printf("\n");
					forn(j, 0, n) if(m&(1<<j)) printf("%d ", nums[j]);
					printf("\n");

					found = true;
				}
			}
		
		}

		if(!found) cout << "Impossible" << endl;
	}

	return 0;
}
