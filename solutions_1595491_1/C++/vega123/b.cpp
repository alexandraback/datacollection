#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,i;
	int N,S,p,x;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		
		
		scanf("%d%d%d",&N,&S,&p);
		int ans=0;
		while(N--)
		{
			scanf("%d",&x);
			if(p==1)
			{
				if(x>0)ans++;
			}
			else if((x==(p-2)*3+2) || (x==(p-2)*3+3)){
				ans++;
				S--;
			}
			else if(x>(p-2)*3+3)
			{
				ans++;
			}
			
		}
		printf("Case #%d: ",i);
		if(S<0)ans+=S;
		printf("%d\n",ans);

	}
}