//lazy propagation
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, a, b) for(int i=(a);i<int(b);i++)
#define PB push_back
#define MP(X,Y) make_pair(X,Y)
#define SZ(X) ((int)(X.size()))
#define ALL(x)   (x).begin(),(x).end()
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
#define F first
#define S second
#define CLEAR(A, V) memset(A, V, sizeof(A))

typedef  long long   ll;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;

template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline T gcd(T a, T b){ return b?gcd(b, a%b):a;}
const double EPS = 1e-9;
const double PI = acos(-1.0);

string board[4];
bool win(char c) {

	forn(i, 0, 4) {
		bool line = true;
		forn(j, 0, 4) line = line && (board[i][j] == c || board[i][j] == 'T');
		if(line) return true;
	}

	forn(j, 0, 4) {
		bool column = true;
		forn(i, 0, 4) column = column && (board[i][j] == c || board[i][j] == 'T');
		if(column) return true;
	}

	bool diagonal = true;
	forn(i, 0, 4) diagonal = diagonal && (board[i][i] == c || board[i][i] == 'T');
	if(diagonal) return true;

	diagonal = true;
	forn(i, 0, 4) diagonal = diagonal && (board[i][3-i] == c || board[i][3-i] == 'T');
	if(diagonal) return true;

	return false;
}

bool draw() {

	forn(i, 0, 4) forn(j, 0, 4) if(board[i][j] == '.') return false;
	return true;
}

int main () {

	int casos;
	cin >> casos;
	
	forn(t, 0, casos) {
		forn(i, 0, 4) cin >> board[i];

		cout << "Case #" << t+1 << ": ";
		if( win('X') ) cout << "X won" << endl;
		else if( win('O') ) cout << "O won" << endl;
		else if( draw() )  cout << "Draw" << endl;
		else cout << "Game has not completed" << endl;

	}
	return 0;
}



