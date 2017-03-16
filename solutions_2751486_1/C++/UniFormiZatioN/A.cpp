#include<stdio.h>
#define MAX 1000010
char S[MAX];
int N,C[MAX];
main()
{
//	freopen("A-large.in","r",stdin);
//	freopen("A-large-out.txt","w",stdout);
	int Test,Case,i,j,k;
	long long ans;
	scanf("%d",&Test);
	for(Case=1;Case<=Test;Case++)
	{
		scanf("%s %d",&S,&N);
		for(i=j=0;S[i];i++)
		{
			if(S[i]=='a' || S[i]=='e' || S[i]=='i' ||\
			S[i]=='o' || S[i]=='u') C[i]=j=0;
			else C[i]=++j;
		}
		ans=0;
		for(i=0,k=-1;S[i];i++)
		{
			if(C[i]>=N) k=i;
			if(k>=0) ans+=(k-N+2);
			if(ans<0) puts("------");
		}
		printf("Case #%d: %I64d\n",Case,ans);
	}
}
