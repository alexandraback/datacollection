#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		int n;
		scanf("%d", &n);
		
		double naomi[1024];
		double ken[1024];
		
		int i;
		for(i = 0; i < n; i ++)
		{
			scanf("%lf", &naomi[i]);
		}
		set<double> kenset;
 		set<double>::iterator Item;
		
		for(i = 0; i < n; i ++)
		{
			scanf("%lf", &ken[i]);
			kenset.insert(ken[i]);
		}
		sort(naomi, naomi+n);
		sort(ken, ken+n);
		
		int ans1, ans2, j;
		j = ans1 = ans2 = 0;
		for(i = 0; i < n; i ++)
		{
			if(ken[j] < naomi[i])
			{
				j ++;
				ans1 ++;
			}
			Item = kenset.lower_bound(naomi[i]);
			if(Item == kenset.end())
			{
				ans2 ++;
			}
			else {
				kenset.erase(Item);
			}
		}
		printf("Case #%d: %d %d\n", cas, ans1, ans2);
	}
	return 0;
}
