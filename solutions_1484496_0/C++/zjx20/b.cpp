#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int num[1000];

void print(int x)
{
	int cc = 0;
	bool first = true;
	while(x > 0)
	{
		if(x&1)
		{
			if(!first) printf(" ");
			else first = false;
			printf("%d", num[cc]);
		}
		x>>=1;
		cc++;
	}
	printf("\n");
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,ca=0;
	int n;

	scanf("%d: ",&t);
	while(t--)
	{
		printf("Case #%d:\n",++ca);

		scanf("%d",&n);
		map<int, vector<int>> s;
		int i;
		for(i=0;i<n;i++) scanf("%d",&num[i]);

		int a = 1 << 21,b = 1 << 21;

		int limit = (1<<20);
		for(i=1;i<limit;i++)
		{
			int cc = 0;
			int x = i;
			int sum = 0;
			while(x > 0)
			{
				if(x&1) sum += num[cc];
				cc++;
				x>>=1;
			}

			bool flag = false;
			
			if(s.find(sum) != s.end())
			{
				vector<int>& aa = s[sum];
				for(auto it = aa.begin(); it != aa.end(); ++it)
				{
					if(((*it) & i) == 0)
					{
						flag = true;
						a = *it;
						b = i;
						break;
					}
				}
			}

			s[sum].push_back(i);

			if(flag) break;
		}

		if(a == (1 << 21)) printf("Impossible\n");
		else
		{
			print(a);
			print(b);
		}
	}
	return 0;
}