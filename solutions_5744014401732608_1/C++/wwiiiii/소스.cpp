#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void solve(int);
int b, m;
int chk[55];
int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
}

void solve(int casen)
{
	scanf("%d %d", &b, &m);
	fill(chk, chk + 55, 0);
	long long int maxi = 1;
	bool flag = true;
	for (int i = 0; i < b - 2; i++) maxi *= 2;
	printf("Case #%d: ", casen);
	if (m > maxi) {
		puts("IMPOSSIBLE"); return;
	}
	while (m > 0)
	{
		if (m == 1)
		{
			chk[1] = 1;
			break;
		}
		int temp = m, po = -1;
		while (temp > 0)
		{
			temp = temp >> 1;
			po++;
		}
		if (m == maxi)
		{
			for (int i = 1; i < b; i++) chk[i] = 1;
			break;
		}
		m = m - (1 << po);
		chk[po + 2] = 1;
		flag = false;
	}
	printf("POSSIBLE\n",b,m);
	for (int i = 1; i <= b; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (i >= j) printf("0");
			else
			{
				if (j < b) printf("1");
				if (j == b && chk[i] == 1) printf("1\n");
				if (j == b && chk[i] == 0) printf("0\n");
			}
		}
	} puts("");
	return;
}
