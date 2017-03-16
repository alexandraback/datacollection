#include <stdio.h>

int CL[50][50];
int main()
{
	int T,i,R,C,W,j,y;
	scanf("%d",&T);

	for(i = 0; i <= 20; ++i)
		for(j = 0; j <= 20; ++j)
			CL[i][j] = 0;

	for(i = 1; i <= 20; ++i)
	{
		CL[1][i] = i;
		CL[i][i] = i;
	}

	for(i = 1; i <= 20; ++i)
	{
		for(j = i+1; j <= (2*i) && j <= 20; ++j)
			CL[i][j] = i+1;

		for(j = (2*i)+1; j <= 20; ++j)
			CL[i][j] = 1+CL[i][j-i];
	}

	int ans;
	for(i = 1; i <= T; ++i)
	{
		scanf("%d", &R);
		scanf("%d", &C);
		scanf("%d", &W);

		ans = 0;

		if(R == 1) printf("Case #%d: %d\n",i, CL[W][C]);
		else
		{
			if(C == W) ans = R-1+W;
			else if(W == 1) ans = R*W;
			else if(C == (2*W))
				ans = (2*R) + W -1;
			else if(C < (2*W))
				ans = R+W;
			else
			{
				ans = (R*(CL[W][C]-W-1));
				y = C-(W*(CL[W][C]-W-1));
				if(y == W) ans += R-1+W;
				else if(y == 1) ans += R;
				else
				{
					if(y % 2)
						ans += R+W;
					else
						ans += (2*R) + W -1;
				}
			}

			printf("Case #%d: %d\n", i,ans);
		}
	}

	return 0;
}