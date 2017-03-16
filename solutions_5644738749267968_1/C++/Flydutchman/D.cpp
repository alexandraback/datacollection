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

int n; double A[2333],B[2333];
int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) {
		printf("Case #%d: ",TTT);
		cin >> n;
		For(i,1,n) scanf("%lf",&A[i]);
		For(i,1,n) scanf("%lf",&B[i]);
		sort(A + 1,A + n + 1);
		sort(B + 1,B + n + 1);
		int ans_fair = 0, p = 1;
		For(i,1,n) {
			while (B[p] < A[i] && p <= n) ++p;
			if (p > n) break ;
			++ans_fair;
			++p;
		}
		swap(A,B);
		int ans_deceit = 0; p = 1;
		For(i,1,n) {
			while (B[p] < A[i] && p <= n) ++p;
			if (p > n) break ;
			++ans_deceit;
			++p;
		}
		cout << ans_deceit << ' ' << n - ans_fair  << endl;
	}
	return 0;
}

