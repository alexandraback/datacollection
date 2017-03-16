#include <stdio.h>
#include <algorithm>

using namespace std;

struct node
{
	int sta, tot;
	bool operator < (const node &a) const
	{
		return tot<a.tot;
	}
} b[(1<<20)+5];

int a[30], c[30];
int n;

void print(int sta)
{
	int i, cn;
	cn=0;
	for (i=0; i<n; i++)
	  if (sta&(1<<i)) c[cn++] = a[i];
	for (i=0; i<cn; i++)
	  if (i==cn-1) printf("%d\n", c[i]);
	  else printf("%d ", c[i]);  
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("bout.txt", "w", stdout);
	int T, cas=0;
	int i, j;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		  scanf("%d", &a[i]);
		for (i=0; i<(1<<n); i++)
		{
			b[i].sta = i;
			b[i].tot = 0;
			for (j=0; j<n; j++)
				if (i&(1<<j)) b[i].tot +=a[j];
		}
		printf("Case #%d:\n", ++cas);
		sort(b, b+(1<<n));
		for (i=1; i<(1<<n); i++)
			if (b[i].tot == b[i-1].tot)
			{
				print(b[i-1].sta);
				print(b[i].sta);
				break;	
			}
		if (i==(1<<n)) printf("Impossible\n");
	}
	return 0;
}