#include <iostream>
using namespace std;

int main()
{
	FILE* input;
	FILE* output;

	input = fopen("C:\\Users\\현우\\Desktop\\Google\\2016QR\\Revenge of the Pancakes\\large.txt", "r");
	output = fopen("C:\\Users\\현우\\Desktop\\Google\\2016QR\\Revenge of the Pancakes\\large_answer.txt", "w");

	int T;
	int t = 1;

	fscanf(input, "%d", &T);

	while (T >= t)
	{
		char pancakes[101];

		fscanf(input, "%s", pancakes);

		int flip = 0;
		int end;

		for (end = 0; pancakes[end] != '\0'; ++end);

		--end;

		for (int i = end; i >= 0;)
		{
			if (pancakes[i] == '+')
				--i;

			else
			{
				int minus_end;

				for (minus_end = i; pancakes[minus_end] == '-'; --minus_end);

				i = minus_end;

				for (int j = 0; j <= i; ++j)
				{
					if (pancakes[j] == '+')
						pancakes[j] = '-';
					else
						pancakes[j] = '+';
				}

				++flip;
			}
		}

		fprintf(output,"Case #%d: %d\n", t, flip);

		++t;

	}

	return 0;

}