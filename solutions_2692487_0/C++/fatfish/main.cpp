#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a;
int motes[106];

void inputData()
{
	scanf("%d%d", &a, &n);
	for (int i = 0; i < n; ++ i)
	{
		scanf("%d", &motes[i]);
	}
}

void process(int cases)
{
	sort(motes, motes + n);

	int ret = n;

	if (a != 1)
	{
		int his = 0;
		for (int i = 0; i < n; ++ i)
		{
			while (a <= motes[i])
			{
				a = 2 * a - 1;
				++ his;
			}
			a += motes[i];

			int cur = his + (n - 1 - i);
			if (ret > cur)
			{
				ret = cur;
			}
		}
	}
	
	printf("Case #%d: %d\n", cases, ret);
}

int main()
{
	//freopen("E:\\codejam\\A\\A-small-attempt0 (1).in", "r", stdin);
	//freopen("E:\\codejam\\A\\out.txt", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; ++ i)
	{
		inputData();
		process(i);
	}
	
	return 0;
}