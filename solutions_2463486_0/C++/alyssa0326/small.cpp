#include<cstdio>
#include <cmath>
#include<cstring>
using namespace std;
bool ok[1001];
void run()
{
	int A,B;
	scanf("%d %d\n",&A,&B);
	int ret=0;
	for (int i = A;i<=B;i++)
		if(ok[i])
			ret++;
	printf("%d",ret);
}
int main()
{
	int N;
	scanf("%d\n",&N);
	memset(ok,0,sizeof(ok));
	for(int i = 0 ;i <1000;i++)
	{
		int k = sqrt(i);
		if (k*k==i)
		{
			if(i/10==0)
			{
				ok[i] = true;
			}
			else if (i/100==0 )
			{
				if (i%10==i/10)
					ok[i] = true;
			}
			else
			{
				if(i%10==i/100)
					ok[i]= true;
			}
		}
	}
	ok[676] = false;
	for (int Case = 1 ; Case <= N ; Case++)
	{
		printf("Case #%d: ",Case);
		run();
		putchar('\n');
	}
	return 0;
}
