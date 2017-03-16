#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int d[1005][1005];
int n;
bool f()
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
					d[i][j]+=d[i][k]*d[k][j];
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
    freopen("a.txt","r",stdin);
	freopen("n.txt","w",stdout);
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = 0;
		int num,tar;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&tar);
				d[i][tar] = 1;
			}
		}

		if(f())
	    	printf("Case #%d: %s\n",cas++,"Yes" );
 	    else
 	        printf("Case #%d: %s\n",cas++, "No");
    }
    return 0;
}
