#include<cstdio>

using namespace std;


int main(int argc, char** argv)
{
	int t = 0;
	FILE *fp = fopen(argv[1], "r");
	FILE *fm = fopen(argv[2], "w");
	fscanf(fp, "%d", &t);

	long long int radius = 0;
	long long int paint = 0, temp = 0, count = 0;

	for(int i=0; i<t; i++)
	{
		fscanf(fp, "%lld %lld", &radius, &paint);
		count = 0;
		
		while(paint >= 0)
		{
			temp = radius*2 + 1;
	
			if(paint - temp >= 0)
			{
				paint -= temp;
			}
			else
			{
				fprintf(fm, "Case #%d: %lld\n", i+1, count);
				break;
			}
			
			++count;
			radius += 2;
		}
	}
	
	fclose(fp);
	fclose(fm);
	return 0;
}
