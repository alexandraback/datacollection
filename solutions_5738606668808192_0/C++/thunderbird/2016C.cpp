#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;

map<ll, vector<ll>> ans;

ll GetDivisor(ll n)
{
	for (ll i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0) return i;
	}
	return -1;
}
ll Change(ll n, int b)
{
	ll ret = 0;
	ll i = 1;
	while (n > 0)
	{
		ret += (n % 10)*i;
		n /= 10;
		i *= b;
	}
	return ret;
}

ll To10(ll n)
{
	ll ret = 0;
	ll i = 1;
	while (n > 0)
	{
		ret += (n % 2)*i;
		n /= 2;
		i *= 10;
	}
	return ret;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	//freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int testcase;

	scanf("%d", &testcase);
	for (int case_id = 1; case_id <= testcase; case_id++)
	{

		int N, J;
		printf("Case #%d: ", case_id);
		printf("\n");
		cin >> N >> J;
		ll tmp = 1;
		for (int i = 0; i < N; i++) tmp *= 2;
		int l = 0;
		for (ll i = tmp / 2+1; i < tmp; i += 2)
		{
			ll tmp10 = To10(i);
			bool iscoin = true;
			vector<ll> d;
			for (int j = 2; j <= 10; j++)
			{
				d.push_back(GetDivisor(Change(tmp10,j)));
				if (d[d.size() - 1] == -1)
				{
					iscoin = false;
					break;
				}
			}
			if (iscoin)
			{
				ans.insert(pair<ll, vector<ll>>(i, d));
				if (ans.size() == J)
					break;
			}
		}


		for (std::map<ll, vector<ll>>::iterator it = ans.begin(); it != ans.end(); ++it)
		{		
			std::cout << To10(it->first) << " ";
			for (int i = 0; i < it->second.size();i++)
				std::cout << it->second[i] << " ";
			std::cout << endl;
		}

	}
	return 0;
}

