#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm> 
#include <cmath> 

#include <vector> 
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <sstream>


using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
}


int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt", "w", stdout);
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; ++t)
	{
		int n;
		cin >> n;
		vector <int> v(10000,0);
		for (int i = 0; i < 2 * n - 1; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int a;
				cin >> a;
				v[a] = 1 - v[a];
			}
		}
		vector <int> res;
		for (int i = 0; i < v.size(); ++i)
			if (v[i] == 1)
				res.push_back(i);
		sort(res.begin(), res.end());
		printf("Case #%d: ",t + 1);	
		for (int i = 0; i < res.size(); ++i)
			cout << res[i] << ' ';
		cout << '\n';
	}
	return 0;
}