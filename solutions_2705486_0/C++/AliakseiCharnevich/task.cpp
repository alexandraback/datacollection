#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
vector<string> v;
const pair<int, int> FAIL(100000,100000);
pair<int, int> prov(const string & s, const string & v, int start, int L)
{
	int last = start - L;
	int cnt = 0;
	for (int i = start; i < start + v.size(); i++)
	{
		if (v[i - start] != s[i])
		{
			if (i - last < 5)
			{
				return FAIL;
			}
			else
			{
				cnt++;
				last = i;
			}
		}
	}
	int LST = v.size() + start - last;
	if (LST > 5)
		LST = 5;
	return make_pair(cnt, LST);
}
int ANS()
{
	string s;
	cin >> s;
	int mas[51][6];
	for (int i =0; i <= 50; i++)
		for (int k =0; k <= 5; k++)
		mas[i][k] = 100000;
	mas[0][5] = 0;
	for (int i = 1; i <= s.size(); i++)
	{
		for (int k = 1; k <= 5; k++)
		{
			int ss = 0;
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j].size() + i - 1> s.size())
					continue;
				pair<int, int> f = prov(s,v[j],i-1, k);
				if (f == FAIL)
					continue;
				int r = f.first;
				int last_pos = f.second;
				int sz= v[j].size();
				mas[i-1 + sz][last_pos] = min(mas[i-1 + sz][last_pos], mas[i-1][k] + r);
				ss++;
			}
		}
	}
	int m = 100000;
	for (int i = 1; i <= 5; i++)
		m = min(m, mas[s.size()][i]);
	return m;
}

void input_dict()
{
	ifstream inp_d("dict.txt");
	string s;
	v.reserve(521196);
	while(inp_d >> s)
		v.push_back(s);
	inp_d.close();
}
int main()
{
	ios_base::sync_with_stdio(false);
	input_dict();
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TEST = 0;
	cin >> TEST;
	for (int tt = 1; tt <= TEST; tt++)
	{
		cout <<	"Case #" << tt <<": " << ANS() << "\n";
	}
}