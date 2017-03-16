#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

string solStr[] = {"X won", "O won", "Draw", "Game has not completed"};
int ma[4][4];

int returnWinner(int x, int y) {
	for(int i=-1; i<=1 ;i++){
		for(int j=-1; j<=1 ;j++){
			if(i == j && i == 0) continue;
			int a = x, b = y, r = 0;
			while(true) {
				if(a < 0 || a >= 4) break;
				if(b < 0 || b >= 4) break;
				r += ma[a][b];
				a += i;
				b += j;
			}
			if(r == 4 || r == 103) return 0;
			if(r == 40 || r == 130) return 1;
		}
	}
	return 4;
}

void solve(int caso){
	string s;
	bool drawFlag = true, xWin = false, oWin = false;
	F(i, 4) {
		cin >> s;
		F(j, 4){
			ma[i][j] = 0;
			if(s[j] == 'X') ma[i][j] = 1;
			if(s[j] == 'O') ma[i][j] = 10;
			if(s[j] == 'T') ma[i][j] = 100;
			if(s[j] == '.') drawFlag = false;
		}
	}
	F(i, 4) {
		int r1 = returnWinner(0, i);
		int r2 = returnWinner(i, 0);
		if(r1 == 0 || r2 == 0) xWin = true;
		if(r1 == 1 || r2 == 1) oWin = true;
	}
	if(xWin && oWin){
		cout<<"Case #"<<caso<<": "<< solStr[2] << endl;
	}
	else if(xWin){
		cout<<"Case #"<<caso<<": "<< solStr[0] << endl;
	}
	else if(oWin){
		cout<<"Case #"<<caso<<": "<< solStr[1] << endl;
	}
	else{
		cout<<"Case #"<<caso<<": "<< solStr[(drawFlag)? 2 : 3] << endl;
	}
}

int main(){
	// freopen("a.in.txt", "r", stdin);
	// freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("a.out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solve(i+1); }
}

