#include<stdio.h>
int main()
{
	int t,cases,n,s,p,score,i,ans;
	scanf("%d",&t);
	for(cases=1;cases<=t;cases++)
	{
		scanf("%d %d %d",&n,&s,&p);
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&score);
			if((score%3)==1)
			{
				if(score/3+1>=p)
					ans++;
			}
			else if((score%3)==0)
			{
				if(score/3>=p)
					ans++;
				else if(score>=3 && s>0 && score/3+1>=p)
				{
					s--;
					ans++;
				}
			}
			else
			{
				if(score/3+1>=p)
					ans++;
				else if(s>0 && score/3+2>=p)
				{
					s--;
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n",cases,ans);
	}
	return 0;
}

			
	
