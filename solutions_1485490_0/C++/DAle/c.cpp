#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

int main()
{
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n, m;
		ifs >> m >> n;
		vector<long long> cnt1(n), v1(n);
		vector<long long> cnt2(m), v2(m);
		for (int i = 0; i < m; ++i)
			ifs >> cnt2[i] >> v2[i];
		for (int i = 0; i < n; ++i)
			ifs >> cnt1[i] >> v1[i];

		long long res = 0;
		for (int d1 = 0; d1 < n; ++d1)
			for (int d2 = d1; d2 < n; ++d2)
			{
				vector<long long> cntm = cnt1;
				long long s = 0;
				long long cnt = cnt2[0];
				for (int i = 0; i <= d1; ++i)
				{
					if (v1[i] == v2[0]) 
					{
						long long z = min(cnt, cntm[i]);
						s += z;
						cnt -= z;
						cntm[i] -= z;
					}
				}
				if (m > 1) 
				{
					long long cnt = cnt2[1];
					for (int i = d1; i <= d2; ++i)
					{
						if (v1[i] == v2[1]) 
						{
							long long z = min(cnt, cntm[i]);
							s += z;
							cnt -= z;
							cntm[i] -= z;
						}
					}
				}
				if (m > 2) 
				{
					long long cnt = cnt2[2];
					for (int i = d2; i < n; ++i)
					{
						if (v1[i] == v2[2]) 
						{
							long long z = min(cnt, cntm[i]);
							s += z;
							cnt -= z;
							cntm[i] -= z;
						}
					}
				}
				res = max(res, s);
			}
		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
