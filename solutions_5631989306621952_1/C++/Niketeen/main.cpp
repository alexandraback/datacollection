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
	freopen("A-large.in","r",stdin);
	freopen("out.txt", "w", stdout);
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; ++t)
	{
		string s;
		cin >> s;
		vector <pair <int, int> > v(s.size());
		v[0] = make_pair(s[0]-'A',0);
		for (int i = 1; i < s.size(); ++i)
		{
			int a = s[i] - 'A';
			if (a >= v[i - 1].first)
			{
				v[i] = make_pair(a, i);
			}
			else
				v[i] = v[i-1];
		}
		string res, resb;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (i == v[i].second)
			{
				res += s[i];
			}
			else
				resb = s[i] + resb;
		}
		res += resb;
		printf("Case #%d: ",t + 1);	
		cout << res << '\n';
	}
	return 0;
}