#include<stdio.h>

int main()
{
	FILE *fp1,*fp2;
	int i,t,r,c,w,ans;
	
	fp1=freopen("A-large.in","r",stdin);
	fp2=freopen("b.txt","w+",stdout);
	
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d",&r,&c,&w);
		
		ans=c/w+w;
		
		if(c%w==0)
			ans--;
			
		ans=r*ans;
			
		printf("Case #%d: %d\n",i+1,ans);
	}
	fclose(fp1);
	fclose(fp2);
}
