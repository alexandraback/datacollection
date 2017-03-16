#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
int A[105][105];
int r, c, xx;
void printans0()
{
	int cnt = xx;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (cnt > 0)
			{
				printf("*");
				cnt--;
			} else
			{
				if (i == r - 1 && j == c - 1)
					printf("c");
				else
					printf(".");
			}
		}
		printf("\n");
	}

}
void printans1()
{
	int cnt = xx;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (cnt > 0)
			{
				printf("*");
				cnt--;
			} else
			{
				if (i == r - 1 && j == c - 1)
					printf("c");
				else
					printf(".");
			}
		}
		printf("\n");
	}

}
void printans2()
{
	int blank = r * c - xx;
	if (blank % 2 == 1 || blank == 2)
	{
		printf("Impossible\n");
	} else
	{
		if (r == 2)
		{
			for (int i = 0; i < r; i++)
			{
				int cnt=xx/2;
				for (int j = 0; j < c; j++)
				{
					if (cnt > 0)
					{
						printf("*");
						cnt--;
					} else
					{
						if (i == r - 1 && j == c - 1)
							printf("c");
						else
							printf(".");
					}
				}
				printf("\n");
			}
		}
		else
		if(c==2)
		{
			int cnt=xx;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (cnt > 0)
					{
						printf("*");
						cnt--;
					} else
					{
						if (i == r - 1 && j == c - 1)
							printf("c");
						else
							printf(".");
					}
				}
				printf("\n");
			}
		}

	}
}
void printans3()
{
	int blank = r * c - xx;
	int dline = min(blank / 2, c);
	for (int i = 0; i < dline; i++)
		A[0][i] = A[1][i] = 1;
	blank -= 2 * dline;
	int nowr = 2;
	int ans;
	if (r * c - xx <= 2 || r * c - xx == 3 || r * c - xx == 5
			|| r * c - xx == 7)
		ans = 0;
	else
		ans = 1;
	while (blank)
	{
		for (int i = 0; i < dline; i++)
		{
			A[nowr][i] = 1;
			blank--;
			if (blank == 0)
			{
				if (i == 0)
				{
					if (dline == 2)
					{
						ans = 0;
					} else
					{
						ans = 1;
						A[nowr - 1][dline - 1] = 0;
						A[nowr][i + 1] = 1;
						if(nowr==2)
						{
							A[nowr - 2][dline - 1] = 0;
							A[nowr][i + 2] = 1;
						}
					}
				} else
					ans = 1;
				break;
			}
		}
		nowr++;
	}
	if (r * c - xx <= 2 || r * c - xx == 3 || r * c - xx == 5
			|| r * c - xx == 7)
		ans = 0;
	if (ans == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (A[i][j] == 0)
					printf("*");
				else
				{
					if (i == 0 && j == 0)
						printf("c");
					else
						printf(".");
				}
			}
			printf("\n");
		}

	} else
		printf("Impossible\n");

}

int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int cas = 0;
	while (T--)
	{
		scanf("%d %d %d", &r, &c, &xx);
		printf("Case #%d:\n", ++cas);
		//cout << r << " " << c << " " << xx << endl;
		//cout<<cas<<endl;
		memset(A, 0, sizeof(A));
		if (r * c - xx == 1)
			printans0();
		else if (r == 1 || c == 1)
			printans1();
		else if (r == 2 || c == 2)
			printans2();
		else
			printans3();

	}
	return 0;
}
