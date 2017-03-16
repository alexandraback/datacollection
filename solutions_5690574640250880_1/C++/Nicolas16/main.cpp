#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int T;
	int M, R, C;
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d:\n", t);
		
		scanf("%d %d %d", &R, &C, &M);
		
		if(M == C*R-1)
		{
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
				{
					if(i == 0 && j == 0) printf("c");
					else printf("*");
				}
				printf("\n");
			}
		}
		else if(R == 1)
		{
			for(int i = 0; i < M; i++) printf("*");
			for(int i = M; i < C-1; i++) printf(".");
			printf("c\n");
		}
		else if(C == 1)
		{
			for(int i = 0; i < M; i++) printf("*\n");
			for(int i = M; i < R-1; i++) printf(".\n");
			printf("c\n");
		}
		else
		{
			int S = R*C-M;
			bool poss = true;
			
			if(S == 2 || S == 3 || S == 5 || S == 7)
			{
				printf("Impossible\n");
				poss = false;
			}
			else
			{
				bool mines[50][50];
				for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) mines[i][j] = true;
				
				// Remplir les deux premières lignes de pasmines : on en a S
				int K;
				if(S >= 2*C+2) K = C;
				else if(S == 2*C+1) K = C-1;
				else if(S == 2*C) K = C;
				else
				{
					if(S % 2 == 0)
					{
						K = S/2;
					}
					else
					{
						K = (S-3)/2;
					}
				}
				
				for(int j = 0; j < K; j++)
				{
					mines[0][j] = false;
					mines[1][j] = false;
				}
				
				S -= 2*K;
				
				for(int i = 2; i < R; i++)
				{
					if(S >= K+2 || S == K)
					{
						// K reste pareil
					}
					else if(S == K+1)
					{
						// On veut mettre K-1 et puis en mettre deux : possible que si K-1 >= 2 ==> K >= 3
						if(K <= 2)
						{
							printf("Impossible\n");
							poss = false;
						}
						else
						{
							K = K-1;
						}
					}
					else
					{
						K = S;
					}
					S -= K;
					for(int j = 0; j < K; j++)
					{
						mines[i][j] = false;
					}
				}
				
				if(S > 0)
				{
					printf("Impossible\n");
					poss = false;
				}
				
				if(poss)
				{
					for(int i = 0; i < R; i++)
					{
						for(int j = 0; j < C; j++)
						{
							if(i == 0 && j == 0) printf("c");
							else if(mines[i][j]) printf("*");
							else printf(".");							
						}
						printf("\n");
					}
				}
				
			}
		}
		
	}


	return 0;
}
