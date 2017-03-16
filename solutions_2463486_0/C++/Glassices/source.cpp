#include <iostream>
#include <cstring>
using namespace std;

int d[30];
long long a[100];

int Is_Palindrome(long long x)
{
	int n;
	for (n = 0; x; x /= 10) d[n++] = x % 10;
	for (int i = 0; i < n; i++)
		if (d[i] != d[n-1-i])
			return 0;
	return 1;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n = 0;
	for (int i = 1; i <= 10000000; i++)
		if (Is_Palindrome(i) && Is_Palindrome((long long)i*i))
			a[n++] = (long long)i*i;
	int T;
	cin >> T;
	for (int step = 1; step <= T; step++) {
		long long A, B;
		cin >> A >> B;
		int res = 0;
		for (int i = 0; i < n; i++)
			if (a[i] >= A && a[i] <= B)
				res++;
		cout << "Case #" << step << ": " << res << endl;
	}
	return 0;
}

