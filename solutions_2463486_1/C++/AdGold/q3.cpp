#include <stdio.h>
#include <vector>
using namespace std;

bool isPalin(long long n)
{
	long long copy = n, test = 0;
	while (copy)
	{
		test *= 10;
		test += copy%10;
		copy /= 10;
	}
	return test == n;
}

vector<long long> fairAndSquare;

int main()
{
	for (long long i = 0; i <= 10000000LL; i++)
	{
		if (isPalin(i) && isPalin(i*i))
		{
			printf("%lld, %lld\n", i,i*i);
			fairAndSquare.push_back(i*i);
		}
	}
	freopen("C-large-1.in", "r", stdin);
	freopen("q3out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		long long start, end;
		scanf("%lld %lld", &start, &end);
		int c = 0;
		for (int i = 0; i < fairAndSquare.size(); i++)
		{
			if (start <= fairAndSquare[i] && fairAndSquare[i] <= end) c++;
		}
		printf("Case #%d: %d\n", t, c);
	}
}