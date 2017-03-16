#include<stdio.h>

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,R,C,W;
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		scanf("%d %d %d",&R, &C, &W);
		int guess_col = C / W;
		int ans=0;
		if(W==1)
			ans = R*C;
		else
		{
			if(C%W==0)
				ans = guess_col * R + W - 1;
			else
				ans = guess_col * R + W;
		}
		printf("Case #%d: %d\n",c,ans);
	}
}