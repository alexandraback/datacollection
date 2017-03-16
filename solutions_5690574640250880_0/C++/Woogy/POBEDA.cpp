#include <iostream>
#include <stdio.h>
using namespace std;
#pragma warning(disable : 4996)
char matr[7][7];

bool flag[7][7];
int r, c, m;
void prov(int x,int y)
{
	if (flag[x][y]) return;
	flag[x][y] = true;
	if ((matr[x + 1][y] == '.') && (matr[x][y + 1] == '.') && (matr[x + 1][y + 1] == '.') && (matr[x - 1][y] == '.') && (matr[x][y - 1] == '.') && (matr[x - 1][y - 1] == '.'))
	{
		if (x != 1)
		{
			prov(x - 1, y);
		}
		if (y != 1)
		{
			prov(x, y-1);
		}
		if (x != c)
		{
			prov(x + 1, y);
		}
		if (y != r)
		{
			prov(x, y+1);
		}
		if ((y != r) && (x != c))
		{
			prov(x+1, y + 1);
		}
		if ((y != 1) && (x != 1))
		{
			prov(x-1, y - 1);
		}
	}
}



int main()
{
	int T;
	bool flag1;
	int row1[4], otvet,m1;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{

		for (int j = 0; j < 7; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				matr[j][k] = '.';
				flag[j][k] = false;
			}
		}

		scanf_s("%d%d%d", &r, &c, &m);
		m1 = m;
		if (m == 0)
		{
			flag1 = true;
			matr[1][1] = 'c';
		}
		else
		{
			if ((c*r) == (m + 1))
			{
				flag1 = false;
				for (int k = 1; k <= r; k++)
				{
					for (int j = 1; j <= c; j++)
					{
						matr[j][k] = '*';
					}
				}
				flag1 = true;
				matr[1][1] = 'c';

			}
			else
			{
				if ((c == 1) || (r == 1))
				{
					flag1 = true;
					if (c == 1)
					{
						for (int k = r; k > 0; k--)
						{
							if (m > 0)
							{
								m--;
								matr[1][k] = '*';
							}
						}
					}
					if (r == 1)
					{
						for (int k = c; k > 0; k--)
						{
							if (m > 0)
							{

								m--;
								matr[k][1] = '*';
							}
						}
					}
					matr[1][1] = 'c';
				}
				else
				{
						for (int j = c; j > 0; j--)
						{
							for (int k = r; k > 0; k--)
							{
								if ((m == 1) && (k == 2))
								{
									m = 0;
									matr[j - 1][r] = '*';
								}
								else
								{
									if (m > 0)
									{
										matr[j][k] = '*';
										m--;
									}
								}

							}
						}
						flag1 = true;

						
							prov(1, 1);
							matr[1][1] = 'c';
					
						for (int j = 1; j <= c; j++)
						{
							for (int k = 1; k <= r; k++)
							{
								if ((flag[j][k] == false) && (matr[j][k] == '.'))
								{
									flag1 = false;
								}
							}
						}
					
					// YPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPIIIII
					if (flag1 == false)
					{
						m = m1;
						for (int j = 0; j < 7; j++)
						{
							for (int k = 0; k < 7; k++)
							{
								matr[j][k] = '.';
								flag[j][k] = false;
							}
						}

						for (int j = r; j > 0; j--)
						{
							for (int k = c; k > 0; k--)
							{
								if ((m == 1) && (k == 2))
								{
									m = 0;
									matr[c][j - 1] = '*';
								}
								else
								{
									if (m > 0)
									{
										matr[k][j] = '*';
										m--;
									}
								}

							}
						}
						flag1 = true;

						
							prov(1, 1);
							matr[1][1] = 'c';
						
						for (int j = 1; j <= c; j++)
						{
							for (int k = 1; k <= r; k++)
							{
								if ((flag[j][k] == false) && (matr[j][k] == '.'))
								{
									flag1 = false;
								}
							}
						}
						// YPOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
					}
					// YPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPIIIII
					if ((flag1 == false) && (r > 3) && (c > 3))
					{
						m = m1;
						for (int j = 0; j < 7; j++)
						{
							for (int k = 0; k < 7; k++)
							{
								matr[j][k] = '.';
								flag[j][k] = false;
							}
						}

						for (int j = r; j > 3; j--)
						{
							for (int k = c; k > 0; k--)
							{

								if (m > 0)
								{
									matr[k][j] = '*';
									m--;
								}


							}
						}
						for (int j = c; j > 3; j--)
						{
							for (int k = r; k > 0; k--)
							{
								if ((m > 0) && matr[j][k] != '*')
								{
									matr[j][k] = '*';
									m--;
								}


							}
						}
						// chto-to
						for (int j = 3; j > 0; j--)
						{
							for (int k = 3; k > 0; k--)
							{
								if ((m == 1) && (k == 2))
								{
									m = 0;
									matr[3][1] = '*';
								}
								else
								{
									if (m > 0)
									{
										matr[k][j] = '*';
										m--;
									}
								}

							}
						}
						flag1 = true;

						
							prov(1, 1);
							matr[1][1] = 'c';
						
						for (int j = 1; j <= c; j++)
						{
							for (int k = 1; k <= r; k++)
							{
								if ((flag[j][k] == false) && (matr[j][k] == '.'))
								{
									flag1 = false;
								}
							}
						}
						// YPOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
					}
				}
			}
		}

		if (flag1 == false)
		{
			printf("Case #%d:\n", i);
			printf("Impossible\n");
			
		}
		else
		{
			printf("Case #%d:\n", i);
			for (int k = 1; k <= r; k++)
			{
				for (int j = 1; j <= c; j++)
				{
					printf("%c", matr[j][k]);
				}
				printf("\n");
			}
		}
	}
	}

