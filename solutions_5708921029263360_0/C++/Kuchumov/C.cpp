#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define debug_flag true
#else
	#define debug_flag false
#endif

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
    string name = it -> substr((*it)[0] == ' ', it -> length());
    if (isalpha(name[0]))
	    cerr << name  << " = " << a << " ";
	else
	    cerr << name << " ";
	_print(++it, args...);
}

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42;
#endif

typedef long long int int64;

struct Triple
{
	int a, b, c;
	Triple() : a(), b(), c() {}
	Triple(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
	
	bool operator < (const Triple &other) const
	{
		if (a != other.a)
			return a < other.a;
		if (b != other.b)
			return b < other.b;
		return c < other.c;
	}
};

const int N = 15;

int A, B, C;
int k;

bool used[N][N][N];
int cnt1[N][N], cnt2[N][N], cnt3[N][N];
vector<Triple> cur_path;
vector<Triple> best_path;
vector<Triple> all;

set<vector<Triple> > ss;

vector<Triple> norm(vector<Triple> l)
{
	sort(l.begin(), l.end());
	return l;
}

void rec(int pos)
{
	int can = (int)all.size() - pos;
	if ((int)cur_path.size() + can <= (int)best_path.size())
		return;

	if (cur_path.size() > best_path.size())
		best_path = cur_path;
	
	if (pos == (int)all.size())
		return;

	int a = all[pos].a;
	int b = all[pos].b;
	int c = all[pos].c;
	
	if (cnt1[a][b] != k && cnt2[a][c] != k && cnt3[b][c] != k)
	{
		used[a][b][c] = true;
		cnt1[a][b]++;
		cnt2[a][c]++;
		cnt3[b][c]++;

		cur_path.push_back(Triple(a, b, c));
		rec(pos + 1);
		cur_path.pop_back();

		used[a][b][c] = false;
		cnt1[a][b]--;
		cnt2[a][c]--;
		cnt3[b][c]--;
	}

	rec(pos + 1);
}

void solve(int test)
{
	scanf("%d%d%d%d", &A, &B, &C, &k);
	best_path.clear();
	
	all.clear();
	for (int a = 0; a < A; a++)
		for (int b = 0; b < B; b++)
			for (int c = 0; c < C; c++)
				all.push_back(Triple(a, b, c));
	rec(0);
	
	printf("Case #%d: %d\n", test, (int)best_path.size());
	for (Triple t : best_path)
		printf("%d %d %d\n", t.a + 1, t.b + 1, t.c + 1);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

    int tests;
    scanf("%d", &tests);
    for (int test = 0; test < tests; test++)
    {
        dbg(test);
        solve(test + 1);
    }

	return 0;
}
