#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl
#define sqr(x) ((x)*(x))


int n,m,tests;

struct node
{
	int id;
	double v;
}a[100010];

int use[100010];

int cmp(node a, node b)
{
	return a.v > b.v;
}

int main()
{
	freopen("d1.in","r",stdin);
	freopen("d1.out","w",stdout);
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%lf",&a[i].v);
			a[i].id = 1;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%lf",&a[n+i].v);
			a[n+i].id = 2;
		}
		
		sort(a+1,a+n+1,cmp);
		sort(a+n+1,a+n*2+1,cmp);
		
		int p = n+1, q = n*2, score1 = 0, score2 = 0;
		for (int i=1;i<=n;i++)
		{
			if (a[p].v > a[i].v)
			{
				p++;
			}
			else {
				q--;
				score1++;
			}
		}
		
		p = n + 1;
		q = n * 2;
		for (int i=n;i>=1;i--)
		{
			if (a[i].v > a[q].v)
			{
				score2++;
				q--;
			}
			else {
				p++;
			}
		}
		
		//sort(a+1,a+n*2+1,cmp);
		//for (int i=1;i<=n+n;i++) printf("%.3f %d,  ", a[i].v, a[i].id); printf("\n");
		printf("Case #%d: %d %d\n", test, score2, score1);
	}
	return 0;
}
