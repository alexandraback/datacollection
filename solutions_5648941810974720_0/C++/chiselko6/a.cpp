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

void print(int test, string ans)
{
	cout << "Case #" << test << ": " << ans << endl;
	//printf("Case #%d: %d\n", test, ans);
}

map <char, int> d;

void clear(char ch, char from)
{
	d[ch] -= d[from];
}

int main()
{
#ifdef INOUT
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	
	int tests;
	cin >> tests;
	ll ans = 0;

	for (int test = 1; test <= tests; test++)
	{
		d.clear();
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			d[s[i]]++;
		}
		map<int, int> ans;
		ans[0] = d['Z']; 
		clear('E', 'Z'); clear('R', 'Z'); clear('O', 'Z'); clear('Z', 'Z'); 
		ans[2] = d['W'];
		clear('T', 'W'); clear('O', 'W'); clear('W', 'W'); 
		ans[4] = d['U'];
		clear('F', 'U'); clear('O', 'U'); clear('R', 'U'); clear('U', 'U'); 
		ans[6] = d['X'];
		clear('S', 'X'); clear('I', 'X'); clear('X', 'X'); 
		ans[5] = d['F'];
		clear('I', 'F'); clear('V', 'F'); clear('E', 'F'); clear('F', 'F'); 
		ans[7] = d['V'];
		clear('S', 'V'); clear('E', 'V'); clear('E', 'V'); clear('N', 'V'); clear('V', 'V'); 
		ans[8] = d['G'];
		clear('E', 'G'); clear('I', 'G'); clear('H', 'G'); clear('T', 'G'); clear('G', 'G'); 
		ans[9] = d['I'];
		clear('N', 'I'); clear('N', 'I'); clear('E', 'I');clear('I', 'I');
		ans[1] = d['O'];
		clear('N', 'O'); clear('E', 'O'); clear('O', 'O'); 
		ans[3] = d['T'];
		string res = "";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < ans[i]; j++)
				res += (char) '0' + i;
		}

		print(test, res);
	}

#ifdef TIME
	cerr << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
