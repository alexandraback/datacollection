#include<stdio.h>
int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		int n,m,k,out=0;
		scanf("%d%d%d",&n,&m,&k);
		if(m==k)
			out=k;
		else
		{
			for(;k<(m+1)/2;m-=k,out++);
			//printf("ch=%d\n",out);
			out+=k+1;
		}
		printf("Case #%d: %d\n",a,out);
	}
}
