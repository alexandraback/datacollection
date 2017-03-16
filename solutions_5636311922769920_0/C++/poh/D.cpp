#include<stdio.h>
int main()
{
	freopen("D small input.in","r",stdin);
	freopen("D small output.out","w",stdout);
	int n,i,j,k,c,s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    scanf("%d %d %d",&k,&c,&s);
	    printf("Case #%d: ",i);
	    for(j=1;j<=s;j++)
            printf("%d ",j);
        printf("\n");
	}
	return 0;
}
