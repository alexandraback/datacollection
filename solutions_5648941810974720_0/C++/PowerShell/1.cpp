#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 999999999
using namespace std;
vector<string>v;
multiset<char>ms;
string ans;
bool done;
void dfs(int now)
{
	//cout << ans << " " << now << endl;
	if(ms.size() == 0)
	{
		cout << ans << "\n";
		done = 1;
		return;
	}
	if(now == 10)
	{
		return;
	}
	for(int j=now;j<v.size();j++)
	{
		if(done) break;
		string nows = v[j];
		int i;
		for(i=0;i<nows.size();i++)
		{
			if(ms.find(nows[i]) != ms.end())
			{
				ms.erase(ms.find(nows[i]));
			}
			else break;
		}
		if(i == nows.size())
		{
			ans += j + '0';
			dfs(now);
			ans.pop_back();
			for(int k=0;k<nows.size();k++)
			{
				ms.insert(nows[k]);
			}
		}
		else
		{
			for(int k=0;k<i;k++)
			{
				ms.insert(nows[k]);
			}
		}
	}
	if(ms.size() == 0)
	{
		cout << ans << "\n";
		done = 1;
		return;
	}
}

void solve()
{
	string s;
	cin >> s;
	v.clear();
	ms.clear();
	done = false;
	ans = "";
	v.push_back("ZERO");
	v.push_back("ONE");
	v.push_back("TWO");
	v.push_back("THREE");
	v.push_back("FOUR");
	v.push_back("FIVE");
	v.push_back("SIX");
	v.push_back("SEVEN");
	v.push_back("EIGHT");
	v.push_back("NINE");
	for(int i=0;i<s.size();i++)
	{
		ms.insert(s[i]);
	}
	dfs(0);
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
