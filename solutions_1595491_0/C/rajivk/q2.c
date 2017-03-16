#include<stdio.h>
int main()
{
	int t, T, i, N, S, p, input, ans;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		ans=0;
		scanf("%d %d %d", &N, &S, &p);
		if(p==0)
		{
			ans=N;
			for(i=0;i<N;i++)
				scanf("%d", &input);
		}
		else if(p==1)
		{
			for(i=0;i<N;i++)
			{
				scanf("%d", &input);
				if(input)
					ans++;
			}
		}
		else
		{
			for(i=0;i<N;i++)
			{
				scanf("%d", &input);
				if(input>3*p-3)
					ans++;
				else if(input>3*p-5 && S)
				{
					ans++;
					S--;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
