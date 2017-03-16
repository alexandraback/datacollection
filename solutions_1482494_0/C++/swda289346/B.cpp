#include <stdio.h>
#include <algorithm>
#include <deque>
#define A 2001
using namespace std;

int main()
{
	int t;
	int n;
	int a, b;
	int star, count, last;
	int left[A+1];
	deque<int> list[A+1];
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		star = 0;
		count = 0;
		last = -1;
		for (int j=0;j<=A;++j)
		{
			list[j].clear();
			left[j] = 0;
		}
		scanf("%d", &n);
		for (int j=0;j<n;++j)
		{
			scanf("%d%d", &a, &b);
			list[a].push_back(b);
		}
		for (int j=0;j<=A;++j)
			sort(list[j].begin(), list[j].end());
		do
		{
			int play = 0, pos = -1;
			for (int j=0;j<=star;++j)
				if (list[j].size())
				{
					while (list[j].size() && list[j].front()<=star)
					{
						star += 2;
						++count;
						list[j].pop_front();
						play = 1;
					}
					if (!play)
					{
						if (pos==-1)
							pos = j;
						else if (list[j].back()>list[pos].back())
							pos = j;
					}
				}
			if (play==0 && pos!=-1)
			{
				++left[list[pos].back()];
				++star;
				++count;
				list[pos].pop_back();
			}
			else if (play==0 && pos==-1)
				break;
			for (int j=last+1;j<=star;++j)
			{
				star += left[j];
				count += left[j];
			}
			last = star;
		}while (star!=n*2);
		if (star!=n*2)
			printf("Case #%d: Too Bad\n", i);
		else
			printf("Case #%d: %d\n", i, count);
	}
	return 0;
}
