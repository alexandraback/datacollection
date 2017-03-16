#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int n;
struct pii
{
	int x, y;
	bool operator < (const pii &r) const
	{
		if (y != r.y) return y < r.y;
		return x > r.x;	
	}
}a[maxn];
bool t[maxn];
int k, ans = 0;

void work()
{
	k = 0; ans = 0;
	memset(t, 0, sizeof(t));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		while (k < a[i].y)
		{
			bool b = false;
			for (int j = n; j >= i; j--)
				if (!t[j] && k >= a[j].x)
				{
					t[j] = 1; k++; ans++; b = true; break;
				}
			if (!b) {printf("Too Bad\n"); return;}
		}
		if (t[i]) k++; else k += 2;	
	}
	printf("%d\n", ans + n);
}

int main()
{
	freopen("B-small-attempt2.in" , "r" , stdin);
	freopen("B-small-attempt2.out" , "w" , stdout);
	int T, p = 0;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


