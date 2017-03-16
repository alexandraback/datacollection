#include <bits/stdc++.h>

using namespace std;
#define MAX 30
int t,n;
char s1[MAX],s2[MAX];
vector<pair<string, string> > v;
int ans;

void solve(int curr, vector<int> vtmp)
{
	if (curr == v.size())
	{
		set<string> fw,sw;
		set<pair<string,string> > bw; 
		for (int i = 0; i < vtmp.size(); ++i)
		{
			fw.insert(v[vtmp[i]].first);
			sw.insert(v[vtmp[i]].second);
			bw.insert(v[vtmp[i]]);
		}

		int local = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (!bw.count(v[i]))
			{	
				if (fw.count(v[i].first) && sw.count(v[i].second))
				{
					local++;
				}
				else
					return;
			}
		}

		if (vtmp.size() + local == v.size())
		{
			ans = max(ans, local);
		}
		return;
	}
	solve(curr + 1, vtmp);
	vtmp.push_back(curr);
	solve(curr + 1, vtmp);
}
int main(void)
{
	scanf("%d ",&t);

	for (int cases = 1; cases <= t; ++cases)
	{
		scanf("%d ",&n);
		v.clear();
		for (int i = 0; i < n; ++i)
		{
			scanf("%s %s",s1, s2);
			v.push_back(make_pair(s1,s2));
		}
		ans = 0;
		vector<int> vtmp;
		solve(0, vtmp);
		printf("Case #%d: %d\n",cases,ans);
	}
	return 0;
}