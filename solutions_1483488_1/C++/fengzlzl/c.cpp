#include <stdio.h>
#include <map>

using namespace std;

int main()
{
	int T, a, b, d, x, i, j, cas=0;
	map<int, bool> used;
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d%d", &a, &b);
		for (i=a; i<b; i++)
	//	i=10030206;
		{
			used.clear();
			for (d=1; d*10<i; d*=10);
			for (x=10; x<=d; x*=10)
			{
				j=i/x + d/x*10*(i%x);
				if (j>=d && j>i && j<=b && !used[j])
				{
					//if (used[j]) printf("%d %d\n", i, j);
					used[j]=true;
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}