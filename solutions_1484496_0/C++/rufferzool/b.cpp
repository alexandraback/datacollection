#include <cstdio>
#include <cstring>

using namespace std;

bool sums[2000010] = { false };
int match[2000010];
int a[21];

void print(int p, int q)
{
	printf("\n");
	for(int i = 0; i < 20; i ++)
	{
		if(p & (1 << i))
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
	for(int i = 0; i < 20; i ++)
	{
		if(q & (1 << i))
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

int main()
{
	int T;
	scanf(" %d", &T);
	for(int z = 1; z <= T; z ++)
	{
		printf("Case #%d:", z);
		int n;
		bool done = false;
		scanf(" %d", &n);
		for(int i = 0; i < n; i ++)
		{
			scanf(" %d", a + i);
		}
		for(int i = 0; i < n; i ++)
		{
			for(int j = i + 1; j < n; j ++)
				if(a[i] == a[j])
				{
					printf("\n%d\n%d\n", a[i], a[j]);
					done = true;
				}
		}
		if(!done)
		{
		for(int i = 1; i < (1 << 20); i ++)
		{
			int sum = 0;
			for(int j = 0; j < 20; j ++)
			{
				if(i & (1 << j))
					sum += a[j];
			}
			if(sums[sum] == true)
			{
				print(i, match[sum]);
				done = true;
				break;
			}
			else
			{
				sums[sum] = true;
				match[sum] = i;
			}
		}
		}
		if(!done)
			printf(" Impossible\n");
		memset(sums, false, sizeof(sums));
	}
}
