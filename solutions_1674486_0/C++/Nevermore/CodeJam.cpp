#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int d[1005][1005];
int n;

bool f(int d[][1005])
{
	int i,j,k;
	for(k = 1; k <= n; k++)
	{
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(d[i][k] >= 1 && d[k][j] >= 1)
				{
					d[i][j]++;
					if(d[i][j] >= 2)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main()
{
    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int t, Case = 1, i, c, j, num;
    scanf("%d",&t);
    while(t--)
    {
		scanf("%d",&n);

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				d[i][j] = 0;

		for(i = 1; i <= n; i++)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&c);
				d[i][c] = 1;
			}
		}

		int flag = f(d);

		printf("Case #%d: %s\n",Case++, flag ? "Yes" : "No");
    }
    return 0;
}
