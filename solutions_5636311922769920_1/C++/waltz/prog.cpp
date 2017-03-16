#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;scanf("%d",&test);
	for (int T=1;T<=test;T++)
	{
		printf("Case #%d: ",T);
		int k,c,s;scanf("%d%d%d",&k,&c,&s);
		if (c*s<k) {puts("IMPOSSIBLE");continue;}
		for (int i=0;i<s;i++)
		{
			ll t=0;
			for (int j=0;j<c;j++) t=t*k+(i*c+j)%k;
			printf("%I64d",t+1);
			if ((i+1)*c>=k) {puts("");break;}
			putchar(' ');
		}
	}
	return 0;
}

