#include <stdio.h>
 
int main(void) {
	// your code goes here
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int r,c,w,t,j,ans;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%d%d%d",&r,&c,&w);
		if(w==1)
		ans=r*c;
		else if(w==c)
		ans=r+w-1;
		else
		{
			if(c%w==0)
			ans=c/w*r+w-1;
			else
			ans=c/w*r+w;
		}
		printf("Case #%d: %d\n",j,ans);
	}
	return 0;
}
