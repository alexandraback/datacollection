#include <fstream>
#include <algorithm>

#define MAX_N 10000000
#define INFINITY 1000000000

using namespace std;

ifstream fin("D:\\Input.txt");
ofstream fout("D:\\Output.txt");

int T, N, answer, dp[MAX_N];

int reverse_digits(int n)
{
	int result = 0;
	while(n > 0)
	{
		result = result * 10 + (n % 10);
		n /= 10;
	}
    return result;
}

int main(int argc, const char* argv[])
{
	fin >> T;
	dp[1] = 1;
	for(int i = 2; i < MAX_N; i++)
	{
		int a = reverse_digits(i);
		if(a < i && reverse_digits(a) == i)
			dp[i] = min(dp[i - 1], dp[a]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	for(int i = 0; i < T; i++)
	{
		fin >> N;
		fout << "Case #" << i + 1 << ": " << dp[N] << "\n";
	}
	return 0;
}