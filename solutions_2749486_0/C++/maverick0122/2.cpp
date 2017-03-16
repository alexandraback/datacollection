#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int x,y;

int abs1(int x)
{
	if(x<0) return -x;
	return x;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",cnt);
		int i,j;
		for(i=0;i<abs1(x);i++)
		{
			if(x>0) printf("WE");
			else printf("EW");
		}
		for(i=0;i<abs1(y);i++)
		{
			if(y>0) printf("SN");
			else printf("NS"); 
		}
		printf("\n");
	} 
} 
