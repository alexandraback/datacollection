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

int a, b;
void load()
{
	scanf("%d%d", &a, &b);
}

string toString(int n)
{
	string res = "";
	do
	{
		res += char('0' + (n % 10));
		n /= 10;
	} while (n > 0);
	reverse(res.begin(), res.end());
	return res;
}

int toInt(const string &s)
{
	return atoi(s.c_str());
}

vector <int> get(int n)
{
	string s = toString(n);
	vector <int> res;
	for (int i = 1; i < (int)s.size(); i++)
	{
		string cur = s.substr((int)s.size() - i) + s.substr(0, (int)s.size() - i);
		res.pb(toInt(cur));
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

void solve(int test)
{
	int res = 0;
	for (int i = a; i < b; i++)
	{
		vector <int> pos = get(i);
		for (int j = 0; j < (int)pos.size(); j++)
			if (a <= pos[j] && pos[j] <= b && pos[j] > i) res++;
	}

	printf("Case #%d: %d\n", test, res);
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		load();
		solve(test);
	}	
	return 0;
}
