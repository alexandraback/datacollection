#include<cstdio>
#include<cassert>
using namespace std;
bool VIS[10];
int N,CNT;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int testcount;scanf("%d",&testcount);
	while(testcount--)
//	for(int testindex=0;testindex<=testcount;testindex++)
	{
		scanf("%d",&N);
		static int kase=1;
		printf("Case #%d: ",kase++);
//		N=testindex;
		if(N==0){puts("INSOMNIA");continue;}
		for(int i=0;i<10;i++)VIS[i]=false;
		CNT=10;
		for(int i=1;;i++)
		{
			int n=N*i;
			for(;n;n/=10)if(!VIS[n%10])
			{
				VIS[n%10]=true,CNT--;
			}
			if(CNT==0)
			{
				printf("%d\n",N*i);
				break;
			}
		}
	}
	return 0;
}
