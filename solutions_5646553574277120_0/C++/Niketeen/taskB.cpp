#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>

using namespace std;
typedef long long ll;
const double eps = 1e-9;
const int mod = 1e9 + 7;

struct sost
{
	int mx;
	int len;
	bitset<31> bs;
};

int c, d, m;
int count(sost a)
{
	int cnt = 0;
	for (int i = 0; i <= m; ++i)
	{
		cnt += a.bs[i];
	}
	return cnt;
}


int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t)
	{
		cin >> c >> d >> m;
		vector<int> v(d);
		for (int i = 0; i < d; ++i)
		{
			cin >> v[i];
		}
		sost st;
		st.mx = 0;
		st.len = 0;
		
		for (int i = 0; i < (1 << d); ++i)
		{
			int sm = 0;
			for (int j = 0; j < d; ++j)
			{
				
				if (i & (1<<j))
				{
					sm += v[j];
				}
				
			}
			if (sm <= m)
				st.bs[sm] = 1;
		}

		queue<sost> q;
		q.push(st);
		int ans = 0;
		while (!q.empty())
		{
			sost cur = q.front();
			q.pop();
			int curcnt = count(cur);
			if (curcnt == m + 1)
			{
				ans = cur.len;
				break;
			}

			for (int i = cur.mx + 1; i <= m; ++i)
			{
				sost next = cur;
				next.mx = i;
				next.len++;
				for (int j = 0; j <= m; ++j)
				{
					if (next.bs[j] && j + i <= m)
					{
						next.bs[j + i] = 1;
					}
				}
				if (count(next) > curcnt)
				{
					q.push(next);
				}
			}
		}

		
		printf("Case #%d: %d\n", t, ans);

		//cout << "Case #" << t << ": " << ans << "\n";

	}



	return 0;
}