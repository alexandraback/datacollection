#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int TestCase, A, B, C;
int a[50], b[50], c[50];
long long sa[50], sb[50], sc[50];
long long f[50][2][2];

void get(int x, int a[], long long s[])
{
	for (int i = 0; i < 50; i ++) {
		a[i] = x & 1;
		x >>= 1;
	}
	s[0] = 1;
	for (int i = 1; i < 50; i ++) {
		s[i] = s[i - 1];
		if (a[i - 1] == 1) {
			s[i] += 1LL << i - 1;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TestCase);
	for (int Case = 1; Case <= TestCase; Case ++) {
		scanf("%d%d%d", &A, &B, &C);
		get(A - 1, a, sa);
		get(B - 1, b, sb);
		get(C, c, sc);
		memset(f, 0, sizeof(f));
		f[40][1][1] = 1;
		long long ret = 0;
		for (int i = 39; i >= 0; i --) {
			for (int j = 0; j < 2; j ++) {
				for (int k = 0; k < 2; k ++)
				if (f[i + 1][j][k] > 0) {
					int x = j == 1 ? a[i] + 1 : 2;
					int y = k == 1 ? b[i] + 1 : 2;
					for (int u = 0; u < x; u ++) {
						for (int v = 0; v < y; v ++) {
							int w = u & v;
							int jj = j & (u == a[i]);
							int kk = k & (v == b[i]);
							if (w < c[i]) {
								long long X = 0, Y = 0;
								if (jj == 0) {
									X = 1LL << i;
								} else {
									X = sa[i];
								}
								if (kk == 0) {
									Y = 1LL << i;
								} else {
									Y = sb[i];
								}
							//	cout << f[i + 1][j][k] << " " << X << " " << Y << endl;
								ret += X * Y * f[i + 1][j][k];
							} else if (w == c[i]) {
								f[i][jj][kk] += f[i + 1][j][k];
							}
						}
					}
				}
			}
	//		long long sum = f[i][0][0] + f[i][0][1] + f[i][1][0] + f[i][1][1];
	//		cout << "Sum = " << sum << endl;
		}
		long long sum = f[0][0][0] + f[0][0][1] + f[0][1][0] + f[0][1][1];
	//	cout << "Sum = " << sum << endl;
		printf("Case #%d: %I64d\n", Case, ret);
	}
	return 0;
}
