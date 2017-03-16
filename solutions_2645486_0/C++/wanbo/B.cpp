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

int T, E, R, N;
int d[10010];
int mx;

void dfs(int pos, int energy, int gain) {
	if(pos == N) {
		mx = max(gain, mx);
		return;
	}
	for(int i = 0; i <= energy; i++) {
		int ne = energy - i + R;
		if(ne > E) ne = E;
		dfs(pos + 1, ne, gain + d[pos] * i);
	}
}

int main() {
	cin >> T;
	for(int ts = 1; ts <= T; ts++) {
		cin >> E >> R >> N;
		for(int i = 0; i < N; i++) cin >> d[i];
		mx = 0;	
		dfs(0, E, 0);
		cout << "Case #" << ts << ": " << mx << endl;
	}
	return 0;
}
