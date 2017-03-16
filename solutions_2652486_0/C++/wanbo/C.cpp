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

int T, R, N, M, K;

int d[10];

void F() {
	int a[3];
	int mx = 0, pos[3] = {2, 2, 2};
	for(a[0] = 2; a[0] <= M; a[0]++)
		for(a[1] = 2; a[1] <= M; a[1]++)
			for(a[2] = 2; a[2] <= M; a[2]++) {
				int p[8];
				for(int i = 0; i < 8; i++) {
					p[i] = 1;
					for(int j = 0; j < 3; j++) {
						if(i & (1 << j)) {
							p[i] *= a[j];
						}
					}
				}
				int t = 1;
				for(int i = 0; i < K; i++) t *= count(p, p + 8, d[i]);
			//	if(t) {
			//		cout << a[0] << " " << a[1] << " " << a[2] << endl;
			//		P(t);
			//	}
				if(t > mx) {
					mx = t;
					pos[0] = a[0];
					pos[1] = a[1];
					pos[2] = a[2];
				}
			}
	cout << pos[0] << pos[1] << pos[2] << endl;
}

int main() {
	cin >> T;
	for(int ts = 1; ts <= T; ts++) {
		cin >> R >> N >> M >> K;
		cout << "Case #" << ts << ": " << endl;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < K; j++) {
				cin >> d[j];
			}
			F();
		}
	}


	return 0;
}
