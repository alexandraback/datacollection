#include <bits/stdc++.h>

using namespace std;
int debug = 1;
typedef long long LL;
typedef pair<string,string> ps;

string itoa(int x, int len)
{
	string s = "";
	while (len--)
	{
		s += char('0'+x%10);
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int satoi(string s) { return atoi(s.c_str()); }

vector<string> Clist, Jlist;
void fill (vector<string> &l, string s, int p, int n)
{
	if (p == n)
	{
		l.push_back(s);
		return;
	}
	if (isdigit(s[p]))
	{
		fill(l, s, p+1, n);
	}
	else
	{
		for (char d = '0'; d <= '9'; d++)
		{
			s[p] = d;
			fill(l, s, p+1, n);
		}
	}
	return;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		string C, J;
		cin >> C >> J;
		int n = C.size();
		int m = pow(10, n);
		Clist.clear();
		Jlist.clear();
		fill(Clist, C, 0, n);
		fill(Jlist, J, 0, n);
		vector<ps> res;
		for (auto x : Clist)
		{
			for (auto y : Jlist)
			{
				res.push_back({x,y});
			}
		}
		sort(res.begin(), res.end());
		int best = 1<<30;
		string bestc = "", bestj = "";
		for (auto x : res)
		{
			int d = abs(satoi(x.first)-satoi(x.second));
			if (d < best)
			{
				best = d;
				bestc = x.first;
				bestj = x.second;
			}
		}

		cout << "Case #" << testCase << ": " << bestc << " " << bestj << endl;

	}
	return 0;
}
