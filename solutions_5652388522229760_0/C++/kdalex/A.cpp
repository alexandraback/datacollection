#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void updateCounts(int num, int *counts)
{
//	std::cout << num << std::endl;
	do
	{
		++counts[num % 10];
		num /= 10;
	} while (num > 0);
}

const int MAXN = 10000000;
int count[MAXN + 1] = {0};


int checkNum(int N)
{
	if (count[N])
		return count[N];

	int counts[10] = { 0 };
	int M = N;
	for (;;)
	{
		updateCounts(M, counts);
		int valid = 0;
		for (int& cnt: counts)
			if (cnt)
				++valid;
		if (valid == 10)
			break;
		M += N;
	}
//	std::cout << N << " : " << M / N << std::endl;
	return count[N] = M;
}

int main(int argc, char **argv)
{
	std::ifstream in;
	std::ofstream out;
	in.open(argv[1], std::ios_base::in);
	out.open(argv[2], std::ios_base::out);

#if 0
	checkNum(11);
	std::cout << count[11] << std::endl;
#else
	count[0] = -1;
	for (int i = 1; i <= MAXN; ++i)
		checkNum(i);

	int T, N;
	in >> T;
	for (int i = 0; i < T; ++i)
	{
		in >> N;
		out << "Case #" << i + 1 << ": ";
		if (count[N] >= 0)
			out << count[N];
		else
			out << "INSOMNIA";
		out << std::endl;
	}
#endif
	return 0;
}
