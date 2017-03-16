#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 200;

int tc;
int n;
int s[MAXN];
double sum;
double a[MAXN];
double suma;
double r[MAXN];
bool fix[MAXN];

int main()
{
	cin >> tc;
	for (int testcase = 1; testcase <= tc; ++testcase) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
			sum += s[i];
		}
		a[0] = 0;
		suma = 0;
		for (int i = 1; i < n; ++i) {
			a[i] = (s[0] - s[i]) / sum;
			suma += a[i];
		}
		r[0] = (1.0 - suma) / n;
		for (int i = 1; i < n; ++i)
			r[i] = r[0] + a[i];

		while (true) {
			memset(fix, 0, sizeof fix);
			int neg = 0;
			for (int i = 0; i < n; ++i)
				if (r[i] < 0) {
					r[i] = 0;
					fix[i] = true;
					++neg;
				}
			if (neg == 0)
				break;
			int at = -1;
			for (int i = 0; i < n; ++i)
				if (!fix[i]) {
					at = i;
					break;
				}
			a[at] = 0;
			suma = 0;
			for (int i = at + 1; i < n; ++i)
				if (!fix[i]) {
					a[i] = (s[at] - s[i])/sum;
					suma += a[i];
				}
			r[at] = (1 - suma) / (n - neg);
			for (int i = 0; i < n; ++i)
				if (!fix[i])
					r[i] = r[at] + a[i];
		}
	
		printf("Case #%d:", testcase);
		for (int i = 0; i < n; ++i)
			printf(" %.7lf", r[i] * 100);
		printf("\n");
	}
}
