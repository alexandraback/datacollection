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
		int k, c, s;
		cin >> k >> c >> s;

		vector<ll> ans;

		for(int j=0; j<k; j+=c)
		{
			ll pos = 0;
			ll pwk = 1;
			for(int i=1; i<c && j+i<k; ++i)
			{
				pos = pos*k + i;
				pwk *= k;
			}
			while(pwk)
			{
				pos += j*pwk;//+pwk/k*j+pwk/k/k*j;
				if(pwk == 1)
					break;
				pwk /= k;
			}
			ans.push_back(pos);
		}

		cout << "Case #" << tt << ":";
		if(s < ans.size())
			cout << " IMPOSSIBLE\n";
		else
		{
			for(int i=0; i<ans.size(); ++i)
				cout << " " << ans[i]+1;
			cout << "\n";
		}
		cout.flush();
	}

	return 0;
}
