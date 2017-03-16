#include <stdio.h>

int nm[10] = {2, 3, 4, 5};
int sts[1000][10];
int len[1000];
int nst[10], nstl;
int ct;
int R, N, M, K;

void DFS(int dep)
{
	int i;
	if(dep == N)
	{
		
		for(i = 0 ; i < nstl ; i++)
		{
			sts[ct][i] = nst[i];
		}
		len[ct] = nstl;
		ct++;
		return;
	}
	for(i = 0 ; i < M ; i++)
	{
		nst[nstl++] = nm[i];
		DFS(dep+1);
		nstl--;
	}
	DFS(dep+1);
}

bool chk(int ni, int num)
{
	int i, l = len[ni];
	for(i = 0 ; i < l ; i++)
	{
		if((num%sts[ni][i]) == 0)
		{
			num /= sts[ni][i];
		}
	}
	if(num == 1) return true;
	return false;
}

void print(int ni)
{
	int i, l = len[ni];
	for(i = 0 ; i < l ; i++)
	{
		printf("%d", sts[ni][i]);
	}
	printf("\n");
}

int main()
{
	freopen("C-small-1-attempt1.in", "r", stdin);
	freopen("outc2.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		
		scanf("%d%d%d%d", &R, &N, &M, &K);
		nstl = 0;
		ct = 0;
		M--;
		DFS(0);

		int i, j, k;
		//printf("%d\n", ct);
		/*for(i = 0 ; i < ct ; i++)
		{
			for(j = 0 ; j < len[i] ; j++)
			{
				printf("%d ", sts[i][j]);
			}
			printf("\n");
		}*/
		printf("Case #1:\n");
		for(i = 1 ; i <= R ; i++)
		{
			int ck[10];
			for(j = 1 ; j <= K ; j++)
			{
				scanf("%d", &ck[j]);
			}	
			for(j = 0 ; j < ct ; j++)
			{
				bool yes = true;
				for(k = 1 ; k <= K ; k++)
				{
					if(chk(j, ck[k]) == false)
					{
						yes = false;
						break;
					}
				}
				if(yes == true)
				{
					print(j);
					break;
				}
			}
		}
	}

	return 0;
}
