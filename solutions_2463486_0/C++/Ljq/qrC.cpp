#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int vs[130];
vector<long long> vt;

bool CheckPar(long long m)
{
	int n = 0;
	for (; m; m /= 10)
		vs[n++] = m % 10;
	for (int i = 0; i < n; i ++)
		if (vs[i] != vs[n-1-i])  return false;
	return true;
}

int Work()
{
	long long a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < vt.size(); i ++)
	{
		long long z = vt[i] * vt[i];
		ans += z >= a && z <= b;
	}
	return ans;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("Cs0-output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	vt.clear();
	for (long long i = 1; i <= 10000000; i ++)
		if (CheckPar(i) && CheckPar(i * i))  vt.push_back(i);

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt ++)
		cout << "Case #" << tt << ": " << Work() << endl;

	return 0;
}