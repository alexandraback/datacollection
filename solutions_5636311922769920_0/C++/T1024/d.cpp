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

		ll pw3 = 1;
		for(int i=0; i<c-1; ++i)
			pw3 *= k;
		for(int i=0; i<k; ++i)
			ans.push_back(i*pw3+1);

		cout << "Case #" << tt << ":";
		if(s < k)
			cout << " IMPOSSIBLE\n";
		else
		{
			for(int i=0; i<ans.size(); ++i)
				cout << " " << ans[i];
			cout << "\n";
		}
		cout.flush();
	}

	return 0;
}
