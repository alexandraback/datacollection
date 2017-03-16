#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int x,y;

void work()
{
	if(x>0)
	{
		while(x--) printf("WE"); 
	}
	else
	{
		while(x++) printf("EW");
	}
	if(y>0)
	{
		while(y--) printf("SN"); 
	}
	else
	{
		while(y++) printf("NS");
	}
	printf("\n"); 
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d", &x, &y);
		printf("Case #%d: ",i+1);
		work();
	}
	return 0;
}
