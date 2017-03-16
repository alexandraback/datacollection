#include<cstdio>
int ar[10];
using namespace std;
void mark(int x)
{
	
	while(x)
	{
		int t=x%10;
		ar[t]=1;
		x=x/10;
	}
}
int check()
{
	for(int i=0;i<10;i++) if(ar[i]==0) return 0;
	return 1;
}
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		int f=0;
		for(int i=0;i<10;i++) ar[i]=0;
		int N; scanf("%d",&N);
		if(N==0)
		{
			printf("INSOMNIA\n");
			continue;
		}
		for(int t=1;t<100;t++)
		{
			mark(t*N);
			if(check())
			{
				 f=1;
				printf("%d\n",t*N); break;
			}
		}
		if(!f) printf("INSOMNIA\n");
	}
}
