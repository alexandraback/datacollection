#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iterator>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MM(a,x) memset(a, x, sizeof(a))
#define P(x) cout<<#x<<" = "<<x<<endl;
#define P2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define PV(a,n) for(int i=0;i<n;i++) cout<<#a<<"[" << i <<"] = "<<a[i]<<endl;
#define TM(a,b) cout<<#a<<"->"<<#b<<": "<<1.*(b-a)/CLOCKS_PER_SEC<<"s\n";

int T;
LL r, t;

LL F(LL i, LL t) {
	double x = i;
	if((2 * x + 1) * (x + 1) + (2 * r) * (x + 1) > 3e18) return 1;
	if((2 * i + 1) * (i + 1) + (2 * r) * (i + 1) > t) return 1;
	else return 0;
}

int main() {
	cin >> T;
	for(int ts = 1; ts <= T; ts++) {
		cin >> r >> t;
		LL tot = 0;
		LL ans = -1;
		LL L = 1, R = 1000000000;
		while(L < R) {
			LL M = (L + R) / 2;
			if(F(M, t)) {
				R = M;
			} else {
				L = M + 1;
			}
		}
		ans = L;
		cout << "Case #" << ts << ": " << ans << endl;
	}


	return 0;
}
