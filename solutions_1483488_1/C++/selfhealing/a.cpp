#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10],b[10],A,B;
char s[10];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	a[0] = 1;
	for(int i = 1; i < 8; i++)
		a[i] = a[i-1]*10;
	int T,cas=0;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&A,&B);
		int ret = 0;
		for(int i = A; i <= B; i++)
		{
			sprintf(s,"%d",i);
			int n = strlen(s), t = i;
			for(int j = 0; j < n-1; j++)
			{
				t = t/10+t%10*a[n-1];
				b[j] = t;
			}
			sort(b,b+n-1);
			for(int j = 0; j < n-1; j++)
				if(j==0 || b[j]!=b[j-1])
					if(A<=b[j] && b[j]<=B && b[j]<i)
						ret++;
		}
		printf("Case #%d: %d\n",++cas,ret);
	}

	return 0;
}
