#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(void)
{
	int t, c, d, v;
	scanf("%d", &t);
	for(int rep = 1;rep <= t;rep++)
	{
		scanf("%d%d%d", &c, &d, &v);
		vector<bool> marked(31*d, false);
		int tmp;
		for(int i = 0;i < d;i++)
		{
			scanf("%d", &tmp);
			marked[tmp] = true;
		}
		marked[0] = true;
		int ans = 0;
		for(int i = 0;i <= v;i++)
		{
			if(!marked[i])
			{
				bool done = false;
				for(int j = i-1;j >= 0;j--)
				{
					if(marked[j] && marked[i-j])
					{
						done = true;
						break;
					}
				}
				if(!done)
				{
					ans++;
					for(int j = i-1;j >= 0;j--)
					{
						if(marked[j] && !marked[i-j])
						{
							marked[i-j] = true;
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", rep, ans);
	}
}