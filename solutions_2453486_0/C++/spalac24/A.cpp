using namespace std;
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iterator>
#include <bitset>
#include <cstdlib>
#include <set>

template <class T> string toStr (T x){stringstream ss;ss << x;return ss.str();}
template <class T> long long toInt (T x){stringstream ss; ss << x; long long r; ss >> r; return r;}


#define FOR(i,a,b) for(int i = (a); i <(b); ++i)
#define foreach(x,v) for(typeof (v).begin() x = v.begin(); x != v.end(); ++x)
#define sz(x) (int)(x).size()
#define DEBUG
#ifdef DEBUG
#define REACH  cout<<" reached line "<<__LINE__<<endl
#define D(x) cout<<#x " is "<<(x)<<endl
#else
#define REACH
#define D(x)
#endif	
#define D2(x) cout<<#x " is "<<(x)<<endl
typedef unsigned long long ull; 

string mat [4];

bool won (char c) {
	char op = (c=='X')?'O':'X';
    bool b = true;
	for (int i = 0; i < 4; ++i) {
		if (mat[i][i] == op or mat[i][i] == '.') {
			b = false;
		}
	}
	if (b) return true;
	b = true;
	for (int i = 0; i < 4; ++i) {
		if (mat[i][3-i] == op or mat[i][3-i] == '.') {
			b = false;
		}
	}
	if (b) return true;
	bool a;
	for (int i = 0; i < 4; ++i) {
		a = b = true;
		for (int j = 0; j < 4; ++j) {
			if (mat[i][j]==op or mat[i][j]=='.') a = false;
			if (mat[j][i]==op or mat[j][i]=='.') b = false;
		}
		if (a or b) return true;
	}
	return false;
}

string solve () {
	if (won('X')) return "X won";
	if (won('O')) return "O won";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (mat[i][j] == '.') return "Game has not completed";
		}
	}
    return "Draw";
}

int main (){
	ios::sync_with_stdio(false);
	int cases;
	cin>>cases;
	for (int cas = 1; cas <= cases; ++cas) {
		cout<<"Case #"<<cas<<": ";
		for (int i = 0; i < 4; ++i) {
			cin>>mat[i];
		}
		//for (int i = 0; i < 4; ++i) cout<<mat[i]<<endl;
		cout<<solve()<<endl;
	}
	
}
