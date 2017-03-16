#include<cstdio>
#include<cstring>

char sol[55][55];

int main()
{
	int T; scanf("%d", &T);
	for(int ii = 0; ii < T; ii++)
	{
		int R, C, M; scanf("%d%d%d", &R, &C, &M);
		int L = R*C-M;
		if(R == 1 || C == 1)
		{
			int c = R*C-M;
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
				{
					if(!c) sol[i][j] = '*';
					else
					{
						sol[i][j] = '.';
						c--;
					}
				}
				sol[i][C] = 0;
			}
			sol[0][0] = 'c';
			printf("Case #%d:\n", ii+1);
			for(int i = 0; i < R; i++)
			printf("%s\n", sol[i]);
		}
		else if(R == 2 || C == 2)
		{
			if(R*C-M == 1)
			{
				printf("Case #%d:\n",ii+1);
				for(int i = 0; i < R; i++)
				{
					for(int j = 0; j < C; j++)
						sol[i][j] = '*';
					sol[i][C] = 0;
					sol[0][0] = 'c';
					printf("%s\n", sol[i]);
				}
			}
			else if(M%2 || R*C-M == 2)
				printf("Case #%d:\nImpossible\n",ii+1);
			else
			{
				printf("Case #%d:\n",ii+1);
				if(R == 2)
				{
					for(int _ = 0; _ < 2; _++)
					{
						for(int j = 0; j < C; j++)
							if(_ == 0 && j == 0)
								printf("c");
							else if(j<C-M/2)
								printf(".");
							else
								printf("*");
						printf("\n");
					}
				}
				else
				{
					for(int i = 0; i < R; i++)
						if(i<R-M/2)
							printf("%c.\n",i?'.':'c');
						else
							printf("**\n");
				}
			}
		}
		else if(L == 2 || L == 3 || L == 5 || L == 7)
			printf("Case #%d:\nImpossible\n",ii+1);
		else if(L == 1)
		{
			printf("Case #%d:\n",ii+1);
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
					printf("%c",(i||j)?'*':'c');
				printf("\n");
			}
		}
		else
		{
			for(int i = 0; i < R; i++)
			{
				memset(sol[i],'*',sizeof(sol[i]));
				sol[i][C] = 0;
			}
			L-=4;
			sol[0][0] = 'c';
			sol[0][1] = sol[1][0] = sol[1][1] = '.';
			//init
			if(L)
			{
				L-=2;
				sol[0][2] = sol[1][2] = '.';
			}
			if(L)
			{
				L-=2;
				sol[2][0] = sol[2][1] = '.';
			}
			for(int i = 3; i < C && L >= 2; i++)
			{
				L-=2;
				sol[0][i] = sol[1][i] = '.';
			}
			for(int i = 3; i < R && L >= 2; i++)
			{
				L-=2;
				sol[i][0] = sol[i][1] = '.';
			}
			int posr = 2, posc = 2;
			while(L)
			{
				L--;
				sol[posr][posc] = '.';
				posc++; if(posc >= C) {posc = 2; posr++;};
			}
			printf("Case #%d:\n", ii+1);
			for(int i = 0; i < R; i++)
				printf("%s\n",sol[i]);
		}
	}
	return 0;
}
