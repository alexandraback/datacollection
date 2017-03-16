#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=100010;
int p[110],pr[25];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",++cas);
		int a,n;
		scanf("%d%d",&a,&n);
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
        }
        if(a==1)
        {
            printf("%d\n",n);
            continue;
        }
        sort(p,p+n);
        int mi=n;
        for(i=0;i<=n;i++)
        {
            int sum=i,aa=a;
            for(j=0;j<n-i;j++)
            {
                while(aa<=p[j])
                {
                	aa+=(aa-1);
                	sum++;
                }
                aa+=p[j];
            }
            mi=min(mi,sum);
        }
        printf("%d\n",mi);

	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
