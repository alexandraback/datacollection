#include <bits/stdc++.h>

using namespace std;

int S[105][55], C[3010];

inline void Read(int& x)
{
	x = 0;
	char ch = getchar();
	while(ch < '0') ch = getchar();
	while(ch >= '0') x = x * 10 + ch - '0', ch = getchar();
}

bool cmp(int x, int y)
{
	return S[x][1] < S[y][1];
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int s = 1; s <= _; s++)
	{
		printf("Case #%d: ", s);
		int n;
		scanf("%d", &n);
		memset(C, 0, sizeof C);
		for(int i = 1; i < n * 2; i++)
			for(int j = 1; j <= n; j++) Read(S[i][j]), C[S[i][j]] ^= 1;
		/*memset(Ans, 0, sizeof Ans);
		sort(tmp + 1, tmp + n * 2, cmp);
		if(S[tmp[1]][1] == S[tmp[2]][1])
		{
			for(int i = 1; i <= n; i++) Ans[1][i] = S[tmp[1]][i];
			for(int i = 1; i <= n; i++) Ans[i][1] = S[tmp[2]][i];
			for(int i = 3; i < n * 2; i += */
		for(int i = 1; i <= 2500; i++) if(C[i]) printf("%d ", i);
		putchar('\n');
	}
	return 0;
}
