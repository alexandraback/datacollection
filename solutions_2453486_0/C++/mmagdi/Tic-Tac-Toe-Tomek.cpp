/*
 TASK:Tic-Tac-Toe-Tomek
 LANG:C++
 Muhammad Magdi Muhammad
 Email: moh_magdi@acm.org
 */
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<(int)m;i++)
#define REP(i,k,m)      for(int i=k;i<(int)m;i++)
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define OO ((int)1e9)
#define MAX 100000

typedef long long ll;

int diri[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dirj[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int compare(double d1, double d2) {
	if (fabs(d1 - d2) < 1e-9)
		return 0;
	if (d1 < d2)
		return -1;
	return 1;
}
int I, J;
inline bool valid(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

using namespace std;

#define SMALL
//#define LARGE
int T;

string grid[4];

bool check(string s) {
	set<char> a;
	rep(i,s.size())
		a.insert(s[i]);
	return a.size() == 1;
}

bool check(char C) {
	string res = "";
	rep(i,4) {
		if (check(grid[i]) && C == grid[i][0])
			return 1;
	}
	rep(i,4) {
		string cur = "";
		rep(j,4)
			cur += grid[j][i];
		if (check(cur) && C == cur[0])
			return 1;
	}
	string cur = "";
	rep(i,4) {
		cur += grid[i][i];
	}
	if (check(cur) && C == cur[0])
		return 1;
	cur = "";
	rep(i,4) {
		cur += grid[i][3 - i];
	}
	if (check(cur) && C == cur[0])
		return 1;
	return 0;
}

int main() {
//	freopen("1.in", "rt", stdin);
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("Tic-Tac-Toe-Tomek-large.in","rt",stdin);
	freopen("Tic-Tac-Toe-Tomek-large.out","wt",stdout);
#endif

	cin >> T;
	rep(tt,T) {
		printf("Case #%d: ", tt + 1);
		rep(i,4)
			cin >> grid[i];
		int ii = -1, jj = -1 , dot = 0;
		rep(i,4) {
			rep(j,4) {
				if (grid[i][j] == 'T') {
					ii = i, jj = j;
				}
				if(grid[i][j] == '.')dot = 1 ;
			}
		}
		bool x = 0 , y = 0 ;
		if(ii != -1){
			grid[ii][jj] = 'O' ;
			y = check('O') ;
			grid[ii][jj] = 'X' ;
			x = check('X') ;
		}else{
			y = check('O') ;
			x = check('X') ;
		}
		if(!x && !y){
			if(dot)cout << "Game has not completed" << endl ;
			else cout << "Draw" << endl ;
		}else if(x){
			cout << "X won" << endl;
		}else
			cout << "O won" << endl;
//		cerr << tt << endl;
	}
	return 0;
}
//end

