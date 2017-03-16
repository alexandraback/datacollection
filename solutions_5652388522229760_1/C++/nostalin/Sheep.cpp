#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int digits[10] = { 0,1,2,3,4,5,6,7,8,9 };
bool is_seen[10];

long long int digit(long long int n, int dig)
{
	long long int ret;

	ret = n / pow(10, dig);
	ret %= 10;

	return ret;
}

int main()
{
	FILE* input;
	FILE* output;

	input = fopen("C:\\Users\\현우\\Desktop\\Google\\2016QR\\Counting Sheep\\large.txt", "r");
	output = fopen("C:\\Users\\현우\\Desktop\\Google\\2016QR\\Counting Sheep\\large_answer.txt", "w");

	int T;
	int t = 1;

	fscanf(input,"%d", &T);

	while (T >= t)
	{
		long long int num;
		bool all_seen = false;

		fscanf(input, "%lld", &num);
		cout << "!" << endl;
		if (num == 0)
			fprintf(output, "Case #%d: INSOMNIA\n", t);

		else
		{
			for (int i = 0; i < 10; ++i)
				is_seen[i] = false;

			long long int n;
			long long int sheep;
			all_seen = false;

			for (n = 1; !all_seen; ++n)
			{
				sheep = num*n;
				for (int dig = 0; pow(10, dig)<=sheep; ++dig)
					is_seen[digit(sheep, dig)] = true;

				all_seen = true;

				for (int i = 0; i < 10; ++i)
					if (!is_seen[i])
						all_seen = false;
			}

			fprintf(output, "Case #%d: %lld\n", t, sheep);
		}

		++t;

	}

	return 0;

}