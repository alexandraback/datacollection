#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//init();
	
	//printf("Input File Name ?");
	char FileName[128];
	//scanf("%s", FileName);
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	int Case;
	for(Case = 1;  Case <= T; Case ++)
	{
		int a, n;
		int b[128];
		scanf("%d%d", &a, &n);
		int i, j, k;
		for(i = 0; i < n; i ++)
		{
			scanf("%d", &b[i]);
		}
		sort(b, b+n);
		int ans = n;
		int tmp = 0;
		for(i = 0; i < n; i ++)
		{
			if(tmp + n - i < ans)ans = tmp + n - i;
			while(a <= b[i])
			{
				a += (a-1);
				tmp ++;
				if(tmp > ans)break;
			}
			a += b[i];
			if(tmp + n - 1 - i < ans)ans = tmp + n - 1 - i;
			//printf("%d %d %d\n", a, tmp, ans);
		}
		printf("Case #%d: %d\n", Case, ans);
	}
	
	return 0;
}
