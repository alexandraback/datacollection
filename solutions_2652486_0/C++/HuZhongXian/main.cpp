#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if(a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if(a < b) return a; else return b; }
template <class T> T ABS(T a) { if(a < 0) return -a; else return a; }

#define MAX_STR_NUM 256

int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "C-small-1-attempt0.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int T;
	int R, N, M, K;
	long long p[15], cnt[13];
	fscanf(input, "%d\n", &T);
	for (int i = 1; i <= T; ++i)
	{
		fprintf(output, "Case #%d:\n", i);

		fscanf(input, "%d %d %d %d\n", &R, &N, &M, &K);
		for (int r = 0; r < R; ++r)
		{
			for (int k = 0; k < K; ++k)
			{
				fscanf(input, "%lld", &p[k]);
			}
			fscanf(input, "\n");

			memset(cnt, 0, sizeof(cnt));
			for (int k = 0; k < K; ++k)
			{
				long long tcnt[13];
				memset(tcnt, 0, sizeof(tcnt));
				for (int yz = 2; yz <= M; ++yz)
				{
					while ((p[k] % yz) == 0)
					{
						p[k] /= yz;
						++tcnt[yz];
					}
					cnt[yz] = MAX(cnt[yz], tcnt[yz]);
				}
			}

			long long tt = 0;
			for (int yz = 2; yz <= M; ++yz)
			{
				tt += cnt[yz];
			}
			if (tt)
			{
				fprintf(output, "%s", std::string(cnt[7], '7').c_str());
				fprintf(output, "%s", std::string(cnt[5], '5').c_str());
				fprintf(output, "%s", std::string(cnt[3], '3').c_str());
				tt -= cnt[7];
				tt -= cnt[5];
				tt -= cnt[3];
				if (tt == 6)
				{
					fprintf(output, "%s", "444");
				}
				else if (tt == 5)
				{
					fprintf(output, "%s", "442");
				}
				else if (tt == 4)
				{
					fprintf(output, "%s", "422");
				}
				else
				{
					fprintf(output, "%s", cnt[2] > 1 ? "4" : "2");
				}
				fprintf(output, "\n");
			}
			else
			{
				fprintf(output, "%s\n", std::string(N, '2').c_str());
			}
		}
	}

	fclose(output);
	fclose(input);

	//system("pause");
	return 0;
}
