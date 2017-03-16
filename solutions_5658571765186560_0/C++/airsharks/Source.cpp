#include <stdio.h>

int main()
{
	int N;
	char t;
	scanf_s("%d", &N);
	FILE *fp;
	fopen_s(&fp, "out.out", "wt+");
	for (int Case = 1; Case <= N; Case++)
	{
		int X, R, C;
		scanf_s("%d %d %d", &X, &R, &C);
		switch (X)
		{
		case 1:
		{
			fprintf(fp, "Case #%d: GABRIEL\n", Case);
			printf("Case #%d: GABRIEL\n", Case);
			break;
		}
		case 2:
		{
			if (R*C%X != 0)
			{
				fprintf(fp, "Case #%d: RICHARD\n", Case);
				printf("Case #%d: RICHARD\n", Case);
			}
			else
			{
				if (R*C >= 2)
				{
					fprintf(fp, "Case #%d: GABRIEL\n", Case);
					printf("Case #%d: GABRIEL\n", Case);
				}
				else
				{
					fprintf(fp, "Case #%d: RICHARD\n", Case);
					printf("Case #%d: RICHARD\n", Case);
				}
			}
			break;
		}
		case 3:
		{
			if (R*C%X != 0)
			{
				fprintf(fp, "Case #%d: RICHARD\n", Case);
				printf("Case #%d: RICHARD\n", Case);
			}
			else
			{
				if (R*C >3 && R>1 && C>1)
				{
					fprintf(fp, "Case #%d: GABRIEL\n", Case);
					printf("Case #%d: GABRIEL\n", Case);
				}
				else
				{
					fprintf(fp, "Case #%d: RICHARD\n", Case);
					printf("Case #%d: RICHARD\n", Case);
				}
			}
			break;
		}
		case 4:
		{
			if (R*C%X != 0)
			{
				fprintf(fp, "Case #%d: RICHARD\n", Case);
				printf("Case #%d: RICHARD\n", Case);
			}
			else
			{
				if (R*C >= 12 && R > 2 && C > 2)
				{
					fprintf(fp, "Case #%d: GABRIEL\n", Case);
					printf("Case #%d: GABRIEL\n", Case);
				}
				else
				{
					fprintf(fp, "Case #%d: RICHARD\n", Case);
					printf("Case #%d: RICHARD\n", Case);
				}
			}
			break;
		}
		case 5:
		{
			if (R*C%X != 0)
			{
				fprintf(fp, "Case #%d: RICHARD\n", Case);
				printf("Case #%d: RICHARD\n", Case);
			}
			else
			{
				if (R*C >= 15 && R>3 && C>3)
				{
					fprintf(fp, "Case #%d: GABRIEL\n", Case);
					printf("Case #%d: GABRIEL\n", Case);
				}
				else
				{
					fprintf(fp, "Case #%d: RICHARD\n", Case);
					printf("Case #%d: RICHARD\n", Case);
				}
			}
		}
		case 6:
		{
			if (R*C%X != 0)
			{
				fprintf(fp, "Case #%d: RICHARD\n", Case);
				printf("Case #%d: RICHARD\n", Case);
			}
			else
			{
				if (R%X != 0 || C%X != 0)
				{
					if (R*C >= 24 && R >3 & C >3)
					{
						fprintf(fp, "Case #%d: GABRIEL\n", Case);
						printf("Case #%d: GABRIEL\n", Case);
					}
					else
					{
						fprintf(fp, "Case #%d: RICHARD\n", Case);
						printf("Case #%d: RICHARD\n", Case);
					}
				}
			}
			break;
		}
		default:
		{
			fprintf(fp, "Case #%d: RICHARD\n", Case);
			printf("Case #%d: RICHARD\n", Case);

			break;
		}
		}


	}
	fclose(fp);
	N = getchar();

}