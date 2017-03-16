#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007
#define update(a,b) { a = max(a,(b)); }

int v[MaxN],f[102][102]; int e,r,n;
int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) { printf("Case #%d: ",TTT);
			scanf("%d%d%d",&e,&r,&n);
		For(i,1,n) scanf("%d",&v[i]);
		Fill(f,-INF); f[0][e] = 0;
		For(i,0,n - 1) For(j,0,e) if (f[i][j] >= 0) {
			For(k,0,j) {
				update(f[i + 1][min(e,j - k + r)],f[i][j] + k * v[i + 1]);
			}
		}
		int ans = 0;
		For(i,r,e) ans = max(ans,f[n][i]);
		cout << ans << endl;
	}
	return 0;
}

