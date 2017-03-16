#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int npow[4] = {1, 10, 100, 1000};


bool match(string& s, string& t)
{
	if (s.size() != t.size())
		return false;

	for (int i = 0; i < s.size(); i++)
	{
		if (t[i] != '?' and s[i] != t[i])
			return false;
	}
	return true;
}

int digit_count(int x)
{
	int ans = 0;
	while(x)
	{
		ans++;
		x/=10;
	}
	return ans;
}

string getstring(int x, int sz)
{
	string ret;
	int xx = x;
	while(xx)
	{
		ret.push_back('0' + xx%10);
		xx/=10;
	}

	if (digit_count(x) < sz)
	{
		int dif = sz - digit_count(x);
		while(dif--)
		{
			ret.push_back('0');
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	int T, t = 0;
	scanf("%d", &T);

	while(T--)
	{
		string co, ja;
		cin >> co >> ja;
		int n = co.size();

		int aabs = INF, apc = INF, apj = INF;
		
		for (int i = 0; i < npow[n]; i++)
		{
			//printf("at i = %d made ", i);
			string cc = getstring(i, n);
			//cout << cc << '\n';
			if (!match(cc, co)) continue;
			for (int j = 0; j < npow[n]; j++)
			{
				string cj = getstring(j, n);
				if (!match(cj, ja)) continue;
				int cabs = abs(i-j);
				if (cabs < aabs)
				{
					aabs = cabs;
					apc = i;
					apj = j;
				}
				else if (cabs == aabs)
				{
					if (i < apc)
					{
						apc = i;
						apj = j;
					}
					else if (i == apc and j < apj)
					{
						apj = j;
					}
				}
			}
		}
		string sapc = getstring(apc, n), sapj = getstring(apj, n);
		printf("Case #%d: ", ++t);
		cout << sapc << " " << sapj << '\n';
	}
	return 0;
}
