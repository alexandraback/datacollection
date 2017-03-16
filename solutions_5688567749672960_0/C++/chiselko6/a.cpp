#include <bits/stdc++.h>

#define ll long long
#define __(x) cout << #x << " : " << x << endl;
#define out(a, i, n) for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

#define INOUT
//#define TIME	

using namespace std;

void print(int test, int ans)
{
	cout << "Case #" << test << ": " << ans << endl;
	//printf("Case #%d: %d\n", test, ans);
}

vector <int> get(ll n)
{
	vector <int> a;
	while (n)
	{
		a.pb(n % 10);
		n /= 10;
	}
	reverse(a.begin(), a.end());
	return a;
}

ll num(vector <int> a)
{
	ll ans = 0;
	int pos = 0;
	while (pos < a.size() && a[pos] == 0)
		pos++;
	for (int i = pos; i < a.size(); i++)
		ans = ans * 10 + a[i];
	if (pos == a.size()) return 0;
	if (a[pos] == 1) ans--;
	return ans;
}

ll res(vector <int> a)
{
	ll len = a.size() / 2;
	ll ans = 0;
	vector <int> first;
	vector <int> second;
	if (a.size() % 2 == 0)
	{
		for (int i = len - 1; i >= 0; i--)
		{
			first.pb(a[i]);
		}
		for (int i = len; i < a.size(); i++)
		{
			second.pb(a[i]);
		}
		return num(first) + num(second);
	}
	for (int i = len - 1; i >= 0; i--)
	{
		first.pb(a[i]);
	}
	for (int i = len; i < a.size(); i++)
	{
		second.pb(a[i]);
	}
	ll ans1 = num(first) + num(second) + 1;
	first.clear();
	second.clear();
	for (int i = len; i >= 0; i--)
		first.pb(a[i]);
	for (int i = len + 1; i < a.size(); i++)
		second.pb(a[i]);
	ll ans2 = num(first) + num(second);
	return min(ans1, ans2);
}

ll d[20];

int main()
{
#ifdef INOUT
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	d[1] = 10;
	d[2] = 29;
	ll ttt = 10;
	for (int i = 3; i < 20; i++)
	{
		ttt *= 10;
		d[i] = ttt + 9 + d[i-1];
	}
	//cout << d[6] << endl;
	int tests;
	cin >> tests;
	ll ans = 0;
	for (int test = 1; test <= tests; test++)
	{
		ll n;
		cin >> n;
		if (n / 10 == 0)
		{
			print(test, n);
			continue;
		}
		vector <int> a = get(n);
		
		bool flag = false;
		for (int i = 1; i < a.size(); i++)
		{
			if (a[i] != 0)
				flag = true;
		}
		if (!flag)
		{
			if (a[0] == 1)
			{
				print(test, d[a.size() - 1]);
				continue;
			}
			n -= 1;
			a = get(n);
		}
		ll ans = res(a);
		//if (a[0] == 1) ans--;
		if (!flag) ans++;
		print(test, ans + d[a.size() - 1]);
	}

#ifdef TIME
	cout << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
