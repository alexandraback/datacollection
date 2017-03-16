#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main()
{
	 int T,r,t,T1;
	 int ans = 0,temp;

	T = 1;
	for(scanf("%d",&T1); T <= T1; T++)
	{	scanf("%d%d",&r,&t);
		ans = 0;
		temp = 1 + 2*r;
		while(temp <= t)
		{	ans ++;
			r += 2;
			temp += 1 + 2*r;	
		}
		printf("Case #%d: %d\n",T,ans);
	}

	return 0;
}
