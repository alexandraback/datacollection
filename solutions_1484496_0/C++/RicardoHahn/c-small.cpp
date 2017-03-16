#include <stdio.h>
#include <map>

using namespace std;

#define MAX 21

#define ison(i,a) ((a)&(1<<(i)))

int main()
{
	int t;

	scanf("%d",&t);

	for(int tcnt = 1; tcnt <= t; ++tcnt)
	{
		int n;
		scanf("%d",&n);
		int i;

		int v[MAX];
		for(i=0; i<n; ++i)
			scanf("%d",&v[i]);

		map<int,int> mapa;

		printf("Case #%d:\n",tcnt);

		int lim = 1<<n;
		for(i=1;  i<lim; ++i)
		{
			int s = 0;
			for(int j=0; j<n; ++j)
				if(ison(j,i))
					s+=v[j];
			if(mapa.count(s) > 0)
			{
				bool pr = false;
				for(int j=0; j<n;++j)
					if(ison(j,i))
					{
						if(pr)
							printf(" ");
						printf("%d",v[j]);
						pr=true;
					}
				printf("\n");
				i = mapa[s];
				pr=false;
				for(int j=0; j<n;++j)
					if(ison(j,i))
					{
						if(pr)
							printf(" ");
						printf("%d",v[j]);
						pr=true;
					}
				printf("\n");
				break;
			}
			mapa[s] = i;
		}
		if(i>=lim)
			printf("Impossible\n");
	}
	return 0;
}

