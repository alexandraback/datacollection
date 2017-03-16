#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int s[10];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T,k=0;
	scanf("%d",&T);
	while(T!=0)
	{
		T--;
		k++;
		long long n;
		scanf("%lld",&n);
		if(n==0)
		{
			printf("Case #%d: INSOMNIA\n",k);
			continue;
		}
		memset(s,0,sizeof(s));
		int sx=0;
		long long t;
		long long tn=n;
		n=0;
		while(sx!=10)
		{
			n+=tn;
			t=n;
			while(t!=0)
			{
				int x=t%(long long)10;
				if(s[x]==0)
				{
					s[x]=1;
					sx++;
				}
				t/=10;
			}
		}
		printf("Case #%d: %lld\n",k,n);
	}
	return 0;
}
