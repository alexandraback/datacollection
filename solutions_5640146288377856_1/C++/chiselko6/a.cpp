#include <bits/stdc++.h>

#define ll long long
#define __(x) cout << #x << " : " << x << endl;
#define out(a, i, n) for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

#define INOUT
//#define TIME
//#define TEST	

using namespace std;

void print(int test, ll ans)
{
	cout << "Case #" << test << ": " << ans << endl;
	//printf("Case #%d: %d\n", test, ans);
}

void gen()
{
	freopen("input.txt", "w", stdout);
	
}

int main()
{
#ifdef INOUT
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
#ifdef TEST
	cout << 1;
	gen(); return 0;
#endif
	int tests;
	cin >> tests;
	ll ans = 0;
	for (int test = 1; test <= tests; test++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		ll t = c / w;
		ll ans = t * r + w;
		if (c % w == 0)
			ans--;
		print(test, ans);
	}

#ifdef TIME
	cerr << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
