#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a[1000];
int b1[2000005];

int main(void)
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int q = 1; q <= t; q++)
	{
		memset(b1,-1,sizeof(b1));
		int n;
		scanf("%d",&n);
		for (int i = 0 ; i < n; i++)
			scanf("%d",&a[i]);
		vector<int> ans;
		for (int i = 1; i < (1 << n); i++)
		{
			int sum = 0;
			for (int j = 0 ; j< n; j++)
				if (i & (1 << j))
					sum+= a[j];
			if (b1[sum] != -1)
			{
				ans.push_back(b1[sum]);
				ans.push_back(i);
				break;
			} else
				b1[sum] = i;
		}
		printf("Case #%d:\n",q);
		if	(ans.size() == 0)
		{
			printf("Impossible\n");
		} else
		{
			vector<int> v;
			for (int j = 0 ; j < n; j++)
				if (ans[0] & (1 << j))
					v.push_back(a[j]);
			for (int i = 0 ; i< v.size(); i++)
				printf("%d%c", v[i], (i == (v.size() -1)) ? '\n' : ' ');
			v.clear();
			for (int j = 0 ; j < n; j++)
				if (ans[1] & (1 << j))
					v.push_back(a[j]);
			for (int i = 0 ; i< v.size(); i++)
				printf("%d%c", v[i], (i == (v.size() -1)) ? '\n' : ' ');
		}
	}
	return 0;
}