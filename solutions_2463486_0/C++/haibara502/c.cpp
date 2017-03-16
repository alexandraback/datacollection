#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 10000000;
int sum[maxn], d[20];

void prepare()
{
	memset(sum, 0, sizeof sum);
	for (int i = 1; i <= 10000000; ++i)
	{
		sum[i] += sum[i - 1];
		long long sqr = (long long)i * (long long)i;
		int len = 0;
		while (sqr)
			d[++len] = sqr % 10, sqr /= 10;
		int half = len / 2;
		bool ff = true;
		for (; half; --half)
			if (d[half] != d[len + 1 - half]) ff = false;
		if (!ff) continue;
		sqr = i;
		len = 0;
		while (sqr)
			d[++len] = sqr % 10, sqr /= 10;
		half = len / 2;
		ff = true;
		for (; half; --half)
			if (d[half] != d[len + 1 - half]) ff = false;
		if (ff) sum[i]++;
	}
}

void getans()
{
	long long A, B;
	cin >> A >> B;
	long long a1 = (long long)sqrt(A), b1 = (long long)sqrt(B);
	if (a1 * a1 == A) --a1;
	if ((b1 + 1) * (b1 + 1) == B) ++b1;
	cout << sum[b1] - sum[a1] << endl;
	/*
	cerr << a1 << ' ' << b1 << endl;
	cerr << sum[b1] << ' ' << sum[a1] << endl;
	cerr << "begin" << endl;
	for (int i = a1; i <= b1; ++i) if (sum[i] != sum[i - 1]) cerr << i << ' ';
	cerr << endl;
	*/
}

int main()
{
	prepare();
	int T, t1(0);
	scanf("%d", & T);
	while (T--)
	{
		printf("Case #%d: ", ++t1);
		getans();
	}
}
