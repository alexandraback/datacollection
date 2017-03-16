#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
using namespace std;

#define MAXN 1000000
int result[MAXN + 1];

long long reverse(long long N)
{
	long long result = 0;
	while (N > 0)
	{
		result = result * 10 + N % 10;
		N = N / 10;
	}
	return result;
}

void Solve()
{
	long long N;
	cin >> N;
	cout << result[N];
}

int main() {
	result[0] = 0;
	for (int i = 1; i <= MAXN; ++i)
	{
		result[i] = MAXN + 1;
	}
	for (int i = 1; i <= MAXN; ++i)
	{
		int revI = reverse(i);
		result[i] = min(result[i], result[i - 1] + 1);
		result[revI] = min(result[revI], result[i] + 1);
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}