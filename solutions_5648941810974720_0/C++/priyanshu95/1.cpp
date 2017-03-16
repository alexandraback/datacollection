#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back

using namespace std;

int ct[30] = {0}, ct_num[10] = {0};

void dec_ct(int num, int amt)
{
	ct_num[num] += amt;
	if(num == 0)
	{
		ct['Z'-'A'] -= amt;
		ct['E'-'A'] -= amt;
		ct['R'-'A'] -= amt;
		ct['O'-'A'] -= amt;
	}
	else if (num == 1)
	{
		ct['O'-'A'] -= amt;
		ct['N'-'A'] -= amt;
		ct['E'-'A'] -= amt;
	}
	else if(num == 2)
	{
		ct['T'-'A'] -= amt;
		ct['W'-'A'] -= amt;
		ct['O'-'A'] -= amt;
	}
	else if(num == 3)
	{
		ct['T'-'A'] -= amt;
		ct['H'-'A'] -= amt;
		ct['R'-'A'] -= amt;
		ct['E'-'A'] -= amt;
		ct['E'-'A'] -= amt;
	}
	else if (num == 4)
	{
		ct['F'-'A'] -= amt;
		ct['O'-'A'] -= amt;
		ct['U'-'A'] -= amt;
		ct['R'-'A'] -= amt;
	}
	else if (num == 5)
	{
		ct['F'-'A'] -= amt;
		ct['I'-'A'] -= amt;
		ct['V'-'A'] -= amt;
		ct['E'-'A'] -= amt;
	}
	else if (num == 6)
	{
		ct['S'-'A'] -= amt;
		ct['I'-'A'] -= amt;
		ct['X'-'A'] -= amt;
	}
	else if (num == 7)
	{
		ct['S'-'A'] -= amt;
		ct['E'-'A'] -= amt;
		ct['V'-'A'] -= amt;
		ct['E'-'A'] -= amt;
		ct['N'-'A'] -= amt;
	}
	else if (num == 8)
	{
		ct['E'-'A'] -= amt;
		ct['I'-'A'] -= amt;
		ct['G'-'A'] -= amt;
		ct['H'-'A'] -= amt;
		ct['T'-'A'] -= amt;
	}
	else if (num == 9)
	{
		ct['N'-'A'] -= amt;
		ct['I'-'A'] -= amt;
		ct['N'-'A'] -= amt;
		ct['E'-'A'] -= amt;
	}
}

int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		string s;
		cin >> s;
		memset(ct, 0, sizeof(ct));
		memset(ct_num, 0, sizeof(ct_num));
		for(int i = 0; i < s.size(); i++)
			ct[s[i] - 'A']++;
		dec_ct(6, ct['X'-'A']);
		dec_ct(0, ct['Z'-'A']);
		dec_ct(2, ct['W'-'A']);
		dec_ct(4, ct['U'-'A']);
		dec_ct(5, ct['F'-'A']);
		dec_ct(7, ct['S'-'A']);
		dec_ct(1, ct['O'-'A']);
		dec_ct(8, ct['G'-'A']);
		dec_ct(3, ct['T'-'A']);
		dec_ct(9, ct['E'-'A']);
		string ans;
		for(int i = 0; i < 10; i++)
		{
			while(ct_num[i] != 0)
			{
				ct_num[i]--;
				char c = '0'+i;
				ans += c;
			}
		}
		sort(ans.begin(), ans.end());
		cout << "Case #"<<t<< ": "<< ans << endl;
	}
}
