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
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		int q;
		string s;
		cin >> q >> s;
		int cur = 0;
		int ans = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int x = s[i] - '0';
			if (cur < i)
				ans += i - cur, cur += i - cur;
			cur += x;
		}
		cout << "Case #" << test << ": " << ans << "\n";
	}
}





