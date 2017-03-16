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
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int ans = 100000000;
		for(int i = 1; i <= 1000; i++)
		{
			int tmp = i;
			for(int j = 1; j <= n; j++)
				tmp += (a[j] - 1) / i;
			if(tmp < ans)
				ans = tmp;
		}
		
		printf("Case #%d: %d\n", t, ans);
	}
	
	return 0;
}

