#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;
int p[110000];
int rec[110000];

int main()
{
	int t, teste;
	int n;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		int n;
		int i;
		scanf("%d\n", &n);
		bool shown[10];
		int count = 0;
		for (i = 0; i < 10; i++)
		{
			shown[i] = false;
		}

		if (n == 0)
		{
			printf("Case #%d: INSOMNIA\n", t + 1);
			continue;
		}

		int last = 0;
		while(true)
		{
			last += n;
			int temp = last;
			while (temp > 0)
			{
				int digit = temp % 10;
				temp /= 10;
				if (shown[digit] == false)
				{
					shown[digit] = true;
					count++;
				}
			}
			if (count == 10)
				break;
		}
		printf("Case #%d: %d\n", t + 1, last);
	}
	return 0;
}
