//#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
	FILE *infile, *outfile;
	int i, j, c;
	int cases, A, B, digit, limit, pt, counter, total, flag;
	int temp, temparr[10];
	int *arr;
	//int googler[100];
	
	infile = fopen("C-large.in", "r");
	outfile = fopen("result.txt", "w");
	fscanf(infile, "%d", &cases);
	for (c = 0; c < cases; c++)
	{
		fscanf(infile, "%d %d", &A, &B);
		digit = 0;
		i = A;
		while (i != 0)
		{
			i /= 10;
			digit++;
		}
		limit = 1;
		for (i = 0; i < digit - 1; i++)
		{
			limit *= 10;
		}
		/////////////////////////
		//printf("%d %d %d\n", A, B, digit);
		arr = (int *)malloc(digit * sizeof(int));
		total = 0;
		for (i = A; i <= B; i++)
		{
			if (digit == 1)
			{
				break;
			}
			temp = i;
			counter = 0;
			for (j = 0; j < digit; j++)
			{
				temp = (temp % limit) * 10 + temp / limit;
				arr[j] = temp;
			}
			flag = 0;
			for (j = 0; j < digit; j++)
			{
				//printf("%d ", arr[j]);
				if (arr[j] >= A && arr[j] < i)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				continue;
			}
			
			sort(arr, arr + digit);
			/*
			for (j = 0; j < digit; j++)
			{
				printf("%d ", arr[j]);
			}
			printf("\n");
			*/
			
			pt = 0;
			for (j = 0; j < digit; j++)
			{
				if (arr[j] >= A && arr[j] <= B)
				{
					if (pt != 0)
					{
						if (arr[j] > temparr[pt - 1])
						{
							temparr[pt] = arr[j];
							pt++;
						}
					}
					else
					{
						temparr[pt] = arr[j];
						pt++;
					}
				}
			}
			pt = pt * (pt - 1);
			pt /= 2;
			total += pt;
			//fprintf(outfile, "%d\n", counter);
		}
		fprintf(outfile, "Case #%d: %d\n", c + 1, total);
	}
	
	fclose(infile);
	fclose(outfile);
	printf("done\n");
	return 0;
}
