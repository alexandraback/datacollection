#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

bool count( const vector<string>& a, int sx, int sy, int dx, int dy ) {
	int numo = 0;
	int numx = 0;
	int numt = 0;
	for( int j = 0; j < 4; j++ ) {
		int xx = sx + dx * j;
		int yy = sy + dy * j;
		if( a[xx][yy] == 'O' ) numo++;
		if( a[xx][yy] == 'T' ) numt++;
		if( a[xx][yy] == 'X' ) numx++;
	}
	if( numt <= 1 && numt + numx == 4 ) {
		cout << "X won" << endl;
		return true;
	}
	if( numt <= 1 && numt + numo == 4 ) {
		cout << "O won" << endl;
		return true;
	}
	return false;
}

void solveTest()
{
	vector<string> a;
	for( int i = 0; i < 4; i++ ) {
		string tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for( int i = 0; i < 4; i++ ) {
		if( count( a, 0, i, 1, 0 ) ) return;
		if( count( a, i, 0, 0, 1 ) ) return;
	}
	if( count( a, 0, 0, 1, 1 ) ) return;
	if( count( a, 3, 0, -1, 1 ) ) return;
	bool notComp = false;
	for( int i = 0; i < 4; i++ ) {
		for( int j = 0; j < 4; j++ ) {
			if( a[i][j] == '.' ) notComp = true;
		}
	}
	if( notComp ) {
		cout << "Game has not completed" << endl;
	} else {
		cout << "Draw" << endl;
	}
}

void run()
{
	int tn;
	cin >> tn;
	for( int i = 0; i < tn; i++ ) {
		cout << "Case #" << (i+1) << ": ";
		solveTest();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	run();
	return 0;
}