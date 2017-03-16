#include <iostream>
#include <algorithm>
using namespace std;

bool solve(int x, int n, int m)
{
	if(x > 6) return 0;
	if(n*m % x) return 0;
	if(x > max(n, m)) return 0;
	int z = (x + 1)/2;
	if(z > min(n, m)) return 0;
	if(x > 3 && z >= min(n, m)) return 0;
	return 1;
}

int main()
{
	int T; cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int x, n, m; cin >> x >> n >> m;
		cout << "Case #" << t << ": " << (solve(x, n, m) ? "GABRIEL" : "RICHARD") << endl;
	}
	return 0;
}

