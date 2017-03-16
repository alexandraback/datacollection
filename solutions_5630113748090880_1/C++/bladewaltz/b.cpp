#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[111];
int ha[3333];
int n;
vector<int> ans;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	int k = 0;
    while(T--)
	{
		scanf("%d",&n);
		memset(ha, 0, sizeof(ha));
		ans.clear();
		for(int i = 1; i <= 2 * n - 1; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				scanf("%d",&a[j]);
				ha[a[j]] ++;
			}
		}
		for(int i = 1;i <= 2522; ++i)
		{
			if(ha[i] != 0)
			{
				if(ha[i] & 1) ans.push_back(i);
			}
		}

		sort(ans.begin(), ans.end());
		printf("Case #%d: ", ++k);
		for(int i = 0; i < ans.size() - 1; ++i) printf("%d ",ans[i]);
		printf("%d\n",ans[ans.size() - 1]);

	}
	return 0;
}
