#include <iostream>

using namespace std;

int main()
{
	FILE* input;
	FILE* output;

	input = fopen("C:\\Users\\현우\\Desktop\\Google\\2016QR\\Fractiles\\large.txt", "r");
	output = fopen("C:\\Users\\현우\\Desktop\\Google\\2016QR\\Fractiles\\large_answer.txt", "w");

	int T;
	int t = 1;

	fscanf(input, "%d", &T);

	while (T >= t)
	{
		int K, C, S;

		fscanf(input, "%d %d %d", &K, &C, &S);

		if (K == S)
		{
			fprintf(output, "Case #%d:", t);

			for (int i = 1; i <= K; ++i)
				fprintf(output, " %d", i);

			fprintf(output, "\n");

		}

		else if (C == 1 || K > S+1)
			fprintf(output, "Case #%d: IMPOSSIBLE\n", t);

		else
		{
			fprintf(output, "Case #%d:", t);

			for (int i = 2; i <= K; ++i)
				fprintf(output, " %d", i);

			fprintf(output, "\n");

		}

		++t;
	}

	return 0;

}