#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
int p[1000][10];

bool seq[6][6][6][1000];
int ans[1000][4];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for(int i = 2; i <= 5; ++i)
	{
		for(int j = 2; j <= 5; ++j)
		{
			for(int k = 2; k <= 5; ++k)
			{
				seq[i][j][k][1] = true;
				seq[i][j][k][i] = true;
				seq[i][j][k][j] = true;
				seq[i][j][k][k] = true;
				seq[i][j][k][i * j] = true;
				seq[i][j][k][i * k] = true;
				seq[i][j][k][j * k] = true;
				seq[i][j][k][i * j * k] = true;
			}
		}
	}
	printf("Case #1:\n");
	for(int i = 1; i <= T; ++i)
	{
		int r, n, m, k;
		scanf("%d%d%d%d", &r, &n, &m, &k);
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < k; ++j)
				scanf("%d", &p[i][j]);
		for(int i = 0; i < r; ++i)
		{
			for(int a1 = 2; a1 <= m; a1++)
				for(int a2 = 2; a2 <= m; ++a2)
					for(int a3 = 2; a3 <= m; ++a3)
					{
						bool succ = true;
						for(int s = 0; s < k; ++s)
						{
							if(!seq[a1][a2][a3][p[i][s]])
							{
								succ = false;
								break;
							}
						}
						if(succ)
						{
							printf("%d%d%d\n", a1, a2, a3);
							goto end;
						}
					}
			end:
			;
		}
	}
	
	fclose(stdout);
	fclose(stdin);
	return 0;
}