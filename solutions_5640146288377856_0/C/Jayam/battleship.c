#include<stdio.h>
int main()
{
	int t,T,r,c,w,ans;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d %d %d",&r,&c,&w);
		ans=((c/w)*r)+w;
		if(c%w==0)
			ans--;
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
