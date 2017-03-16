#include <iostream>
#include <stdio.h>
#include <string>
#pragma warning(disable:4996)

using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define maxN 1000000

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("tjg.out", "w", stdout);
	int T, n;
	string s; 
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int ans = 0, people = 0;
		cin >> n >> s;
		for (int i = 0; i < s.size(); i++)
			if (s[i] > '0')
			{
				if (people < i) {
					ans += i - people;
					people = i;
				}
				people += s[i] - '0';
			}
		cout << "Case #" << t << ": " << ans << endl;
	}
}