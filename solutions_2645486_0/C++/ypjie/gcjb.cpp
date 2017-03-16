#include <stdio.h>
#include <string.h>
using namespace std;

const int E = 5 +10;
const int N = 10 +10;
const int OO = 1000000000;

int ans;
int e;
int n;
int nowtd;
int r;
int tdnum;
int a[N];
int f[N][E];

int max(int &a, int b) {if (b > a) a = b;}
int min(int &a, int b) {if (b < a) a = b;}

void ri()
{
	int i;
	int j;
	
	ans = -OO;
	for (i = 0; i < N; i++) for (j = 0; j < E; j++) f[i][j] = -OO;
	scanf("%d%d%d", &e, &r, &n);
	f[0][e] = 0;
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve()
{
	int i;
	int j;
	int k;
	
	for (i = 0; i < n; i++)
		for (j = 0; j <= e; j++)
			if (f[i][j] >= 0)
				for (k = 0; k <= j; k++)
					if (j - k + r <= e) max(f[i + 1][j - k + r], f[i][j] + a[i] * k);
	for (i = 0; i <= e; i++) max(ans, f[n][i]);
}

void print() {printf("Case #%d: %d\n", nowtd, ans);}

int main()
{
	scanf("%d", &tdnum);
	for (nowtd = 1; nowtd <= tdnum; nowtd++)
	{
		ri();
		solve();
		print();
	}
	return 0;
}
