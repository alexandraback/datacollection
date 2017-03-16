#include<stdio.h>
#include<algorithm>
int aaa[110];
int main(){
	freopen("PA2.in","r",stdin);
	freopen("PA2.txt","w",stdout);
	int T,n,j,now,ti,ans,k;
	scanf("%d",&T);
	for(j=1;j<=T;j++)
	{
		ti=0,ans=110;
		scanf("%d%d",&now,&n);
		for(k=1;k<=n;k++)
		{
			scanf("%d",&aaa[k]);
		}
		if(now==1)
		{
			ans=n;
			goto AAA;
		}
		std::sort(aaa+1,aaa+n+1);
		for(k=1;k<=n;k++)
		{
			if(now<=aaa[k])
			{
				ans=std::min(ans,n-k+1+ti);
				while(now<=aaa[k])
				{
					ti++;
					now=2*now-1;
				}
				now+=aaa[k];
			}
			else
			{
				now=now+aaa[k];
			}
		}
		ans=std::min(ans,ti);
		AAA:;
		printf("Case #%d: %d\n",j,ans);
	}
}
				
