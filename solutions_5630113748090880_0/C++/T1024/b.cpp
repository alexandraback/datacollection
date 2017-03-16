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
		int n;
		cin >> n;
		int cnt[9999] = {0};
		for(int i=0; i<2*n-1; ++i)
		for(int j=0; j<n; ++j)
		{
			int x;
			cin >> x;
			++cnt[x];
		}
		vector<int> ans;		
		for(int i=0; i<3000; ++i)
			if(cnt[i]&1)
			{
				ans.push_back(i);
			}
		
		if(ans.size() != n)
		{
			cerr << "!!!!!!!!!!!!!Error!!!!!!!!!!\n";
			*(int*)0=0;
		}
		
		cout << "Case #" << tt << ":";
		for(int i=0; i<n; ++i)
			cout  << " " << ans[i];
		cout << "\n";
		cout.flush();
	}

	return 0;
}
