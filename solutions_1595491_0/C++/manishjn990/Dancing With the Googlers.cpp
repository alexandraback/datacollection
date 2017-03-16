#include<cstdio>
#include<cstring>
#include<cstdlib>
int main()
{
	int ans,T,N,S,p,arr[105]={0},i,j,k,temp,a,b,c,ca=0;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;ca++;
		scanf("%d%d%d",&N,&S,&p);
		for(i=1;i<=N;i++)
		{
			scanf("%d",&temp);
			if(temp%3==0)
			{
				a=temp/3;
				if(a>=p)ans++;
				else if(a==(p-1) && S>0 && a!=0)
				{
					ans++;S--;
				}
			}
			else if(temp%3==1)
			{
				a=temp/3;
				a++;
				if(a>=p)ans++;
			}
			else 
			{
				a=temp/3;
				a++;
				if(a>=p)ans++;
				else if(a==(p-1) && S>0)
				{
					ans++;S--;
				}
			}
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}