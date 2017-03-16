#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> arr[1000];

struct pc
{
	bool operator()(pair<int, int>& l, pair<int, int>& r)
	{
		return l.second < r.second;
	}
};

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			arr[i].first = a;
			arr[i].second = b;
		}

		sort(arr, arr+n, pc());

		int cs = 0;
		int mv = 0;
		
		for (int i=0; i<n; ++i)
		{
			while (cs < arr[i].second)
			{
				bool found = false;
				
				for (int j=n-1; j>=0; --j)
				{
					if (arr[j].first != -1 && arr[j].second != -1 && cs >= arr[j].first)
					{
						arr[j].first = -1;
						++cs;
						++mv;
						found = true;
						break;
					}
				}

				if (!found)
					break;
			}

			if (cs < arr[i].second)
			{
				mv = -1;
				break;
			}

			arr[i].second = -1;
			++mv;
			if (arr[i].first == -1)
				++cs;
			else
				cs += 2;
		}

		printf("Case #%d: ", c);
		if (mv == -1)
			printf("Too Bad\n");
		else
			printf("%d\n", mv);
	}
	
	return 0;
}