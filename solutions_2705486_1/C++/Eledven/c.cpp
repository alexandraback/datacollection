#include <iostream>
#include <ctime>
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
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));

class Node
{
public:
	int c;
	int nxt[26];
	bool term;

	Node(int c = -1)
	{
		this->c = c;
		term = false;
		memset(nxt, -1, sizeof(nxt));
	}

	int &operator [] (int i)
	{
		return nxt[i];
	}
};

vector <Node> trie;

void addWord(const char *word)
{
	int n = strlen(word);
	int v = 0;
	for (int i = 0; i < n; i++)
	{
		int c = word[i] - 'a';
		if (trie[v][c] == -1)
		{
			Node cur(c);
			trie[v][c] = trie.size();
			trie.pb(cur);
		}
		v = trie[v][c];
	}
	trie[v].term = true;
}

bool find(const char *word)
{
	int v = 0;
	for (int i = 0; word[i]; i++)
	{
		int c = word[i] - 'a';
		if (trie[v][c] == -1) return false;
		v = trie[v][c];
	}
	return trie[v].term;
}

int maxLength;
void loadDictionary(const char *fileName)
{
	trie.pb(Node());

	FILE *file = fopen(fileName, "r");
	if (!file)
	{
		eprintf("error while openning file %s\n", fileName);
		exit(-1);
	}

	maxLength = 0;
	char tmp[100] = {0};
	int words = 0;
	while (fscanf(file, "%s", tmp) == 1)
	{
		maxLength = max(maxLength, (int)strlen(tmp));
		for (int i = 0; tmp[i]; i++)
			assert('a' <= tmp[i] && tmp[i] <= 'z');
		addWord(tmp);
		words++;
	}
	eprintf("loading: OK\n");
	eprintf("there are %d words\n", words);
	eprintf("maximum length: %d\n", maxLength);
	eprintf("trie size: %d\n", trie.size());
}

string s;
char word[111];
vector < pair <pii, int > > all[4111];

void generate(const int startPos, int pos, int last, int wrong, int v)
{
	if (v == -1) return;

	word[pos] = 0;
	if (trie[v].term)
		all[startPos].pb(mp(mp(pos, last), wrong));

	if (pos + startPos >= (int)s.size()) return;
	if (pos >= maxLength) return;

	// no mistake
	int c = s[startPos + pos] - 'a';
	if (trie[v][c] != -1)
	{
		word[pos] = s[startPos + pos];
		generate(startPos, pos + 1, last, wrong, trie[v][c]);
	}
	// mistake
	if (startPos + pos - last >= 5)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			if (c == s[startPos + pos]) continue;
			word[pos] = c;
			generate(startPos, pos + 1, startPos + pos, wrong + 1, trie[v][c - 'a']);
			word[pos] = 0;
		}
	}
}

int dp[4111][4111];

int f(int pos, int last)
{
	if (pos == (int)s.size())
		return 0;
	int &res = dp[pos][last + 6];
	if (res != -1) return res;
	res = INF;
	generate(pos, 0, last, 0, 0);

	sort(all[pos].begin(), all[pos].end());
	all[pos].erase(unique(all[pos].begin(), all[pos].end()), all[pos].end());
	for (int i = 0; i < (int)all[pos].size(); i++)
	{
		int cres = f(pos + all[pos][i].fi.fi, all[pos][i].fi.se) + all[pos][i].se;
		res = min(res, cres);
	}
	return res;	
}

void solve(int test)
{
	cin >> s;
	eprintf("%d\n", s.size());
	memset(dp, -1, sizeof(dp));
	printf("Case #%d: %d\n", test, f(0, -6));
}

int main(int argc, char *argv[])
{
	clock_t start = clock();
	if (argc != 2)
	{	
		eprintf("usage: %s <dictionary>\n", argv[0]);
		exit(-1);
	}

	loadDictionary(argv[1]);
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		clock_t cur = clock();
		solve(test);
		eprintf("test %d complete time: %.6lf\n", test, (double)(clock() - cur) / CLOCKS_PER_SEC);
	}	
	eprintf("time: %.6lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}
