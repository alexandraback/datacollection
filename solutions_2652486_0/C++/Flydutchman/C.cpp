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

int R,N,M,K,a[5],cache[1020][200],b[10],A[1020],app[1020];
int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	printf("Case #1:\n"); scanf("%*d");
	cin >> R >> N >> M >> K;
	For(i,2,M) For(j,2,M) For(k,2,M) {
		int num = (i * (M + 1) + j) * (M + 1) + k;
			if(num==210){
				int z=i;
			}
		a[0] = i, a[1] = j, a[2] = k;
		For(S,0,7) {
				int prod = 1;
			For(p,0,2) if (S >> p & 1) prod *= a[p];
			++cache[num][prod];
		}
	}
	For(i,1,R) {
			if(i==1){
				int z=i;
			}
			Fill(app,0);
		For(j,1,K) {
				int t;
			scanf("%d",&b[j]);
		}
		int Tot = 0;
		For(j,1,1000) {
			bool fl = true;
			For(p,1,K) if (!cache[j][b[p]]) { fl = false ;break ; }
			if (fl) {
				A[++Tot] = j;
			}
		}
		int c = A[rand() % Tot + 1];
		if (c % (M + 1) == 0) {
			int z = i;
		}
		//cout << c % (M + 1) << (c / (M + 1) % (M + 1)) << (c / (M + 1) / (M + 1)) << endl;
		printf("%d%d%d\n",c%(M+1),c/(M+1)%(M+1),c/(M+1)/(M+1));
	}
	return 0;
}

