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

long long getLL() {
	long long ret = 0;
	char c;
	while (1) {
		c = getchar();
		if (c >= '0' && c <= '9') break ;
	}
	while (1) {
		ret = ret * 10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') break ;
	}
	return ret;
}

int getInt() {
	int ret = 0;
	char c;
	while (1) {
		c = getchar();
		if (c >= '0' && c <= '9') break ;
	}
	while (1) {
		ret = ret * 10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') break ;
	}
	return ret;
}

int A[MaxN], n;
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	int T; cin >> T;
	for (int TK = 1; TK <= T; ++TK) {
		printf("Case #%d: ", TK);
		cin >> n;
		for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
		int ans = INF;
		for (int tg = 1; tg <= 1000; ++tg) {
			int spe = 0;
			for (int i = 1; i <= n; ++i) spe += (A[i] - 1) / tg;
			ans = min(ans, spe + tg);
		}
		cout << ans << endl;
	}
	return 0;
}

