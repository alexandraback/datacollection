#include <cassert>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
#define SAMPLE_NAME "A"
	if( freopen(SAMPLE_NAME "-large.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-large.out", "wt", stdout);
	} else 	if( freopen(SAMPLE_NAME "-small.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;

	bool valid[256] = {false};
	valid['.'] = true;
	valid['X'] = true;
	valid['O'] = true;
	valid['T'] = true;
	int  bitsy[256] = {0};
	bitsy['.'] = 0;
	bitsy['X'] = 1;
	bitsy['O'] = 2;
	bitsy['T'] = 3;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		int board[4][4] = {0};
		//cerr << '#' << case_num << endl;
		cout << "Case #" << case_num ;

		int iAnder[4] = {3, 3, 3, 3};
		int jAnder[4] = {3, 3, 3, 3};
		int d1Ander = 3, d2Ander = 3;

		for(int i = 0; i < 4; ++i) {
			char line[5] = {0};
			do { cin >> line; } while ( !valid[ line[0] ]);
			//cout << line << endl;
			for(int j = 0; j < 4; ++j) {
				board[i][j] = bitsy[ line[j] ];
			}
		}
		for(int i = 0; i < 4; ++i) {
			iAnder[i] = board[i][0] & board[i][1] & board[i][2] & board[i][3];
			jAnder[i] = board[0][i] & board[1][i] & board[2][i] & board[3][i];
			d1Ander &= board[i][i];
			d2Ander &= board[i][3-i];
		}
		int winner = d1Ander | d2Ander;
		for(int i = 0; i < 4; ++i) {
			winner |= iAnder[i] | jAnder[i];
		}
		if(winner) {
			if(1 == winner) cout << ": X won" << endl;
			else cout << ": O won" << endl;
		} else {
			for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
			if(!board[i][j]) winner = -1;
			if(-1 == winner) cout << ": Game has not completed" << endl;
			else cout << ": Draw" << endl;
		}
	}
 	return 0;
}
