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

int g[101][101];
int r, c;

int row[101], col[101];

bool f() {
	MM(row, 0);MM(col, 0);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++) {
			row[i] = max(row[i], g[i][j]);
			col[j] = max(col[j], g[i][j]);
		}
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++) 
			if(g[i][j] != row[i] && g[i][j] != col[j]) return 0;
	return 1;
}

int main() {
	int T;
	cin >> T;
	for(int k = 1; k <= T; k++) {
		cin >> r >> c;
		for(int i = 0; i < r; i++)for(int j = 0; j < c; j++) scanf("%d", &g[i][j]);
		bool win = f();
		cout << "Case #" << k << ": " << (win ? "YES" : "NO") << endl;
	}
	return 0;
}
