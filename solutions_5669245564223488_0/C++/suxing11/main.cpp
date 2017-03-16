# include <stdio.h>
# include <algorithm>
# include <string>
# include <iostream>
# include <cstring>

using namespace std;



int a[100] ;
string str[100];
int n;

int tab[300];


int test(string s)
{
	int i, len = s.length();
	memset (tab, 0, sizeof(tab));
	tab[s[0]] = 1;
	for (i = 1; i < len; i++)
	{
		if (s[i] != s[i-1] && tab[s[i]]) return 0;
		tab[s[i]] = 1;
	}
	return 1;
}


int main ()
{
	int T, cas, ans, i;
	string s;
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("B_small.txt", "w", stdout);
//	scanf ("%d", &T);
	cin >> T;
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d", &n);
		for (i = 0; i < n; i++)
			cin >> str[i];
		for (i = 0; i < n; i++)
			a[i] = i;
		
		ans = 0;
		do{
			s = "";
			for (i = 0; i < n; i++)
				s += str[a[i]];
			if (test(s)) ans++;
		}while (next_permutation(a, a+n));
		printf ("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
