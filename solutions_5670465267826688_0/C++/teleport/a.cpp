#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 alfdjasldfjeao
#define y1 safiodjafis

int p[4][4] = {{1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1}};

struct node {
	int x;
};

node operator *(const node &fir, const node &sec)
{
	node ans;
	ans.x = p[abs(fir.x) - 1][abs(sec.x) - 1];
	if (fir.x * sec.x < 0)
		ans.x *= -1;
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	map < char, int > m;
	m['i'] = 2, m['j'] = 3, m['k'] = 4;
	for (int test = 1; test <= T; test++)
	{
		ll len;int n;
		cin >> n >> len;
		string s;
		cin >> s;
		node cur;
		cur.x = 1;
		int fir = -1;
		for (int i = 0; i < 4 * s.length(); i++)
		{
			node curnode;
			curnode.x = m[s[i % s.length()]];
			cur = cur * curnode;
			if (cur.x == 2)
			{
				fir = i + 1;
				break;
			}
		}
		int sec = -1;
		cur.x = 1;
		for (int i = 0; i < 4 * s.length(); i++)
		{
			node curnode;
			curnode.x = m[s[s.length() - i % s.length() - 1]];
			cur = curnode * cur;
			if (cur.x == 4)
			{
				sec = i + 1;
				break;
			}
		}
		cur.x = 1;
		for (int i = 0; i < s.length(); i++)
		{
			node curnode;
			curnode.x = m[s[i]];
			cur = cur * curnode;
		}
		string ans = "NO";
		bool flag = abs(cur.x) != 1 && len % 4 == 2 || cur.x == -1 && len % 2 == 1;
		if (flag && fir != -1 && sec != -1 && fir + sec <= len * s.length())
			ans = "YES";
		cout << "Case #" << test << ": " << ans << "\n";
	}
	
}





