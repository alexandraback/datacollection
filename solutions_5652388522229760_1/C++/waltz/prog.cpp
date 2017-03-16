#include <cstdio>
#include <cstring>

using namespace std;

bool ok[10];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;scanf("%d",&test);
	for (int T=1;T<=test;T++)
	{
		int n;scanf("%d",&n);
		printf("Case #%d: ",T);
		if (!n) {puts("INSOMNIA");continue;}
		memset(ok,0,10*sizeof(bool));
		int i=1;
		while (1)
		{
			int t=i*n;
			while (t)
			{
				ok[t%10]=1;t/=10;
			}
			bool hhh=1;
			for (int j=0;j<10;j++) if (!ok[j]) {hhh=0;break;}
			if (hhh) break;
			i++;
		}
		printf("%d\n",i*n);
	}
	return 0;
}

