#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void process(int tc)
{
	map<int, int> ma;
	int n;
	cin >> n;
	for (int i = 0; i < n * 2 - 1 ; ++i)
		for (int j = 0 ; j < n ; ++j)
		{
			int x;
			cin >> x;
			++ma[x];
		}
	vector<int> v;
	for (auto it = ma.begin() ; it != ma.end() ; ++it)
		if (it->second % 2)
			v.push_back(it->first);
	sort(v.begin() , v.end());
	cout << "Case #" << tc << ':';
	for (auto it = v.begin() ; it != v.end() ; ++it)
		cout << ' ' << *it;
	cout << endl;

}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 1 ; i <= t; ++i)
		process(i);
}
