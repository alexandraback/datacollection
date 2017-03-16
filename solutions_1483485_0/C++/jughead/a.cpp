#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#define ll long long
#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair <int, int>
#define ff first
#define ss second
#define ldb long double
#define sqr(a) ((a) * (a))
#define nextLine() {int c = 0; while((c = getchar()) != 10 && c != EOF);}
#define addEdge(a, b) next[edges] = first[a]; first[a] = edges; end[edges] = a;
#define debug(a) cerr << #a << " = " << (a) << " ";
#define debugl(a) cerr << #a << " = " << (a) << "\n";
const ldb eps = 1e-9;
const ldb pi = fabsl(atan2l(0.0, -1.0));
const ll inf = 1 << 28;
using namespace std;
#define problem "a"

char s[123123];
char t[123123];
int mapp[256];
//ifstream in(problem ".ans");

void init()
{
mapp['a'] = 'y';
mapp['b'] = 'h';
mapp['c'] = 'e';
mapp['d'] = 's';
mapp['e'] = 'o';
mapp['f'] = 'c';
mapp['g'] = 'v';
mapp['h'] = 'x';
mapp['i'] = 'd';
mapp['j'] = 'u';
mapp['k'] = 'i';
mapp['l'] = 'g';
mapp['m'] = 'l';
mapp['n'] = 'b';
mapp['o'] = 'k';
mapp['p'] = 'r';
mapp['q'] = 'z';
mapp['r'] = 't';
mapp['s'] = 'n';
mapp['t'] = 'w';
mapp['u'] = 'j';
mapp['v'] = 'p';
mapp['w'] = 'f';
mapp['x'] = 'm';
mapp['y'] = 'a';
mapp['z'] = 'q';

}

void load()
{
}

void solve(int test_number)
{
	cerr << "Case #" << test_number << "\n";
	gets(s);
/*	in.getline(t, 123123);
	for (int i = 0; s[i] != 0; i++)
	{
		if (mapp[s[i]] == -1 && s[i] != ' ')
			mapp[s[i]] = t[i];
		else if (s[i] != ' ' && mapp[s[i]] != t[i])
		{
			cerr << "Duplicate mappings\n";
			cerr << s[i] << " " << (int)t[i] << " and " << mapp[s[i]] << "\n";
			exit(1);
		}
	}
	*/
	cout << "Case #" << test_number << ": ";
	for (int i = 0; s[i] != 0; i++)
	{
		if (s[i] != ' ')
			s[i] = mapp[s[i]];
	}
	cout << s << "\n";
}

int main()
{
	memset(mapp, -1, sizeof(mapp));
	freopen(problem ".in", "rt", stdin);
	freopen(problem ".out", "wt", stdout);
	int t;
	cin >> t;
	gets(s);
	init();
	for (int i = 0; i < t; i++)
	{
		load();
		solve(i + 1);
	}
/*	mapp['z'] = 'q';
	mapp['q'] = 'z';
	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << "mapp['" << char(i) << "'] = '" << char(mapp[i]) << "';\n";
	}
	*/
	return 0;
}

