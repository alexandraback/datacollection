#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int a[10];
int v[10][10];
int n, m;
void input()
{
	int i, j, k;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		a[i] = j;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			v[i][j] = 0;
	while(m--)
	{
		scanf("%d %d",&i,&j);
		i--;j--;
		v[i][j] = v[j][i] = 1;
	}
}
int p[10];
int d[10];
int pl=0;
void able(int si)
{
	int i, j;
	while(pl<n)
	{
		if(v[si][p[pl]] == 1)
		{
			pl++;
			able(p[pl-1]);
		}
		else
			break;
	}
}
void process()
{
	int i, j, k;
	int dap = 0;
	for(i=0; i<n;i++)
	{
		p[i] = i;
	}
	do{
		pl=1;
		able(p[0]);
		if(pl==n)
		{
			if(dap == 0)
			{
				dap = 1;
				for(i=0;i<n;i++)
					d[i] = p[i];
			}
			else
			{
				for(i=0;i<n;i++)
				{
					if(a[d[i]] > a[p[i]])
					{
						for(i=0;i<n;i++)
							d[i] = p[i];
						break;
					}
					else if(a[d[i]] < a[p[i]])
						break;
				}
			}
		}
	} while(next_permutation(p,p+n));
	for(i=0;i<n;i++)
		printf("%d",a[d[i]]);
}
int main()
{
	int t, tv;
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small-attempt0.out","wt",stdout);
	scanf("%d",&t);
	tv = 0;
	while(t--)
	{
		tv++;
		input();
		printf("Case #%d: ",tv);
		process();
		printf("\n");
	}
}