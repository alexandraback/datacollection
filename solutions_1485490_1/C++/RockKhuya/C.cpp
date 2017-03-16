#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
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
#include <vector>
#include <stdint.h>

using namespace std;
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define LL long long
#define zero(a) fabs(a)<1e-9
#define resz(a,n) a.clear(),a.resize(n)
#define same(a,n) memset(a,n,sizeof(a))
#define make(a,b) make_pair(a,b)
#define rep(i,a) for(int i=1;i<=a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

uint64_t qmax(uint64_t x, uint64_t y) {
	if (x>y) return x;
	else return y;
}
uint64_t qmin(uint64_t x, uint64_t y ) {
	if (x>y) return y;
	else return x;
}
int main() {
	int test_num, test_id;
	int N, M;
	uint64_t a[101], b[101];
	uint64_t A[101], B[101];
	uint64_t Q[101][101], max1, tong1, tong2;

	ifstream ifs("C-large.in");
	ofstream ofs("C-large.out");
	ifs >> test_num;
	same(a,0);
	same(b,0);
	same(A,0);
	same(B,0);
	for(test_id = 1; test_id <= test_num; ++test_id) {
		// input
		ifs >> N >> M;
		rep(i, N) {
			ifs >> a[i] >> A[i];
		}
		rep(i,M) {
			ifs >> b[i] >> B[i];
		}
		// processing
		same(Q,0);
		rep(x,N) {
			rep(y,M) {
				if (A[x] != B[y]) {
					Q[x][y] = qmax(Q[x-1][y], Q[x][y-1]);
				}
				else { // A[x]==B[y]
					tong1 = 0;
					max1 = 0;
					for(int i = x; i>0; --i) {
						if (A[i]==A[x]) tong1+=a[i];
						tong2 = 0;
						for(int j = y; j>0; --j) {
							if (B[j]==B[y]) tong2+=b[j];
							max1 = qmax(max1, Q[i-1][j-1]+qmin(tong1,tong2));
						}
					}
					Q[x][y] = max1;
				}
			}
		}
		// ouput
		uint64_t ans = 0;
		rep(i,N){
			rep(j,M) {
				ans = qmax(ans, Q[i][j]);
				cout << Q[i][j] << " ";
			}
			cout << endl;
		}
		ofs << "Case #" << test_id << ": " << ans << endl;

	}
	return 0;
}
