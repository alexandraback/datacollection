#include <bits/stdc++.h>

#define ll long long
#define __(x) cout << #x << " : " << x << endl;
#define out(a, i, n) for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

#define INOUT
#define TIME	

using namespace std;

void print(int test, int ans)
{
	cout << "Case #" << test << ": " << ans << endl;
	//printf("Case #%d: %d\n", test, ans);
}

int main()
{
#ifdef INOUT
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	
	int tests;
	cin >> tests;
	ll ans = 0;
	for (int test = 1; test <= tests; test++)
	{
		int n;
		cin >> n;
		vector < pair <string, string> > in;
		for (int i = 0; i < n; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			in.pb(mp(s1, s2));
		}
		vector < pair <string, string> > have;
		for (int i = 0; i < n; i++)
		{
			bool used1 = false, used2 = false;
			for (int j = 0; j < have.size(); j++)
			{
				used1 |= have[j].first == in[i].first;
				used2 |= have[j].second == in[i].second;
			}
			if (!used1 || !used2)
			{
				have.pb(in[i]);
			}
		}
		ans = in.size() - have.size();
		print(test, ans);
	}

#ifdef TIME
	cerr << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
