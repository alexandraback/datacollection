#include <ctime>
#include <bitset>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <fstream>
using namespace std;


#define PB	push_back
#define MP  make_pair
#define ALL(a) 	(a).begin(), (a).end()
#define FILL(a,v) memset(a,v,sizeof(a))

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define SQR(x) (x)*(x)

#define y1 asdfasdf

typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-7;
const int MOD = 1000000007;
const int INF = 2000000000;


string s[] = {
	"ONE",

	"NINE"
};

int a[26];
int b[26];

void solve()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < 26; ++i)
	{
		a[i] = 0;
		b[i] = 0;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		a[s[i] - 'A']++;
	}
	while (a['Z' - 'A'])
	{
		++b[0];
		--a['Z' - 'A'];
		--a['E' - 'A'];
		--a['R' - 'A'];
		--a['O' - 'A'];
	}
	while (a['X' - 'A'])
	{
		++b[6];
		--a['S' - 'A'];
		--a['I' - 'A'];
		--a['X' - 'A'];
	}

	while (a['G' - 'A'])
	{
		++b[8];
		--a['E' - 'A'];
		--a['I' - 'A'];
		--a['G' - 'A'];
		--a['H' - 'A'];
		--a['T' - 'A'];
	}
	while (a['H' - 'A'])
	{
		++b[3];
		--a['T' - 'A'];
		--a['H' - 'A'];
		--a['R' - 'A'];
		--a['E' - 'A'];
		--a['E' - 'A'];
	}
	while (a['W' - 'A'])
	{
		++b[2];
		--a['T' - 'A'];
		--a['W' - 'A'];
		--a['O' - 'A'];
	}


	while (a['S' - 'A'])
	{
		++b[7];
		--a['S' - 'A'];
		--a['E' - 'A'];
		--a['V' - 'A'];
		--a['E' - 'A'];
		--a['N' - 'A'];
	}
	//
	while (a['R' - 'A'])
	{
		++b[4];
		--a['F' - 'A'];
		--a['O' - 'A'];
		--a['U' - 'A'];
		--a['R' - 'A'];
	}

	while (a['V' - 'A'])
	{
		++b[5];
		--a['F' - 'A'];
		--a['I' - 'A'];
		--a['V' - 'A'];
		--a['E' - 'A'];
	}
	while (a['I' - 'A'])
	{
		++b[9];
		--a['N' - 'A'];
		--a['I' - 'A'];
		--a['N' - 'A'];
		--a['E' - 'A'];
	}
	while (a['O' - 'A'])
	{
		++b[1];
		--a['O' - 'A'];
		--a['N' - 'A'];
		--a['E' - 'A'];
	}
	for (int i = 0; i < 10; ++i)
		while (b[i] > 0)
		{
			printf("%c", '0' + i);
			--b[i];
		}
	printf("\n");
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);

	string s;
	getline(cin, s);
	for (int test = 1; test <= tests; ++test)
	{
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}
