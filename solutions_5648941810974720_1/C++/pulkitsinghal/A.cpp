#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define ll long long

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int cnt[26];

void reduce(int i)
{
	for(int j=0;j<digits[i].size();++j)
		cnt[digits[i][j]-'A']--;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc)
	{
		string s;
		cin >> s;
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<s.size();++i)
			++cnt[s[i]-'A'];
		string res;
		while(cnt['Z'-'A'])
		{
			reduce(0);
			res += "0";
		}
		while(cnt['W'-'A'])
		{
			reduce(2);
			res += "2";
		}
		while(cnt['G'-'A'])
		{
			reduce(8);
			res += "8";
		}
		while(cnt['H'-'A'])
		{
			reduce(3);
			res += "3";
		}
		while(cnt['R'-'A'])
		{
			reduce(4);
			res += "4";
		}
		while(cnt['O'-'A'])
		{
			reduce(1);
			res += "1";
		}
		while(cnt['X'-'A'])
		{
			reduce(6);
			res += "6";
		}
		while(cnt['S'-'A'])
		{
			reduce(7);
			res += "7";
		}
		while(cnt['V'-'A'])
		{
			reduce(5);
			res += "5";
		}
		while(cnt['N'-'A'])
		{
			reduce(9);
			res += "9";
		}
		sort(res.begin(),res.end());
		cout << "Case #" << tc << ": " << res << endl;
	}
	return 0;
}
