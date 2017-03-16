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
	freopen("c-small.in", "r", stdin);
	freopen("c-small.out", "w", stdout);
}

void panic(bool expression = false)
{
	if (!expression)
	{
		cerr << "PANIC!" << endl;
		assert(false);
	}
}

vector<string> words;
string s;
int dp[55][7];

bool cmp(const string &a, const string &b)
{
	return sz(a) < sz(b);
}

void pre()
{
	freopen("garbled_email_dictionary.txt", "r", stdin);
	words.resize(521196);
	fi(521196)
		words[i] = ns();
	sort(all(words), cmp);
}

int getLastIndex(int index, int last, string &w, int &difCount)
{
	difCount = 0;
	fi(sz(w))
	{
		int j = i + index;
		if (w[i] != s[j])
		{
			difCount++;
			if (j - last < 5)
				return -1;
			last = j;
		}
	}
	return last;
}

int getDp(int i, int j)
{
	if (i < 0)
		return j == 5 ? 0 : INF;
	return dp[i][j];
}

void solve(int test_num)
{
	cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	s = ns();
	_(dp, 127);
	fi(sz(s))
	{
		fj(sz(words))
		{
			string &word = words[j];
			if (sz(word) <= i + 1)
			{
				int difCount;
				int preEnd = i - sz(word);
				int last = getLastIndex(preEnd + 1, -5, word, difCount);
				if (last == -1)
					continue;
				fk(6)
				{
					int curDp = getDp(preEnd, k);
					if (curDp < INF)
					{
						last = getLastIndex(preEnd + 1, preEnd - k, word, difCount);
						if (last == -1)
							continue;
						int d = min(5, i - last);
						dp[i][d] = min(dp[i][d], curDp + difCount);
					}
				}
			}
			else
				break;
		}
	}
	int res = INF;
	for (int i = 0; i <= 5; i++)
		res = min(res, dp[sz(s) - 1][i]);
	panic(res < INF);
	printf("%d\n", res);
}

int main()
{
	pre();
	prepare();
	int number_of_tests;
	scanf("%d", &number_of_tests);
	fi(number_of_tests)
		solve(i + 1);
	return 0;
}