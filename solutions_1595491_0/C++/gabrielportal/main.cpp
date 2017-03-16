#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
int n, s, p;

bool ok(int a)
{
	return ceil( 1.0*a / 3.0 ) >= p;
}

bool surprising(int a)
{
	if (a <= 2) return false;
	if (a%3 == 1) return false;
	if (a%3 == 0) return (a/3 + 1) >= p;
	return (a/3) + 2 >= p;
}

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << t+1 << ": ";
		cin >> n >> s >> p;
		v.resize(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.rbegin(), v.rend());
		
		int ret = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (ok(v[i])) ++ret;
			else if (s > 0 and surprising(v[i]))
			{
				s--;
				++ret;
			}
		}
		cout << ret << endl;
	}
}

