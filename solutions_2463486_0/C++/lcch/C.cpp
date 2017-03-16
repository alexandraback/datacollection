#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10000000 + 10;
int f[maxn], a[20];

bool check(long long N)
{
	int nx = 0;
	while (N > 0) {
		a[++nx] = N % 10;
		N /= 10;
	}
	for (int i = 1; i <= nx; i++)
		if (a[i] != a[nx - i + 1]) return false;
	return true;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);

	f[0] = 0;
	for (int i = 1; i <= 10000000; i++) {
		f[i] = f[i-1];
		if (check(i) && check((long long)(i) * i)) f[i]++;
	}
	int TextN, TT = 0;
	long long A, B;
	int nA, nB;
	cin >> TextN;
	while (TextN--) {
		cin >> A >> B;
		nB = floor(sqrt((double(B))));
		nA = ceil(sqrt((double(A))));
		cout << "Case #" << ++TT << ": " << f[nB] - f[nA - 1] << endl;
	}
	return 0;
}