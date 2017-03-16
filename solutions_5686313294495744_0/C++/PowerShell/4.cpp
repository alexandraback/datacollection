#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 999999999
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<pair<string , string> >v;
	
	for(int i=0;i<n;i++)
	{
		string ff,ss;
		cin >> ff >> ss;
		v.push_back(make_pair(ff,ss));
	}
	int ans = 0;
	for(int i=1;i< (1<<n);i++)
	{
		set<string>first, second;
		vector<string>findfirst, findsecond;
		int temp = 0;
		for(int j=0;j<v.size();j++)
		{
			if(i & (1 << j))
			{
				first.insert(v[j].first);
				second.insert(v[j].second);
			}
			else
			{
				findfirst.push_back(v[j].first);
				findsecond.push_back(v[j].second);
			}
		}
		for(int j=0;j<findfirst.size();j++)
		{
			if(first.find(findfirst[j]) != first.end() && second.find(findsecond[j]) != second.end()) temp++;
		}
		ans = max(temp, ans);
	}
	cout << ans << "\n";
}
int main()
{
	int tc;
	cin >> tc;
	for(int i=1;i<=tc;i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}
