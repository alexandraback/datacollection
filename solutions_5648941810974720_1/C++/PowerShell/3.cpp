#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 999999999
using namespace std;

int get_num(string s)
{
	if(s == "ZERO") return 0;
	if(s == "ONE") return 1;
	if(s == "TWO") return 2;
	if(s == "THREE") return 3;
	if(s == "FOUR") return 4;
	if(s == "FIVE") return 5;
	if(s == "SIX") return 6;
	if(s == "SEVEN") return 7;
	if(s == "EIGHT") return 8;
	if(s == "NINE") return 9;
}

void solve()
{
	string s;
	cin >> s;
	vector<string>v;
	multiset<char>ms;
	string ans = "";
	v.push_back("ZERO");
	v.push_back("TWO");
	v.push_back("FOUR");
	v.push_back("SIX");
	v.push_back("EIGHT");
	v.push_back("ONE");
	v.push_back("THREE");
	v.push_back("SEVEN");
	v.push_back("FIVE");
	v.push_back("NINE");
	for(int i=0;i<s.size();i++)
	{
		ms.insert(s[i]);
	}
	
	for(int i=0;i<v.size();i++)
	{
		string now = v[i];
		int it = 0;
		vector<char>temp;
		while(1)
		{
			if(it == now.size())
			{
				it = 0;
				temp.clear();
				ans += get_num(now) + '0';
			}
			if(ms.find(now[it]) != ms.end())
			{
				temp.push_back(now[it]);
				ms.erase(ms.find(now[it]));
				it++;
			}
			else break;
		}
		for(int j=0;j<temp.size();j++)
		{
			ms.insert(temp[j]);
		}
	}
	assert(ms.size() == 0);
	sort(ans.begin(), ans.end());
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
