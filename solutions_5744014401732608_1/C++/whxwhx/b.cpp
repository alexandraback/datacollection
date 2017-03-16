#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long LL;
const int N = 55;
int mp[N][N];
void add_edge(int a, int b) { mp[a][b] = 1; }
int main(){
	int T, t = 0; scanf("%d",&T);
	while (T--){
		memset(mp, 0, sizeof(mp)); t++; printf("Case #%d: ",t);
		int n; LL m; scanf("%d%lld",&n,&m);
		rep(i,2,n) rep(j,i + 1,n) add_edge(i, j);
		if (m > (1LL << (n - 2))) { cout <<"IMPOSSIBLE"<<endl; continue; } else cout <<"POSSIBLE"<<endl;
		if (m) m--, add_edge(1, n);
		rep(i,0,n - 3) if (m >> i & 1) add_edge(1, n - i - 1);
		rep(i,1,n) {
			rep(j,1,n) cout <<mp[i][j];
			cout <<endl;
		}
	}
}