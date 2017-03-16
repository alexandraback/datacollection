#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

#define SI(x) scanf("%d ",&x)
#define SL(x) scanf("%lld",&x)

#define MX 2000006
typedef long long LL;
using namespace std;

int S[22];
int ways[1<<21];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-output.txt","w",stdout);
   
    int T,tnum = 1;
    SI(T);

    while(T-- >0)
    {
	printf("Case #%d: \n",tnum);
	tnum++;
	int n;
	SI(n);
	for(int i=0;i<n;i++)
	{
		SI(S[i]);
	}
	sort(S,S+20);

	memset(ways,0,sizeof(ways));
	bool ok = false;

	for(int i=1;i<(1<<n);i++)
	{

		LL sum = 0;
		for(int j=0;j<n;j++)
		{
			if((i&(1<<j)) > 0)
			{
				sum+=S[j];
			}
		}
		if(ways[sum]!=0)
		{
			for(int k=0;k<n;k++)
			{
				if((ways[sum] &(1<<k)) > 0)
				{
					printf("%d ",S[k]);
				}
			}
			printf("\n");
			for(int k=0;k<n;k++)
			{
				if((i&(1<<k)) > 0)
				{
					printf("%d ",S[k]);
				}
			}
			printf("\n");
			ok = true;
		}
		else
			ways[sum] = i;
		if(ok) break;

	}
	if(!ok)
	{
		printf("Impossible\n");
	}

    }


    fclose(stdout);
	return 0;
}
