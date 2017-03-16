#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
	//freopen();
	//freopen();
	
	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc){
		int c;
		cin >> c;
		vector<pair<string, string>> inp(c);
		multiset<string> a, b;
		for (int i = 0; i < c; ++i)
		{
			cin >> inp[i].first >> inp[i].second;
			a.insert(inp[i].first);
			b.insert(inp[i].second);
		}
		
		int sol = 0;
		for (auto& e : inp)
		{
			if (a.count(e.first) > 1
			 && b.count(e.second) > 1)
			{
				sol++;
				a.erase(e.first);
				b.erase(e.second);
			}
		}
		
		cout << "Case #" << (tc + 1) << ": " << sol << endl;
	}
}