#include <iostream>
#include <cstdio>
using namespace std;
const int maxs = 300, maxk = 10, maxn = 5, maxm = 10;

int dat[maxk];
int sets[maxs][maxn], scnt;
int n, m, k, r;

int now[maxn];
void getsets(int dep = 0)
{
	if (dep >= n)
	{
		for (int i = 0; i < n; i++) sets[scnt][i] = now[i];
		scnt++;
		return;
	}
	
	for (int i = 2; i <= m; i++)
	{
		now[dep] = i;
		getsets(dep + 1);
	}
}

long long cnt[maxs][maxs];

void calcset(int k, int dep = 0, int now = 1)
{
	if (dep >= n)
	{
		cnt[k][now]++;
		return;
	}
	
	calcset(k, dep + 1, now);
	calcset(k, dep + 1, now * sets[k][dep]);
}

long long setscnt[maxs];
void getscnt()
{
	static int counts[maxm];
	static long long fact[maxn];
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
	for (int i = 0; i < scnt; i++)
	{
		for (int j = 2; j <= m; j++) counts[j] = 0;
		for (int j = 0; j < n; j++) counts[sets[i][j]]++;
		setscnt[i] = fact[n];
		for (int j = 2; j <= m; j++) setscnt[i] /= fact[counts[j]];
	}
}

void init()
{
	for (int i = 0; i < k; i++) scanf("%d", &dat[i]);
}

long long f[maxs];
int work()
{
	int ans = -1;
	for (int i = 0; i < scnt; i++)
	{
		f[i] = setscnt[i];
		for (int j = 0; j < k; j++) f[i] *= cnt[i][dat[j]];
		if (ans < 0 || f[ans] < f[i]) ans = i;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	scanf("%d%d%d%d", &r, &n, &m, &k);
	getsets();
	for (int i = 0; i < scnt; i++) calcset(i);
	getscnt();
	printf("Case #1:\n");
	for (int i = 0; i < r; i++)
	{
		init();
		int res = work();
		for (int i = 0; i < n; i++) printf("%d", sets[res][i]);
		printf("\n");
	}
	return 0;
}
