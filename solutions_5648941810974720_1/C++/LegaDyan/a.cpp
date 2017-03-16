#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#define rep(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

int a[100009], s[100009];

int calc (char ch)
{
	return ch - 'A' + 1;
}

int cacl (char ch)
{
	return ch - 'A' + 1;
}

int main ()
{
	//freopen ("1.in", "r", stdin); freopen ("1.out", "w",stdout); 
	int ti; cin >> ti;
	rep (ff, 1, ti)
	{
		memset (a, 0, sizeof (a));
		memset (s, 0, sizeof (s));
		string ss;
		cin >> ss;
		int n = ss.length ();
		rep (i, 0, n - 1)
			s[calc (ss[i])]++;
		//rep (i, 1, 26) printf ("%d %d\n", i, s[i]);
		rep (i, 1, s[calc ('Z')])
			a[0]++, s[calc ('E')] --, s[calc ('R')] --, s[calc ('O')]--;
		rep (i, 1, s[calc ('W')])
			a[2]++, s[calc ('T')] --, s[calc ('O')]--;
		rep (i, 1, s[calc ('X')])
			a[6]++, s[calc ('S')]--, s[cacl ('I')]--;
		rep (i, 1, s[calc ('U')])
			a[4]++, s[calc ('F')]--, s[cacl ('O')]--, s[calc ('R')]--;
		rep (i, 1, s[calc ('O')])
			a[1]++, s[calc ('N')]--, s[cacl ('E')]--;
		rep (i, 1, s[calc ('F')])
			a[5]++, s[calc ('V')]--, s[cacl ('I')]--, s[calc ('E')]--;
		rep (i, 1, s[calc ('G')])
			a[8]++, s[calc ('E')]--, s[cacl ('I')]--, s[calc ('H')]--;
		rep (i, 1, s[calc ('V')])
			a[7]++, s[calc ('S')]--, s[cacl ('E')]-= 2, s[calc ('N')]--;
		rep (i, 1, s[calc ('I')])
			a[9]++, s[calc ('E')]--, s[cacl ('N')]--;
		rep (i, 1, s[calc ('R')])
			a[3]++;
		//rep (i, 0, 9) printf ("--------------- %d %d\n", i, a[i]);
		int cnt = 0, ans[10000];
		rep (i, 0, 9)
			rep (j, 1, a[i])
				ans[++cnt] = i;
		printf ("Case #%d: ", ff);
		rep (i, 1, cnt)
			printf ("%d", ans[i]);
		cout << endl;
	}
	return 0;
}
