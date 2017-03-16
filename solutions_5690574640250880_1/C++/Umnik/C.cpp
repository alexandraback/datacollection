#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int t;
int h, w, m;
int a[100][100];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);
	for (int s = 1; s <= t; s++)
	{
		printf("Case #%d:\n", s);
		scanf("%d%d%d", &h, &w, &m);
		m = h * w - m;
		if (h == 1)
		{
			for (int i = 0; i < w; i++)
			{
				if (i == 0)
					printf("c");
				else if (i < m)
					printf(".");
				else
					printf("*");
			}
			printf("\n");
			continue;
		}
		if (w == 1)
		{
			for (int i = 0; i < h; i++)
			{
				if (i == 0)
					printf("c\n");
				else if (i < m)
					printf(".\n");
				else
					printf("*\n");
			}
			continue;
		}
		if (m == 1)
		{
			printf("c");
			for (int i = 1; i < w; i++)
				printf("*");
			printf("\n");
			for (int j = 1; j < h; j++)
			{
				for (int i = 0; i < w; i++)
					printf("*");
				printf("\n");
			}
			continue;
		}
		if (h == 2)
		{
			if (m % 2 == 1 || m == 2)
			{
				printf("Impossible\n");
				continue;
			}
			m /= 2;
			printf("c");
			for (int i = 1; i < w; i++)
			{
				if (i < m)
					printf(".");
				else
					printf("*");
			}
			printf("\n");
			for (int i = 0; i < w; i++)
			{
				if (i < m)
					printf(".");
				else
					printf("*");
			}
			printf("\n");
			continue;
		}
		if (w == 2)
		{
			if (m % 2 == 1 || m == 2)
			{
				printf("Impossible\n");
				continue;
			}
			m /= 2;
			printf("c.\n");
			for (int i = 1; i < h; i++)
			{
				if (i < m)
					printf("..\n");
				else
					printf("**\n");
			}
			continue;
		}
		if (m == 2 || m == 3 || m == 5 || m == 7)
		{
			printf("Impossible\n");
			continue;
		}
		if (m <= 2 * w)
		{
			if (m % 2 == 0)
			{
				m /= 2;
				printf("c");
				for (int i = 1; i < w; i++)
				{
					if (i < m)
						printf(".");
					else
						printf("*");
				}
				printf("\n");
				for (int i = 0; i < w; i++)
				{
					if (i < m)
						printf(".");
					else
						printf("*");
				}
				printf("\n");
				for (int i = 2; i < h; i++)
				{
					for (int j = 0; j < w; j++)
						printf("*");
					printf("\n");
				}
			}
			else
			{
				m -= 3;
				m /= 2;
				printf("c");
				for (int i = 1; i < w; i++)
				{
					if (i < m)
						printf(".");
					else
						printf("*");
				}
				printf("\n");
				for (int i = 0; i < w; i++)
				{
					if (i < m)
						printf(".");
					else
						printf("*");
				}
				printf("\n");
				printf("...");
				for (int j = 3; j < w; j++)
				{
					printf("*");
				}
				printf("\n");
				for (int i = 3; i < h; i++)
				{
					for (int j = 0; j < w; j++)
						printf("*");
					printf("\n");
				}
			}
		}
		else
		{
			if (m % w != 1)
			{
				int tmp = m / w;
				for (int i = 0; i < h; i++)
				{
					if (i == 0)
					{
						printf("c");
						for (int j = 1; j < w; j++)
							printf(".");
						printf("\n");
					}
					else if (i < tmp)
					{
						for (int j = 0; j < w; j++)
							printf(".");
						printf("\n");
					}
					else if (i == tmp)
					{
						for (int j = 0; j < w; j++)
						{
							if (j < m % w)
								printf(".");
							else
								printf("*");
						}
						printf("\n");
					}
					else
					{
						for (int j = 0; j < w; j++)
							printf("*");
						printf("\n");
					}
				}
			}
			else
			{
				int tmp = m / w;
				for (int i = 0; i < h; i++)
				{
					if (i == 0)
					{
						printf("c");
						if (m == 2 * w + 1)
						{
							for (int j = 1; j < w - 1; j++)
								printf(".");
							printf("*\n");
						}
						else
						{
							for (int j = 1; j < w; j++)
								printf(".");
							printf("\n");
						}
					}
					else if (i < tmp)
					{
						if (m == 2 * w + 1)
						{
							for (int j = 0; j < w - 1; j++)
								printf(".");
							printf("*\n");
						}
						else
						{
							for (int j = 0; j < w - 1; j++)
								printf(".");
							if (i == tmp - 1)
								printf("*\n");
							else
								printf(".\n");
						}
					}
					else if (i == tmp)
					{
						if (m == 2 * w + 1)
						{
							printf("...");
							for (int j = 3; j < w; j++)
								printf("*");
							printf("\n");
						}
						else
						{
							printf("..");
							for (int j = 2; j < w; j++)
								printf("*");
							printf("\n");
						}
					}
					else
					{
						for (int j = 0; j < w; j++)
							printf("*");
						printf("\n");
					}
				}
			}
		}
	}

	return 0;
}