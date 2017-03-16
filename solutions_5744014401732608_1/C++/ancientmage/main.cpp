#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <time.h>
#include <vector>
#include <queue>
#include <set>
#include <random>
#include <string>
#include <fstream>

using namespace std;

#define ll long long

#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");
/**/
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin >> test;
	for(int _ = 1; _ <= test; ++_)
	{
		ll n, m;
		cin >> n >> m;
		if((1ll << (n-2)) < m)
		{
			cout << "Case #" << _ << ": IMPOSSIBLE\n";
			continue;
		}
		else
		{
			if((1ll << (n-2)) == m)
			{
				cout << "Case #" << _ << ": POSSIBLE\n";
				for(int i = 1; i <= n; ++i, cout << endl)
					for(int j = 1; j <= n; ++j)
						cout << bool(i < j);
				continue;
			}
		}
		cout << "Case #" << _ << ": POSSIBLE\n";
		vector<vector<int> > v(n+2, vector<int>(n+2, 0));
		vector<int> bits;
		ll mm = m;
		while(mm)
		{
			bits.push_back(mm & 1ll);
			mm >>= 1;
		}
		for(int i = 1; i < 1 + bits.size(); ++i)
			for(int j = i+1; j <= 1 + bits.size(); ++j)
				v[i][j] = 1;
		for(int i = 0; i < bits.size(); ++i)
			if(i + 2 < n)
				v[i+2][n] = bits[i];
		for(int i = 1; i <= n; ++i, cout << endl)
			for(int j = 1; j <= n; ++j)
				cout << v[i][j];
	}

	return 0;
}
 