#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
		return 0;
	FILE *fp = fopen(argv[1], "r");
	FILE *ofp = fopen(argv[2], "w");

	int ncase;
	fscanf(fp, "%d\n", &ncase);
	for(int i = 1; i <= ncase; i++)
	{
		int low;
		int high;
		fscanf(fp, "%d %d\n", &low, &high);

		int count = 0;
		if(low >= 10)
		{
			int digit = 1;
			int ndigit = 0;
			while(low / digit != 0)
			{
				digit *= 10;
				ndigit++;
			}
			for(int num = low; num < high; num++)
			{
				int recycle[digit - 1];
				int j = 0;
				for(int coeff = 10, mult = digit / 10; coeff < digit; coeff *= 10, mult /= 10)
				{
					int candidate = (num % coeff) * mult + num / coeff;
					if(candidate > num && candidate <= high)
					{
						bool appeared = false;
						for(int k = 0; k < j; k++)
							if(candidate == recycle[k])
								appeared = true;
						if(!appeared)
						{
							count++;
							recycle[j++] = candidate;
						}
					}
				}
			}
		}
		fprintf(ofp, "Case #%d: %d\n", i, count);
	}

	fclose(fp);
	fclose(ofp);
	return 0;
}

