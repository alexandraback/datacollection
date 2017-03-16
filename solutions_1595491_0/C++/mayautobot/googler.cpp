#include<stdio.h>
int main()
{
	int test,num,N,S,qut,rem,t,p,ans,i;
	int arr[30];
	scanf("%d",&test);
	for(t=0;t<test;t++)
	{
		scanf("%d",&N);
		scanf("%d",&S);
		scanf("%d",&p);
		ans=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&num);
			rem=num%3;
			qut=num/3;
    			if(rem==2)
			{
				if((qut+1)>=p)
				{ans++;}
				else if(S>0 && (qut+2)>=p)
				{ans++;S--;}
			}
			else if(rem==1 && (qut+rem)>=p)
			{
				ans++;
			}
			else if(rem==0)
			{
				if(qut>=p)
				{ans++;}
				else if(S>0 && num!=0 && (qut+1)>=p)
				{ans++;S--;}
			}
		}
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}
