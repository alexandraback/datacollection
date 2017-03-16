#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>


using namespace std;

const int MAXN = 100002;

int m, n;
double pp[MAXN], f[MAXN];

double Work()
{
	cin >> m >> n;
	for (int i = 0; i < m; i ++)
		cin >> pp[i];
	
	f[0] = pp[0];
	for (int i = 1; i < m; i ++)
		f[i] = f[i-1] * pp[i];

	double ans = n + 2, res;

	for (int i = m - 1; i >= 0; i --)
	{
		res = (i + i + n - m + 1) + (n + 1) * (1.0 - f[m-i-1]);
		ans = min(ans, res);
	}



	return ans;
}


int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout.precision(7);

	int T;
	cin >> T;
	for (int k = 1; k <= T; k ++)
		cout << "Case #" << k << ": " << Work() << endl;

	return 0;
}