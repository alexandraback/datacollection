#include <iostream>

using namespace std;

void doit(int casenum)
{
	cout << "Case #" << casenum << ": ";
	long long A, B, K;
	cin >> A >> B >> K;
	long long ans = 0;
	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < B; ++j)
		{
			ans += ((i & j) < K);
		}
	}
	cout << ans << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) doit(i);
	return 0;
}
