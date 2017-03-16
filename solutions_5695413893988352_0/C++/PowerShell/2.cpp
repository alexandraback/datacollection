#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 999999999
using namespace std;

string c,j;

string to_string(long long a)
{
    string ans = "";
    while(a!=0)
    {
        int dig = a%10;
        ans+=(char)'0'+dig;
        a/=10;
    }
    reverse(ans.begin(), ans.end());
    while(ans.size() < c.size())
    {
		ans = '0' + ans;
	}
    return ans;
}


void solve()
{
	cin >> c >> j;
	vector<int>cv,jv;
	for(ll i=0;i<999;i++)
	{
		string nc = to_string(i);
		bool pos = true;
		if(nc.size() != c.size()) break;
		for(int jj=0;jj<c.size();jj++)
		{
			if(c[jj] != '?')
			{
				if(c[jj] != nc[jj]) pos = false;
			}
		}
		if(pos)
		{
			cv.push_back(i);
		}
	}
	for(ll i=0;i<999;i++)
	{
		string nc = to_string(i);
		bool pos = true;
		if(nc.size() != j.size()) break;
		for(int jj=0;jj<c.size();jj++)
		{
			if(j[jj] != '?')
			{
				if(j[jj] != nc[jj]) pos = false;
			}
		}
		if(pos)
		{
			jv.push_back(i);
		}
	}
	int mn = 999999999;
	int cans, jans;
	for(int i=0;i<cv.size();i++)
	{
		for(int j=0;j<jv.size();j++)
		{
			if(mn > abs(cv[i] - jv[j]))
			{
				mn = abs(cv[i] - jv[j]);
				cans = cv[i];
				jans = jv[j];
			}
		}
	}
	
	cout << to_string(cans) << " " << to_string(jans) << "\n";
	
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
