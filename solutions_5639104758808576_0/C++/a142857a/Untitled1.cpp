#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1005;

int c[MAXN], a[MAXN];
int n;

int main()
{
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	int T = 0;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		for(int i = 0; i <= n; i++)
		{
			char tmp;
			if(i == 0) getchar();
			scanf("%c", &tmp);
			c[i] = tmp - '0';
		}
		for(int i = 1; i <= n; i++)
		c[i] += c[i-1];
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i - c[i - 1] > ans)
				ans = i - c[i - 1];
		}
		printf("Case #%d: %d\n", t, ans);
	}
	
	return 0;
}

