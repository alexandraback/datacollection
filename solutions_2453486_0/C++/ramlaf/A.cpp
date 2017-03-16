#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <complex>
#include <cassert>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cout << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

typedef long long int tint;

int T;
string s[5];
bool notfin;

bool win(char c) {
	bool cond;
	
	forn(i,4) {
		cond = true;
		forn(j,4) if (s[i][j] != c && s[i][j] != 'T') cond = false;
		if (cond) return true;	
	}
	
	forn(j,4) {
		cond = true;
		forn(i,4) if (s[i][j] != c && s[i][j] != 'T') cond = false;
		if (cond) return true;	
	}
	
	cond = true;
	forn(i,4) if (s[i][i] != c && s[i][i] != 'T') cond = false;
	if (cond) return true;
	
	cond = true;
	forn(i,4) if (s[i][3-i] != c && s[i][3-i] != 'T') cond = false;
	if (cond) return true;
		
		
	return false;
}

int main () {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	cin >> T;
	forn(caso,T) {
		notfin = false;
		forn(i,4) {
			cin >> s[i];
			forn(j,4) if (s[i][j] == '.') notfin = true;	
		}
		
		cout << "Case #" << caso+1 << ": ";
		if (win('X')) cout << "X won" << endl;
		else if (win('O')) cout << "O won" << endl;
		else if (notfin) cout << "Game has not completed" << endl;
		else cout << "Draw" << endl;
	}

	return 0;
}
