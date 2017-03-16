/* 2013.4.27 Yoshi-TS4 */

#include <stdio.h>
#include <Windows.h>

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;
	__int64 r,t;

	fscanf(fin, "%d", &T);

	for(int a = 1; a <= T; a++)
	{
		fscanf(fin, "%lld%lld", &r, &t);

		__int64 min = 1;
		__int64 max = 2000000000;
		__int64 cur;
		while(true)
		{
			cur = (min + max) / 2;
			__int64 result = 2 * cur + (2 * r - 1);
			__int64 result2 = 2 * (cur+1) + (2 * r - 1);
			if(result2 <= t / (cur+1))
				min = cur + 1;
			else if(result > t / cur)
				max = cur - 1;
			else
			{
				result *= cur;
				result2 *= cur+1;
				if(result <= t && result2 > t)
					break;
				else if(result2 <= t)
					min = cur + 1;
				else if(result > t)
					max = cur - 1;
			}
		}

		fprintf(fout, "Case #%d: %lld\n", a, cur);
	}

	return -0;
}
