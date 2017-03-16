#include<stdio.h>
main()
{
	int t, y;
	scanf("%d",&t);
	y = t+1;
		int i, inh, j, x;
		static int A[1000][1000];
		int n;
	for(; t>0; t--)
	{
		scanf("%d",&n);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				A[i][j] = 0;
			scanf("%d",&inh);
			for(j=0; j<inh; j++)
			{
				scanf("%d",&x);
				A[i][x-1] = 1;
			}
		}
		int possible;
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				possible = find_poss(A,i,j,n);
				if(possible > 1)
				{
					printf("Case #%d: Yes\n",(y-t));
					break;
				}
			}
			if(possible>1) break;
		}
		if(possible <= 1)
		{
			printf("Case #%d: No\n",(y-t));
		}

	}
}

int find_poss(int A[1000][1000], int i, int j, int n)
{
	if(i==j) return 1;
	int x, p = 0;
	for(x = 0; x<n; x++)
	{
		if(A[i][x] == 1)
			p += find_poss(A,x,j,n);
	}
	return p;
}
