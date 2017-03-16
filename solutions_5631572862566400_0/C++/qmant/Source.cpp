#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <iomanip>
#define ll long long
#define itn int
#define eps 1e-10
#define mp make_pair
#define pb push_back
#define inf 1e9 
#define vi vector<itn>
#define vvi vector<vi>
#define vii vector<pair<itn,itn> >
#define vvii vector<vii>
#define itn long long
using namespace std;

int qwert;

int rek(int ch, int lch, vector<int> &a,vector<int> &us)
{
	int ans = -1;
	us[ch] = 1;
	if (a[ch] == lch)
	{
		ans = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (us[i] == 0)
			{
				ans = max(ans, rek(i, ch, a, us));
			}
		}
	}
	else
	{
		if (us[a[ch]] == 0)
		{
			ans = rek(a[ch], ch, a, us);
		}
		else if (a[ch] == qwert)
			ans = 0;
	}
	us[ch] = 0;
	if (ans != -1)
		ans++;
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
#endif
	itn qw;
	cin >> qw;
	for (int i = 0; i < qw; i++)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int q = 0; q < n; q++)
		{
			cin >> a[q];
			a[q]--;
		}
		int ans = 0;
		vector<int> used(n, 0);
		for (int q = 0; q < n; q++)
		{
			qwert = q;
			ans = max(ans, rek(q, -1, a, used));
		}



		cout << "Case #" << i + 1 << ": " << ans << endl;
	}


	return 0;
}