#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 500
struct node
{
	int x, y;
	int s;
	int ti;
};
node att[N];
int cmp(const void *a, const void *b)
{
	node *c = (node *)a;
	node *d = (node *)b;
	if(c->ti != d->ti)
		return c->ti - d->ti;
	return c->s - d->s;
}
int val[N];
int main()
{
	int num, tcase, icase = 1;
	int i, j, k;
	int n;
	int di, ni, wi, ei, si, ddi, dpi, dsi;
	scanf("%d", &tcase);
	while(tcase--)
	{
		num = 0;
		scanf("%d", &n);
		memset(val, 0, sizeof(val));
		for(i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d%d%d%d",&di, &ni, &wi, &ei, &si, &ddi, &dpi, &dsi);
			for(j = 0; j < ni; j++)
			{
				att[num].ti = di + j * ddi;
				att[num].s = si + j * dsi;
				att[num].x = wi + j * dpi + 200;
				att[num].y = ei + j * dpi + 200;
				num++;
			}
		}
		qsort(att, num, sizeof(node), cmp);
		int sum = 0;
		for(i = 0; i < num; i++)
		{
			for(j = att[i].x ; j < att[i].y; j++)
			{
				if(val[j] < att[i].s)
				{
					sum++;
					break;
				}
			}
			if(i + 1 != num && att[i + 1].ti != att[i].ti)
			{
				for(j = i; j >= 0 && att[j].ti == att[i].ti; j--)
				{
					for(k = att[j].x ; k < att[j].y; k++)
						val[k] = max(val[k], att[j].s);
				}
			}
		}
		printf("Case #%d: %d\n", icase++, sum);
	}
	return 0;
}
