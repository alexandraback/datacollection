#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("A-large.out");

#define cin fin
#define cout fout

int t, test = 1;
char mp[5][5];

void setWinner( char a, char b, char c, char d, string &res ) {
	char arr[4] = {a, b, c, d};
	int o = 0;
	int x = 0;
	for( int i = 0; i < 4; i++ ) {
		if( arr[i] == 'O' || arr[i] == 'T' )	o++;
		if( arr[i] == 'X' || arr[i] == 'T' )	x++;
	}
	if( o == 4 )
		res = "O won";
	if( x == 4 )
		res = "X won";
}

int main() {
	for( cin >> t; t--; ) {
		string res = "Draw";
		for( int i = 0; i < 4; i++ ) {
			for( int j = 0; j < 4; j++ ) {
				cin >> mp[i][j];
				if( mp[i][j] == '.' )
					res = "Game has not completed";
			}
		}
		for( int i = 0; i < 4; i++ ) {
			setWinner( mp[i][0], mp[i][1], mp[i][2], mp[i][3], res );
			setWinner( mp[0][i], mp[1][i], mp[2][i], mp[3][i], res );
		}
		setWinner( mp[0][0], mp[1][1], mp[2][2], mp[3][3], res );
		setWinner( mp[0][3], mp[1][2], mp[2][1], mp[3][0], res );
		cout << "Case #" << test++ << ": " << res << endl;
	}
	return 0;
}