#include <iostream>
#include <stdint.h>


int main()
{
	char filename1[100] = "C:\\Users\\RezaulAkram\\Desktop\\A-large.in";
	char filename2[100] = "C:\\Users\\RezaulAkram\\Desktop\\op.txt";
	FILE* file = fopen(filename1,"r");
	FILE* file2 = fopen(filename2,"w");
	int T;

	fscanf(file,"%d\n", &T);

	for(int i =0 ; i < T; i++)
	{
		int64_t n, d;

		fscanf(file,"%llu/%llu", &n, &d);

		int pos = 0;
		int result = 0;
		if(n >= d)
		{
			pos = 1;
			n = n - d;
		}
		for(int j = 1 ; j <= 40; j++)
		{
			n *= 2;

			if(n >= d)
			{
				if((result == 0) && (pos == 0))
				{
					pos = 1;
					result = j;
				}
				n = n - d;
			}

			if(n == 0)
				break;
			
		}

		fprintf(file2, "Case #%d: ", (i+1));

		if(n != 0)
			fprintf(file2, "Impossible\n");
		else
			fprintf(file2, "%d\n", result);

	}

	fclose(file);
	fclose(file2);
}