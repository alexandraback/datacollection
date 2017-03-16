#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
#include <sstream> 
#include <set> 
#include <map> 
#include <queue> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <bitset> 
#include <unordered_map> 
#include <unordered_set> 

using namespace std;
typedef long long ll;





int main(){
#ifdef _CONSOLE 
	freopen("B-large (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	
	int test;
	cin >> test;
	
	for (int t = 1; t <= test; ++t)
	{
		int n;
		cin >> n;
		vector<vector<int> > v(2*n-1, vector<int> (n));
		map<int, int> ma;
		for (int i = 0; i < 2 * n - 1; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> v[i][j];
				ma[v[i][j]] ++;
			}
		}
		vector<int> ans;
		for (auto it = ma.begin(); it != ma.end(); ++it)
		{
			if (it->second % 2 != 0)
			{
				ans.push_back(it->first);
			}
		}
		sort(ans.begin(), ans.end());
		
		cout << "Case #" << t << ": ";
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i] << ' ';
		}
		cout << "\n";

	}


	return 0;
}

