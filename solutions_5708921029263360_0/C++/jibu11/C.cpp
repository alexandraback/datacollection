#include <stdio.h>
#include <string.h>

int j, p, s, k, ans = 0, a11[30][3], mc[30][3];
int mat1[4][4], mat2[4][4], mat3[4][4];

void brute(int ccj, int ccp, int ccs, int cur)
{
	if(ccj == j + 1)
	{
		if(cur > ans)
		{
			ans = cur;
			int i;
			for(i = 0; i < cur; i++)
			{
				a11[i][0] = mc[i][0];
				a11[i][1] = mc[i][1];
				a11[i][2] = mc[i][2];
			}
		}
		return;
	}
	if(ccp == p + 1)
	{
		brute(ccj + 1, 1, 1, cur);
		return;
	}
	if(ccs == s + 1)
	{
		brute(ccj, ccp + 1, 1, cur);
		return;
	}
	if(mat1[ccj][ccp] < k && mat2[ccj][ccs] < k && mat3[ccp][ccs] < k)
	{
		mat1[ccj][ccp]++; 
		mat2[ccj][ccs]++;
		mat3[ccp][ccs]++;
		mc[cur][0] = ccj;
		mc[cur][1] = ccp;
		mc[cur][2] = ccs;
		brute(ccj, ccp, ccs + 1, cur + 1);
		mat1[ccj][ccp]--; 
		mat2[ccj][ccs]--;
		mat3[ccp][ccs]--;
	}
	brute(ccj, ccp, ccs + 1, cur);
}

int main()
{
	int t, l;
	scanf("%d", &t);
	for(l = 0; l < t; l++)
	{
		scanf("%d%d%d%d", &j, &p, &s, &k);
		/*if(k >= s)
		{
			printf("Case #%d: %d\n", l + 1, j * p * s);
			int i1, i2, i3;
			for(i1 = 1; i1 <= j; i1++)
				for(i2 = 1; i2 <= p; i2++)
					for(i3 = 1; i3 <= s; i3++)
						printf("%d %d %d\n", i1, i2, i3);
		}*/
	//	else
	//	{
			ans = 0;
			memset(a11, 0, sizeof a11);
			memset(mat1, 0, sizeof mat1);
			memset(mat2, 0, sizeof mat2);
			memset(mat3, 0, sizeof mat3);
			brute(1, 1, 1, 0);
			printf("Case #%d: %d\n", l + 1, ans);
			for(int i = 0; i < ans; i++)
				printf("%d %d %d\n", a11[i][0], a11[i][1], a11[i][2]);
	//	}
	}
	return 0;
}
