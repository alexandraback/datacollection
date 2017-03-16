#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
 
using namespace std ;

#define all(n) n.begin(), n.end()
#define fore(i, n) forn (i, n.size())
#define fori(i, n) for (typeof (n.begin()) i = n.begin() ; i != n.end() ; i++)
#define forn(i, n) forsn (i, 0, n)
#define forsn(i, s, n) for (int i = s ; i < n ; i++)
#define LOG cerr << "[" << __LINE__ << "] "
#define pb push_back

typedef pair <int, int> pii ;
#define y first
#define x second

struct trie ;

const int big = 1000000000 ;

const int alph = 'z' - 'a' + 1 ;
const int maxp = 5000000 ;

trie *Q[maxp] ;
int W = 0 ;
struct trie
{
	trie *next[alph] ;
	bool fin ;
	int id ;

	void add(const string &s, int n = 0)
	{
		if (n == s.size())
		{
			fin = true ;
			return ;
		}

		trie *&p = next[s[n] - 'a'] ;
		if (p == NULL) p = new trie ;

		p->add(s, n + 1) ;
	}

	trie()
	{
		Q[id = W++] = this ;

		forn(i, alph) next[i] = NULL ;
		fin = false ;
	}
} ;

void add(map <pii, int> &b, int t, int u, int r)
{
	pii y(t, u) ;
	if (b.find(y) == b.end() || b[y] > r) b[y] = r ;
}

void down(map <pii, int> &b, int c, int t, int u, int r)
{
	if (Q[t]->next[c] != NULL)
		add(b, Q[t]->next[c]->id, max(u - 1, 0), r) ;

	if (u == 0) forn(i, alph) if (Q[t]->next[i] != NULL)
		add(b, Q[t]->next[i]->id, 4, r + 1) ;
}

int parse(const string &s)
{
	map <pii, int> a ;
	a[pii(0, 0)] = 0 ;

	fore(n, s)
	{
		//LOG << n << ' ' << a.size() << endl ;

		map <pii, int> b ;
		fori(it, a)
		{
			int t = it->y.y, u = it->y.x, r = it->x ;

			down(b, s[n] - 'a', t, u, r) ;
			if (t != 0 && Q[t]->fin) down(b, s[n] - 'a', 0, u, r) ;
		}

		swap(a, b) ;
	}

	int r = big ;
	fori(it, a) if (Q[it->y.y]->fin) r = min(r, it->x) ;

//	assert(r < big) ;

	return r ;
}

trie T ;
int main()
{
	ifstream in("garbled_email_dictionary.txt") ;
	string w ;
	while (in >> w) T.add(w) ;
	cerr << "Termino de parsear diccionario!" << endl ;

	int t ; cin >> t ;
	forn(z, t)
	{
		string s ; cin >> s ;
		printf("Case #%d: %d\n", z + 1, parse(s)) ;
	}

	return 0 ;
}

