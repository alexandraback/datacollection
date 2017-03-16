#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <iomanip>
#define nextLine() { for (int c = getchar(); c != '\n' && c != EOF; c = getchar()); }
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long long LL;
typedef long double ldb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));
const int MAXN = 105;

int get(char c)
{
	assert('a' <= c && c <= 'z');
	return c - 'a';
}

char s[MAXN];
void load()
{
	gets(s);
}

const string mapping = "yhesocvxduiglbkrztnwjpfmaq";

void solve(int test)
{
	for (int i = 0, len = strlen(s); i < len; i++)
	{
		if (s[i] < 'a' || s[i] > 'z') continue;
		char c = mapping[get(s[i])];
		s[i] = c;
	}

	printf("Case #%d: %s\n", test, s);
}

void buildMapping()
{
	char enc[MAXN];
	char dec[MAXN];
	vector <int> par(26, -1);

	par[get('a')] = get('y');
	par[get('o')] = get('e');
	par[get('z')] = get('q');

	int examples;
	scanf("%d\n", &examples);

	for (int e = 0; e < examples; e++)
	{
		eprintf("example %d\n", e);
		gets(enc);
		gets(dec);

		int n = strlen(enc);
		assert(n == strlen(dec));
		for (int i = 0; i < n; i++)
		{
			if (enc[i] < 'a' || enc[i] > 'z') continue;
			assert('a' <= dec[i] && dec[i] <= 'z');

			int c1 = get(enc[i]);
			int c2 = get(dec[i]);

			if (par[c2] != -1 && par[c2] != c1) 
			{
				eprintf("%c to %c\n", enc[i], dec[i]);
				eprintf("pair for %c is %c\n", char(c2 + 'a'), char(par[c2] + 'a'));
				throw 42;
			}	

			par[c2] = c1;
		}
	}

	vector <bool> was(26, false);
	for (int i = 0; i < 26; i++)
	{
		if (par[i] == -1) 
			eprintf("%c\n", char(i + 'a'));
		else 
			was[par[i]] = true;
	}

	for (int i = 0; i < 26; i++)
		if (!was[i]) 
		{
			par[get('q')] = i;
			was[i] = true;
		}

	string s(26, ' ');
	for (int i = 0; i < 26; i++)
		s[par[i]] = char(i + 'a');
	cout << s;	
}

int main()
{
	int tests;
	scanf("%d\n", &tests);
	for (int test = 1; test <= tests; test++)
	{
		load();
		solve(test);
	}	
	return 0;
}
