#include <iostream>

using namespace std;

const int a[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};
const int b[4][4] = {
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};

char w[300];

string solve()
{
	w['i'] = 1;
	w['j'] = 2;
	w['k'] = 3;
	int l;
	long long x;
	cin >> l >> x;
	x = min(x, x % 4 + 12);
	string t;
	cin >> t;
	string s = "";
	for (int i = 0; i < x; i++)
		s += t;
	int cur = 0;
	int neg = 0;
	int i = 0; 
	for (; i < s.length(); i++)
	{
		neg ^= b[cur][w[s[i]]];
		cur = a[cur][w[s[i]]];
		if (!neg && cur == w['i'])
			break;
	}
	if (i == s.length())
		return "NO";
	cur = 0;
	neg = 0;
	for (i++; i < s.length(); i++)
	{
		neg ^= b[cur][w[s[i]]];
		cur = a[cur][w[s[i]]];
		if (!neg && cur == w['j'])
			break;
	}
	if (i == s.length())
		return "NO";
	cur = 0;
	neg = 0;
	for (i++; i < s.length(); i++)
	{
		neg ^= b[cur][w[s[i]]];
		cur = a[cur][w[s[i]]];
	}
	if (neg || cur != w['k'])
		return "NO";
	else
		return "YES";
}

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
		cout << "Case #" << tt << ": " << solve() << endl;

}
