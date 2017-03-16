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
		vector<int> a(n);
		int cnt[1111] = {0};
		for(int i=0; i<n; ++i)
		{
			cin >> a[i];
			--a[i];
			++cnt[a[i]];
		}

		int ans = 0;
		
		int mark[1111] = {0};
		int sid=1;
		for(int i=0; i<n; ++i) if(mark[i] != sid)
		{
			int s = 0;
			int j=i;
			while(mark[j] != sid)
			{
				mark[j] = sid;
				j = a[j];
				++s;
			}
			if(j == i)
			{
				ans = max(s,ans);
			}
			++sid;
		}
		
		int ans2=0;
		int d[1111] = {0}, h[1111] = {0};
		for(int i=0; i<n; ++i) if(cnt[i] == 0 || i == a[a[i]])
		{
			int s = 0;
			int j=i,j1=-1;
			while(mark[j] != sid)
			{
				mark[j] = sid;
				j1 = j;
				j = a[j];
				++s;
			}
			if(a[j] == j1 && j != a[j])
			{
				d[j] = max(d[j], s);
				h[j1] = 1;
			}
			++sid;
		}
		int dbg1=0;
		for(int i=0; i<n; ++i) if(d[i])
		{
			ans2 += d[i];
			if(h[i]) {
				--ans2;
				++dbg1;
			}
		}
		if(dbg1&1)
			cerr << "!!!!!!!!!!!!!!!!!!!!!!!\n";
		
		ans = max(ans, ans2);
		cout << "Case #" << tt << ": " << ans << "\n";
		cout.flush();
	}

	return 0;
}
