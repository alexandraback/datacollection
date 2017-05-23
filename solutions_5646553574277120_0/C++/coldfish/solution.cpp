#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;
void main()
{
	FILE *fs = fopen("input.txt", "r");
	FILE *fp = fopen("output.txt", "w");

	int testcase;
	fscanf(fs, "%d", &testcase);

	for (int t = 0; t < testcase; t++)
	{
		fprintf(fp, "Case #%d:", t + 1);

		int c, d, v,cnt=0;
		int arr[6] = { 0, };
		int val[40] = { 0, };
		fscanf(fs, "%d %d %d", &c, &d, &v);
		for (int i = 0; i < d; i++)
			fscanf(fs, "%d", &arr[i]);
		val[0] = 1;
		for (int i = 0; i < d; i++)
		{
			for (int j = v; j > -1; j--){
				if (val[j] == 1 && arr[i] + j <= v)
					val[j + arr[i]] = 1;
			}
		}
		for (int i = 1; i <= v; i++)
		{
			if (val[i] == 0)
			{
				cnt++;
				for (int j = v; j > -1; j--){
					if (val[j] == 1 && i+j<=v)
						val[j + i] = 1;
				}
			}
		}
		fprintf(fp, " %d\n", cnt);
	}
	fclose(fs);
	fclose(fp);
}