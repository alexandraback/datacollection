#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
typedef long long ll;

char s[128];

string get_first (string s)
{
	string mx = s;
	for (int i = 0; i < s.size (); i ++){
		rotate (s.begin (), s.begin () + 1, s.end ());
		mx = max (mx, s);
	}
	return mx;
}

int
main ()
{
	freopen ("Cl.in","r",stdin);
	freopen ("Cl.out","w",stdout);
	int t;
	scanf ("%d", &t);
	for (int tc = 1; tc <= t; tc ++){
		map <string, int> m;
		int a, b;
		scanf ("%d %d", &a, &b);
		for (int i = a; i <= b; i ++){
			sprintf (s, "%d", i);
			m[get_first (string (s))] ++;
		}
		ll ans = 0;
		for (map<string,int>::iterator it = m.begin (); it != m.end (); it ++){
			ll n = it->second;
			ans += n*(n-1)/2;
		}
		printf ("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}