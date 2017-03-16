//#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int counter;

int main(int argc, char **argv)
{
	FILE *infile, *outfile;
	int i, j, k;
	int c, N, S, p;
	int googler[100], sur[100], top;
	
	infile = fopen("B-small-attempt0.in", "r");
	outfile = fopen("result.txt", "w");
	fscanf(infile, "%d", &c);
	for (i = 0; i < c; i++)
	{
		//case i
		j = 0;
		do
		{
			if (j == 0)
            {
				fscanf(infile, "%d", &N);
                j++;
            }
            else if (j == 1)
            {
                fscanf(infile, "%d", &S);
                j++;
            }
            else if (j == 2)
            {
                fscanf(infile, "%d", &p);
                j++;
            }
            else
            {
                fscanf(infile, "%d", googler + j - 3);
                j++;
            }
		} while (fgetc(infile) == ' ');
		///////////////////////////////////////////////
		counter = 0;
		top = 0;
		for (j = 0; j < N; j++)
		{
			if (googler[j] / 3 >= p)
			{
				counter++;
			}
			else if (googler[j] / 3 >= p - 1 && googler[j] % 3 > 0)
			{
				counter++;
			}
			else
			{
				sur[top] = googler[j];
				top++;
			}
		}
		//printf("%d\n", counter);
		j = 0;
		while (S > 0 && j < top)
		{
			//printf("%d ", sur[j]);
			if (sur[j] >= p && (sur[j] - p) / 2 >= p - 2)
			{
				counter++;
				S--;
			}
			j++;
		}
		printf("Case #%d: %d\n", i + 1, counter);
		fprintf(outfile, "Case #%d: %d\n", i + 1, counter);
	}
	
	fclose(infile);
	fclose(outfile);
	printf("done\n");
	return 0;
}
