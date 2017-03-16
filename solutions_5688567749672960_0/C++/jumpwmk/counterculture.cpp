#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char  x[100];
int mic[1000100];

int main()
{
	int q,j,k,len,cnt;
	long long i,n,tmp=0;
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	scanf("%d",&q);
	for(k=1;k<=q;k++)
	{
		cnt=0;
		scanf("%lld",&n);
		i=0;
		for(i=1;i<=n;i++)
			mic[i]=10000100;
		for(i=1;i<=n;i++)
		{
			if(mic[i-1]+1 < mic[i])
				mic[i]=mic[i-1]+1;
			sprintf(x,"%lld",i);
			len=strlen(x);
			reverse(x,x+len);
			sscanf(x,"%lld",&tmp);
			if(tmp <= n && mic[i]+1 < mic[tmp])
				mic[tmp]=mic[i]+1;
		}
		printf("Case #%d: %d\n",k,mic[n]);
	}
	return 0;
}