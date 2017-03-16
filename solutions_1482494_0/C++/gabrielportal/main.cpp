#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int a[1010], b[1010];
int vis[1010];

int main()
{
	int T; cin >> T;
	for (int tt = 1; tt <= T; ++tt)
	{
		cout << "Case #" << tt << ": ";
		
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i] >> b[i], vis[i] = 0;
		
		int ret = 0, stars = 0;
		while ( stars < 2*n )
		{
			bool found = 0;
			for (int i = 0; i < n; ++i)
				if ( vis[i] < 2 and b[i] <= stars )
				{
					stars += 2-vis[i];
					vis[i] = 2;
					found = 1;
					++ret;
					//cout << "\t2* " << i << endl;
				}
			if (found) continue;
			
			int index = -1, m2 = 0;
			for (int i = 0; i < n; ++i)
				if ( vis[i] == 0 and a[i] <= stars )
				{
					if (b[i] > m2)
					{
						index = i;
						m2 = b[i];
					}
				}
			if (index == -1) break;
			stars++;
			vis[index] = 1;
			++ret;
			//cout << "\t1* " << index << endl;
		}
		
		if (stars < 2*n) cout << "Too Bad" << endl;
		else cout << ret << endl;
	}
}

