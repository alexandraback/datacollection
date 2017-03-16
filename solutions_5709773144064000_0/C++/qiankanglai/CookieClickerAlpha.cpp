#include <stdio.h>
#include <vector>


int main()
{
    FILE * pFile = fopen("B-small-attempt0.in", "r");
	int T;
	fscanf(pFile, "%d", &T);
	for(int t = 0; t < T; t++)
	{
		double C, F, X;
		fscanf(pFile, "%lf %lf %lf", &C, &F, &X);
		double mint = X / 2;
		int count_farm = 0;
		double time = 0;
		while(true)
		{
			time += C / (2+F*count_farm);
			count_farm++;
			double mint2 = time + X/(2+F*count_farm);
			if(mint2 < mint)
				mint = mint2;
			else
				break;
		}
		printf("Case #%d: %lf\n", t+1, mint);
	}
	fclose(pFile);
	return 0;
}