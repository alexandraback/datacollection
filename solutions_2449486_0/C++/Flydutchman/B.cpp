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

int T,R,C,A[202][202],rm[202],cm[202];
int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) {
			printf("Case #%d: ",TTT);
			cin >> R >> C;
		For(i,1,R) For(j,1,C) scanf("%d",&A[i][j]);
		For(i,1,R) {
			rm[i] = -INF; For(j,1,C) rm[i] = max(rm[i],A[i][j]);
		}
		For(j,1,C) {
			cm[j] = -INF; For(i,1,R) cm[j] = max(cm[j],A[i][j]);
		}
		bool fll = false ;
		For(i,1,R) {
			bool fl = false ;
			For(j,1,C) if (A[i][j] < rm[i] && A[i][j] < cm[j]) {
				puts("NO"); fl =true; break ;
			} if (fl) {fll = true; break ; }
		}
		if (!fll) puts("YES");
	}	
	return 0;
}

