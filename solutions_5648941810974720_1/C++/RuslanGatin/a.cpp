#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/stack:256000000")

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <map>
#include <memory.h>
#undef NDEBUG
#include <cassert>
#include <ctime>

using namespace std;

#define fo(a,b,c) for (int a = (b); a < (c); a++)
#define fr(a,b) fo(a, 0, (b))
#define fi(n) fr(i, (n))
#define fj(n) fr(j, (n))
#define fk(n) fr(k, (n))
#define fd(a,b,c) for (int a = (b); a >= (c); a--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define _(a,b) memset((a), (b), sizeof(a))
#define __(a) memset((a), 0, sizeof(a))
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long lint;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> pii;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("a-small.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	freopen("a-large.in", "r", stdin);
	freopen("a-large.out", "w", stdout);
}

string s;
vector<int> res;

void read()
{
	s = ns();
}

int getC(string s, char c)
{
	int res = 0;
	fi(sz(s))
		res += s[i] == c;
	return res;
}

void go(string &s, char c, string z, int num)
{
	int cnt = getC(s, c);
	if (cnt == 0)
		return;
	fi(cnt)
		res.pb(num);
	map<char, int> ma;
	fi(sz(z))
		ma[z[i]] += cnt;
	string q;
	for (int i = 0; i < sz(s); i++)
	{
		if (ma[s[i]] <= 0)
			q.push_back(s[i]);
		else
			ma[s[i]]--;
	}
	s = q;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	res.clear();
	go(s, 'W', "TWO", 2);
	go(s, 'Z', "ZERO", 0);
	go(s, 'G', "EIGHT", 8);
	go(s, 'X', "SIX", 6);
	go(s, 'U', "FOUR", 4);
	go(s, 'R', "THREE", 3);
	go(s, 'O', "ONE", 1);
	go(s, 'F', "FIVE", 5);
	go(s, 'S', "SEVEN", 7);
	go(s, 'I', "NINE", 9);
	sort(all(res));
	fi(sz(res))
		printf("%d", res[i]);
	printf("\n");
	if (s != "")
		assert(false);
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
	{
		read();
		solve(i + 1);
	}
	return 0;
}