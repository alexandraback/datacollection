#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t;

	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		int n, k;
		cin >> n >> k;
		vector<ll> ans;
		vector<int> ans2[999];
		int cnt = 0;
		for(ll c=0; ans.size()<k; ++c)
		{
			ll w = (1LL<<(n-1)) + (c<<1) + 1;
			bool ok1 = true;
			ans2[cnt].clear();
			for(int b=2; b<=10; ++b)
			{
				ll d = 0;
				for(int i=0; i<n; ++i)
				{
					d *= b;
					d += (w>>(n-i-1))&1;
				}
				//print2(d, w);

				bool ok = false;
				for(int i=2; !ok && i<999; ++i)
					if(d%i == 0)
					{
						ok = true;
						ans2[cnt].push_back(i);
					}
				if(!ok)
				{
					ok1 = false;
					break;
				}
			}

			if(ok1)
			{
				ans.push_back(w);
				++cnt;
			}
		}

		cout << "Case #" << tt << ":\n";
		for(int j=0; j<k; ++j)
		{
			for(int i=0; i<n; ++i)
				cout << ((ans[j]>>(n-i-1))&1);
			for(int i=0; i<9; ++i)
				cout << " " << ans2[j][i];
			cout << "\n";
		}
		cout.flush();
	}

	return 0;
}
