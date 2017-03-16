#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_NUM 256

int cnt[2000001][8];
int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "data.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	memset(cnt, 0, sizeof(cnt));
	int digits[16], len, temp, tens, val;
	for (int i = 21; i <= 2000001; ++i)
	{
		len = 0, temp = i, tens = 1;
		while (temp)
		{
			digits[len++] = temp % 10;
			temp /= 10;
			tens *= 10;
		}
		tens /= 10;
		temp = i;
		for (int j = 0; j < len; ++j)
		{
			temp = (temp / 10) + tens * digits[j];
			if (digits[j] && (temp < i))
			{
				bool valid = true;
				for (int k = 1; true && (k <= cnt[i][0]); ++k)
					valid = cnt[i][k] != temp;
				if (valid)
					cnt[i][++cnt[i][0]] = temp;
			}
		}
	}
	
	int T, A, B;
	fscanf(input, "%d", &T);
	for (int i = 0; i < T; ++i)
	{
		fscanf(input, "%d %d", &A, &B);
		int ret = 0;
		for (int j = A + 1; j <= B; ++j)
			for (int k = 1; k <= cnt[j][0]; ++k)
				if (cnt[j][k] >= A)
				{
//					fprintf(output, "|%d %d|\n", cnt[j][k], j);
					++ret;
				}
		fprintf(output, "Case #%d: %lld\n", i + 1, ret);
	}
	
	fclose(output);
	fclose(input);

//	system("pause");
	return 0;
}