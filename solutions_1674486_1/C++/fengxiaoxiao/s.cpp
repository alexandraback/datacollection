#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int s[1005][1005];
int n;

bool fa(int s[][1005])
{
	int i,j,k;
	for(i = 1; i <= n; i++)
	{
		for(j=1 ; j<= n; j++)
		{
			for(k = 1; k <= n; k++)
			{
				if(s[j][i] >= 1 && s[i][k] >= 1)
				{
					s[j][k]++;
					if(s[j][k] >= 2)
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
   //freopen("D:\\test.txt","r",stdin);
	freopen("e:\\test.txt","w",stdout);
    int t, count = 1, i, c, j, num;
    scanf("%d",&t);
    while(t--)
    {
		scanf("%d",&n);
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				s[i][j] = 0;

		for(i = 1; i <= n; i++)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&c);
				s[i][c] = 1;
			}
		}

		int re = fa(s);

		printf("Case #%d: %s\n",count++, re ? "Yes" : "No");
    }
    return 0;
}


