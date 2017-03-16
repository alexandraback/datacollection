#include<iostream>
using namespace std;
bool is[1001][1001] = { 0 };
#define mx 1001
int dp[mx];
long long k, B;
int  msk;
int pos[mx][mx];
void dfs(int x) {
	if (dp[x] != -1) return;
	dp[x] = 0;
	if (x == B)
		dp[x] = 1;
	for (int i = x+1;i <= B;++i) {
		if (msk & (1 << pos[x][i]))
		{
			dfs(i);
			dp[x] += dp[i];
		}
	}
}
int main() {
	int T;
	freopen("B.in", "r", stdin);

	freopen("out.out", "w", stdout);
	cin >> T;
	for (int cas = 1;cas <= T;++cas) {
		int n = 1;
		printf("Case #%d: ", cas);
		
		cin >> B >> k;
		int mxx = B*(B - 1) / 2;
		int p = 0;
		for (int i = 1;i <= B;++i)
			for (int j = i + 1;j <= B;++j)
				pos[i][j] = p++;
		bool found = 0;
		for (msk = 0;msk < (1 << mxx);++msk) {
			memset(dp, -1, sizeof(dp));
			dfs(1);
			if (dp[1] == k) {
				puts("POSSIBLE");
				for (int i = 1;i <= B;++i) {
					for (int j = 1;j <= B;++j)
						if(i<j)
						cout << (((1 << pos[i][j]) &msk) != 0);
						else cout << 0;
					printf("\n");
				}
				found = 1;
				break;
			}
		}
		if(!found)
		puts("IMPOSSIBLE");

	}

	//system("pause");
}