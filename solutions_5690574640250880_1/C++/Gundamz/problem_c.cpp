#include <stdio.h>

#define MAXSIZE 51

int min(int a, int b)
{
	return a < b ? a : b;
}

// 0 means dot -1 means c 1 means mine
int matrix[MAXSIZE][MAXSIZE];

int main()
{
	// initial
	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
			matrix[i][j] = 0;
	int num_of_test;
	FILE *f = fopen("C-large.in", "r");
	FILE *out = fopen("C-large.out", "w");
	fscanf(f, "%d", &num_of_test);
	int R, C, M;
	for (int i = 1; i <= num_of_test; i++)
	{
		fscanf(f, "%d %d %d", &R, &C, &M);
		for (int m = 0; m < R; m++)
			for (int n = 0; n < C; n++)
				matrix[m][n] = 1;
		int smaller = min(R, C);
		int count = 0;
		// 有1长度则必定有解
		if (smaller == 1 || R*C-M == 1)
		{
			for (int m = 0; m < R; m++)
			{
				for (int n = 0; n < C; n++)
				{
					if (count >= R*C-M)
						break;
					matrix[m][n] = 0;
					count++;
				}
			}
			matrix[0][0] = -1;
		}
		else if (smaller == 2)
		{
			// 奇数
			if ((R*C-M)%2==1 || R*C-M == 2)
			{
				fprintf(out, "Case #%d:\n", i);
				fprintf(out, "Impossible\n");
				// 跳过接下来的循环
				continue;
			} 
			else //偶数
			{
				// 行为2
				if (R == 2)
				{
					for (int n = 0; n < C; n++)
					{
						for (int m = 0; m < R; m++)
						{
							if (count >= R*C-M)
								break;
							matrix[m][n] = 0;
							count++;
						}
					}
					matrix[0][0] = -1;
				}
				else // 列为2
				{
					for (int m = 0; m < R; m++)
					{
						for (int n = 0; n < C; n++)
						{
							if (count >= R*C-M)
								break;
							matrix[m][n] = 0;
							count++;
						}
					}
					matrix[0][0] = -1;
				}
			}
		}
		else // 最短的行列数也是大等于3
		{
			// 如果剩余为2或不能分解为2个三以上和偶数的组合的
			if (R*C-M == 2 ||R*C-M == 3 || R*C-M == 5 || R*C-M == 7)
			{
				fprintf(out, "Case #%d:\n", i);
				fprintf(out, "Impossible\n");
				// 跳过接下来的循环
				continue;
			}
			// 如果和小于2倍的smaller，就只有自己构建
			// 若和大于2倍的smaller，就可以填满smaller，如果余下了1，就补一下
			if (R*C-M < 3 * smaller)
			{
				if ((R*C-M) % 3 == 0 || (R*C-M) % 3 == 2)
				{
					for (int m = 0; m < R; m++)
					{
						for (int n = 0; n < 3; n++)
						{
							if (count >= R*C-M)
								break;
							matrix[m][n] = 0;
							count++;
						}
					}
					matrix[0][0] = -1;
				}
				else // == 1 最后部分削成2*2即可
				{
					for (int m = 0; m < R; m++)
					{
						for (int n = 0; n < 3; n++)
						{
							if (count >= R*C-M)
								break;
							matrix[m][n] = 0;
							count++;
						}
					}
					int tmp_x = (R*C-M) / 3;
					int tmp_y = (R*C-M) - tmp_x * 3 - 1;
					// printf("%d, %d, %d\n", R, C, M);
					// printf("%d, %d\n", tmp_x, tmp_y);
					matrix[tmp_x][tmp_y+1] = 0;
					matrix[tmp_x-1][2] = 1;
					matrix[0][0] = -1;
				}
			}
			else // >= 3*smaller
			{
				if (R >= C)
				{
					for (int m = 0; m < R; m++)
					{
						for (int n = 0; n < C; n++)
						{
							if (count >= R*C-M)
								break;
							matrix[m][n] = 0;
							count++;
						}
					}
					int tmp_x = (R*C-M) / C;
					int tmp_y = (R*C-M) - tmp_x * C - 1;
					if (tmp_y == 0)
					{
						matrix[tmp_x][tmp_y+1] = 0;
						matrix[tmp_x-1][C-1] = 1;
					}
					matrix[0][0] = -1;
				}
				else
				{
					for (int n = 0; n < C; n++)
					{
						for (int m = 0; m < R; m++)
						{
							if (count >= R*C-M)
								break;
							matrix[m][n] = 0;
							count++;
						}
					}
					int tmp_y = (R*C-M) / R;
					int tmp_x = (R*C-M) - tmp_y * R - 1;
					if (tmp_x == 0)
					{
						matrix[tmp_x+1][tmp_y] = 0;
						matrix[R-1][tmp_y-1] = 1;
					}
					matrix[0][0] = -1;
				}
			}
		}
		fprintf(out, "Case #%d:\n", i);
		for (int m = 0; m < R; m++)
		{
			for (int n = 0; n < C; n++)
			{
				if (matrix[m][n] == 0)
					fprintf(out, ".");
				else if (matrix[m][n] == 1)
					fprintf(out, "*");
				else
					fprintf(out, "c");
			}
			fprintf(out, "\n");
		}
	}
	fclose(f);
	fclose(out);
}