#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

bool won(const vector<string>& board, const char m)
{
	FORN(i, 0, 4){
		bool allgood = true;
		FORN(j, 0, 4) if(board[i][j] != m and board[i][j] != 'T') allgood = false;
		if(allgood) return true;
	}

	FORN(j, 0, 4){
		bool allgood = true;
		FORN(i, 0, 4) if(board[i][j] != m and board[i][j] != 'T') allgood = false;
		if(allgood) return true;
	}

	bool allgood = true;
	FORN(i, 0, 4) if(board[i][i] != m and board[i][i] != 'T') allgood = false;
	if(allgood) return true;
	allgood = true;
	FORN(i, 0, 4) if(board[i][3 - i] != m and board[i][3 - i] != 'T') allgood = false;
	return allgood;
}

bool canmove(const vector<string>& board)
{
	FORN(i, 0, 4) FORN(j, 0, 4) if(board[i][j] == '.') return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	FORN(tc, 0, ntc){
		vector<string> board(4);
		FORN(i, 0, 4) cin >> board[i];

		cout << "Case #" << (tc + 1) << ": ";
		if(won(board, 'X')){
			cout << "X won";
		}else if(won(board, 'O')){
			cout << "O won";
		}else if(canmove(board)){
			cout << "Game has not completed";
		}else{
			cout << "Draw";
		}
		cout << endl;
	}
	
}
