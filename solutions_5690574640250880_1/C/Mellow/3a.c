#include <stdio.h>
#include <string.h>
int R = 0;
int C = 0;
int M = 0;

int blank = 0;
int array[50][50];
int isImpossible = 1;
int q[2500];
int nR = 0;
int nC = 0;
int qNow = 1;
int qAdd = 4;
int i = 0;
int j = 0;
int main()
{
	FILE* fp = 0;
	if(0 == ( fp = freopen("cj3a.in", "w" ,stdout)))
   		 printf("Cannot open file.\n");
	int T = 0;
	scanf("%d",&T);

	for(int cT = 0; cT < T; cT ++)
	{
		scanf("%d%d%d", &R, &C, &M);
		blank = R * C - M ;
		isImpossible = 1;	
		memset(array, 0, sizeof(array));// 1 = . 0 = * -1 = c
		memset(q, 0, sizeof(q));
		if (!blank) // no mines
		{
			printf("Case #%d:\n", cT + 1);
			for ( i = 0; i < R; ++i)
			{
				for ( j = 0; j < C; ++j)
				{
					if (i && j)
					{
						printf(".");
					}else 
					{
						printf("c");
					}
				}
				printf("\n");
			}
			continue; 
		}
		if (R == 1 || C == 1)
		{
			if (R == 1)
			{
				for (i = 0; i < blank; ++i)
				{
					array[0][i] = 1;
				}
 			}else if (C == 1)
 			{
				for (i = 0; i < blank; ++i)
				{
					array[i][0] = 1;
				}
			}
 			array[0][0] = -1;
 			isImpossible = 0;
		}else if (blank == 1)
		{
			array[0][0] = -1;
			isImpossible = 0;
		}else if ((R == 2 || C == 2) && blank % 2)
		{
			
		}
		else if (blank > 4 )
		{

			if (blank != 5 && blank != 7)
			{
				array[0][0] = -1;
				array[0][1] = 1;
				array[1][1] = 3;
				array[1][0] = 2;
				q[0] = 0;
				q[1] = 1;
				q[2] = C;
				q[3] = C + 1;
				nR = 0;
				nC = 0;
				qNow = 1;
				qAdd = 4;
				while(qAdd < blank)
				{
					nR = (int)( q[qNow] / C );
					nC = q[qNow] % C;
					if (nC + 1< C )
					{
						if (qAdd + 1== blank && !nR)
						{
							//rid of last time effect
							qAdd --;
							// printf("%d %d %d\n",(int)( q[qAdd] / C ), q[qAdd] % C,qNow);
							array[(int)( q[qAdd] / C )][q[qAdd] % C] = 0;
							q[qAdd] = 0; 
							if (nC != 1)
							{
								continue;
							}else
							{
								break;
							}
						}
						if ( ! array[nR][nC + 1])
						{//left
							q[qAdd] = ( nR ) * C + nC + 1;
							array[nR][nC + 1] = qAdd;
							qAdd ++;
							if (qAdd == blank)
							{
								isImpossible = 0;
								break;
							}
						}
					}
					if (nR + 1 < R)
					{//down
						if (qAdd + 1== blank && !nC)
						{
							//rid of last time effect
							qAdd --;
							array[(int)( q[qAdd] / C )][q[qAdd] % C] = 0;
							q[qAdd] = 0; 
							if (nR != 1)
							{
								continue;
							}else
							{
								break;
							}
						}
						if (!array[nR + 1][nC])
						{
							q[qAdd] = ( nR + 1 ) * C + nC;
							array[nR + 1][nC] = qAdd;
							qAdd ++;	
							if (qAdd == blank)
							{
								isImpossible = 0;
								break;
							}
						}
					}
					if (nR + 1< R && nC + 1 < C)//left down
					{
						if (!array[nR + 1][nC + 1])
						{
							q[qAdd] = ( nR + 1 ) * C + nC + 1;
							array[nR + 1][nC + 1] = qAdd;
							qAdd ++;	
							if (qAdd == blank)
							{
								isImpossible = 0;
								break;
							}
						}
					}
					qNow ++;
				}			
			}
		}else if (blank == 4)
		{
			array[0][0] = -1;
			array[0][1] = 1;
			array[1][1] = 3;
			array[1][0] = 2;
			isImpossible = 0;
		}

		if (isImpossible)
		{
			printf("Case #%d:\nImpossible\n", cT + 1);
		}else{
			printf("Case #%d:\n", cT + 1);
			for (i = 0; i < R; ++i)
			{
				for (j = 0; j < C; ++j)
				{
					if (array[i][j] > 0)
					{
						printf(".");
					}else if (array[i][j] == 0)
					{
						printf("*");
					}else{
						printf("c");
					}
				}
				printf("\n");
			}
		}
	}
	fclose(fp);
}
