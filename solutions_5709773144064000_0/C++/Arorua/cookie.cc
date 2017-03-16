#include <iostream>
#include <cstdio>
using namespace std;

int process(int k)
{
	double C, F, X;
	double f = 2.0, tot = 0.0, ans = 1e10;
	cin >> C >> F >> X;
	// fix after drunk
	for (int i = 0; ; ++i) {
		if (tot + X / f > ans)
			break;
		// cout << C / f << " " << " " << X / f << " " << tot + X / f << endl;
		ans = tot + X / f;
		tot += C / f;
		f += F;
	}
	printf("Case #%d: %.7lf\n", k, ans);
}

int main()
{
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i)
		process(i);
}

