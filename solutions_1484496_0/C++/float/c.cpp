#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct x
{
	int n;
	char used[50];
};

int cmp(const void* a, const void* b)
{
	x *aa, *bb;
	aa = (x *)a;
	bb = (x *)b;
	return aa->n - bb->n;
}

int total, num[510], vist[510];
x all[2000000];

int bt(int i, int k, int sum)
{
	if(i >= k)
	{
		all[total].n = sum;
		for(int j=0; j<k; j++)
			if(vist[j])
				all[total].used[j] = 1;
		total++;
		return 0;
	}
	vist[i] = 1;
	bt(i+1, k, sum + num[i]);
	vist[i] = 0;
	bt(i+1, k, sum);
	return 0;
}

int main()
{
	int t, cas;
	int n, i, flag, j, k, first;
	scanf("%d", &t);
	for(cas=1; cas<=t; cas++)
	{
		memset(all, 0, sizeof(all));
		memset(vist, 0, sizeof(vist));
		total = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d", &num[i]);
		bt(0, n, 0);
		qsort(all, total, sizeof(x), cmp);
		flag = 0;
		for(i=0; i<total; i++)
		{
			for(j=i+1; j<total; j++)
			{
				if(all[i].n != all[j].n)
					break;
				for(k=0; k<n; k++)
				{
					if(all[i].used[k] == 1 && all[j].used[k] == 1)
						break;
				}
				if(k==n)
				{
					flag = 1;
					goto end;
				}
			}
		}
		end:
		printf("Case #%d:\n", cas);
		if(flag)
		{
			first = 1;
			for(k=0; k<n; k++)
			{
				if(all[i].used[k])
				{
					if(first)
					{
						printf("%d", num[k]);
						first = 0;
					}
					else
						printf(" %d", num[k]);
				}
			}
			printf("\n");
			first = 1;
			for(k=0; k<n; k++)
			{
				if(all[j].used[k])
				{
					if(first)
					{
						printf("%d", num[k]);
						first = 0;
					}
					else
						printf(" %d", num[k]);
				}
			}
			printf("\n");
		}
		else
		{
			puts("Impossible");
		}
	}
	return 0;
}
