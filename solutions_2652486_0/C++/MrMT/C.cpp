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

int r, n, m, k;
int v[10];
int nums[200];

vector<vector<int> > pos;
void bt(int i, vector<int> &aux) {

	if(i >= n) {
		pos.push_back(aux);
		return;
	}

	for(int j=2 ; j<= m ; j++) {
		aux.push_back(j);
		bt(i+1, aux);
		aux.pop_back();
	}
	return;
}

void calc_nums(int i) {
	for(int mask=0 ; mask<(1<<n) ; mask++) {
		int val = 1;
		for(int j=0 ; j<n ; j++) if( mask&(1<<j) )
			val *= pos[i][j];
		nums[val] = 1;
	}
}

int main () {
	int casos;
	cin >> casos;
	cin >> r >> n >> m >> k;
	cout << "Case #" << 1 << ":"<< endl;

	forn(t, 0, r) {
		forn(i, 0, k) cin >> v[i];

		pos.clear();
		vector<int> aux;
		bt(0, aux);
		
		vector<int> valen(0);
		int ran = 0;

		for(int i=0 ; i<pos.size() ; i++) {
			memset(nums, 0, sizeof(nums));
			calc_nums(i);

			bool valid = true;
			for(int j = 0 ; j < k ; j++) valid = valid && nums[v[j]];
			if(valid) valen.push_back(i);

			ran = ((ran + 11 ) * i) % 13;
		}

		int ret = valen[ran%valen.size()];
		forn(j, 0, n) cout<< pos[ret][j];
		cout << endl;
	}

	return 0;
}



