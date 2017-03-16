/*
 ID: aaandrew
 PROG: gcj 13 qual round 
 LANG: C++
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <fstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define PB push_back

char x[4][4];
int freq[256], T;

bool win(char a) {
	REP(i,4) {
		CL(freq);
		REP(j,4) freq[ x[i][j] ]++;
		if (freq[a] == 4 || (freq[a] == 3 && freq['T'])) return true;
		
		CL(freq);
		REP(j,4) freq[ x[j][i] ]++;
		if (freq[a] == 4 || (freq[a] == 3 && freq['T'])) return true;
	}
	
	CL(freq);
	REP(j,4) freq[ x[j][j] ]++;
	if (freq[a] == 4 || (freq[a] == 3 && freq['T'])) return true;
	
	CL(freq);
	REP(j,4) freq[ x[j][3-j] ]++;
	if (freq[a] == 4 || (freq[a] == 3 && freq['T'])) return true;
	
	return false;
}

int main() {
	cin >> T;
	REP(t,T) {
		REP(i,4) cin >> x[i];
		
		cout << "Case #" << (t+1) << ": ";
		
		bool flag = true;
		REP(i,4) REP(j,4) if (x[i][j] == '.') flag = false; //still going
		if (win('O'))
			cout << "O won" << endl;
		else if (win('X'))
			cout << "X won" << endl;
		else if (!flag)
			cout << "Game has not completed" << endl;
		else
			cout << "Draw" << endl;
	}
}
