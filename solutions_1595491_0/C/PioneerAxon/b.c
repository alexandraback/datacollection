#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t,n,s,p,inp;
	int l,l1,tmp;
	int ans;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		ans=0;
		scanf("%d %d %d",&n,&s,&p);
		for(l1=0;l1<n;l1++)
		{
			scanf("%d",&inp);
			tmp = (p*3) - inp;
			if(tmp <= 2)
				ans++;
			else if(tmp <= 4 && s > 0 && (inp>0 || p == 0))
			{
				s--;
				ans++;
			}	
		}
		printf("Case #%d: %d\n",l+1,ans);
	}
	return 0;
}

