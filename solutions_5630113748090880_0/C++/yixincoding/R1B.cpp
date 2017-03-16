#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int T; cin >> T;
	for (int TT = 1; TT < T+1; TT++)
	{
		vector<int> v(2510, 0);
		for (int i = 0; i < 2510; i++) v[i] = 0;
		int n; cin >> n;
		for (int i = 1; i < 2*n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int t; cin >> t;
				v[t] ++;
			}
		}
		vector<int> res;
		res.clear();
		int total = 0;
		for (int i = 0; i < 2501; i++)
		{
			if(v[i] % 2 != 0)
			{
				total ++;
				res.push_back(i);
			}
			if (total == n) break;
		}
		cout << "Case #" << TT << ":";
		for (int i = 0; i < n; i++)
		{
			cout << ' ' << res[i] ;
		}
		cout << endl;
	}
	return 0;
}