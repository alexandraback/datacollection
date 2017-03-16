#include <stdio.h>
#include <set>
#include <vector>
#include <string>
using namespace std;

const int maxn = 510;
int n;
int a[maxn];

bool f[2000000];
int ans[2000000];


void solve()
{
    memset(f,0,sizeof(f));
	int i,j;
	for(i=1;i<(1<<n);i++)
	{
		int sum = 0;
		for(j=0;j<n;j++)
			if((1<<j)&i)
				sum += a[j];
		if(!f[sum])
		{ 
           f[sum] = true;
		   ans[sum] = i;
		}
		else
		{
			vector<int> r1,r2;
            int k=0;
			for(k=0;k<n;k++)
				if((1<<k)&i)
                   r1.push_back(a[k]);

			for(k=0;k<n;k++)
				if((1<<k)&ans[sum])
					r2.push_back(a[k]);
            
			for(k=0;k<r1.size()-1;k++)
				printf("%d ",r1[k]);
			printf("%d\n",r1[k]);

			for(k=0;k<r2.size()-1;k++)
				printf("%d ",r2[k]);
			printf("%d\n",r2[k]);
			return ;
		}
	}
	printf("Impossible\n");
    
}

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.txt","w",stdout);
	int ct,caset = 1;
	scanf("%d",&ct);

	while(ct--)
	{
		printf("Case #%d:\n",caset++);         
	    scanf("%d",&n);
		int i;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		solve();
	}
	return 0;
}