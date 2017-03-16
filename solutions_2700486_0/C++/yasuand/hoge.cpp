#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long _combi[2000][2000];

long long combi(int i, int j)
{
	if (_combi[i][j] >= 0) {
		return _combi[i][j];
	} else if (i < j)  {
		return _combi[i][j] = 0;
	} else if (j == i || j == 0) {
		return _combi[i][j] = 1;
	} else {
		return _combi[i][j] = combi(i - 1, j) + combi(i - 1, j - 1);
	}
}

int main()
{
	memset(_combi, -1, sizeof(_combi));
	_combi[0][0] = 1;
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i) {
		long long n, x, y;
		scanf("%lld%lld%lld", &n, &x, &y);
		y = abs(y);
		long long sum = x + y;
		long long nn = sum  * (sum - 1) / 2;
		double p;
		if (n >= (sum + 1) * (sum + 2) / 2) {
			p = 1;
		} else if (nn >= n) {
			p = 0;
		} else {
			long long m = n - nn;
			long long pattern = 0;
			++sum;
			if (x == 0) {
				if (n == (sum + 1) * (sum + 2) / 2) {
					p = 1;
				} else {
					p = 0;
				}
			} else {
				for(long long j = y + 1; j <= sum; ++j) {
					pattern += combi((int)m, (int)j);
				}
				p = double(pattern) / pow(2.0, double(m));
			}
		}
		printf("Case #%d: %.8f\n", i, p);
	}
	return 0;
}