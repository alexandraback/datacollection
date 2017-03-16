#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int b[200];
int L;
vector<string> v;

void check(string cur)
{
	vector<int> a;
	a.clear();
	for (int i = 0; i < cur.size(); i ++)
		a.push_back(cur[i] - 48);
	
	memset(b, 0, sizeof(b));
	int Lb;
	for (int i = 1; i <= a.size(); i ++)
		for (int j = 1; j <= a.size(); j ++)
			b[i + j - 1] += a[i - 1] * a[j - 1];
	for (int i = 1; ; i ++)
	{
		if (! b[i] && i > 2 * a.size() - 1)
		{
			Lb = i - 1; break;
		}
		b[i + 1] += b[i] / 10;
		b[i] %= 10;
	}
	
	for (int i = 1; i <= Lb; i ++)
		if (b[i] != b[Lb - i + 1]) return ;
	
	string oo = "";
	for (int i = 1; i <= Lb; i ++)
		oo += char(48 + b[i]);
	
	v.push_back(oo);
}

void dfs(int x, string s)
{
	if (x == L + 1)
	{
		string cur, tmp;
		cur = tmp = s;
		reverse(tmp.begin(), tmp.end());
		cur += tmp;
		check(cur);
		
		cur.erase(L, 1);
		check(cur);
		return ;
	}
	//0
	if (x > 1) 
		dfs(x + 1, s + "0");
	//1
	dfs(x + 1, s + "1");
	//2
	if (x == 1 || x == L)
		dfs(x + 1, s + "2");
}

int cmp(string a, string b)
{
	return a.size() < b.size() || a.size() == b.size() && a < b;
}

int work(string s)
{
	int ans = 0;
	for (int i = 0; i < v.size(); i ++)
		if (v[i].size() < s.size() || v[i].size() == s.size() && v[i] <= s)
			ans ++;
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	v.clear();
	v.push_back("9");
	for (L = 1;	L <= 6; L ++)
		dfs(1, "");
	sort(v.begin(), v.end(), cmp);
	string tmp;
	int T; cin >> T; getline(cin, tmp);
	for (int t = 1; t <= T; t ++)
	{
		string s, s1, s2;
		getline(cin, s);
		int pos = s.find(" ");
		s1 = s.substr(0, pos);
		s2 = s.substr(pos + 1);
		//
		int ans = work(s2) - work(s1);
		for (int i = 0; i < v.size(); i ++)
			if (v[i] == s1) ans ++;
		cout << "Case #" << t << ": " << ans << endl;
	}		
	
	
	return 0;
}
