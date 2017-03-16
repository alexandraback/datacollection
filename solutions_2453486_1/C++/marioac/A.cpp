//#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

ifstream cin("A-large.in");
ofstream cout("A-large.out");

char B[4][4];
int main() {
int T;

cin >> T;
string sp;
getline(cin,sp);
for (int tt=1; tt<=T; tt++) {

cout << "Case #"<<tt<<": ";

for (int i=0; i<4; i++) {
	getline(cin,sp);
	for (int j=0; j<4; j++) {
		B[i][j] = sp[j];
	}
}

bool owon = false;
bool xwon = false;

//check rows and columns
bool full = true;
for (int i=0; i<4; i++) {
	int cntor = 0, cntxr = 0, cntoc=0, cntxc=0;
	for (int j=0; j<4; j++) {
		if (B[i][j] == 'O' || B[i][j] == 'T') cntor++;
		if (B[i][j] == 'X' || B[i][j] == 'T') cntxr++;
		if (B[j][i] == 'O' || B[j][i] == 'T') cntoc++;
		if (B[j][i] == 'X' || B[j][i] == 'T') cntxc++;
		if (B[i][j] == '.') full = false;
	}
	if (cntor == 4 || cntoc == 4) { owon = true; break; }
	if (cntxr == 4 || cntxc == 4) { xwon = true; break; }
}
//check diags
int cntol =0, cntor=0, cntxl = 0, cntxr = 0;
for (int i=0; i<4; i++) {
	if (B[i][i] == 'X' || B[i][i]  == 'T') cntxl++;
	if (B[i][3-i] == 'X' || B[i][3-i] == 'T') cntxr++;
	if (B[i][i] == 'O' || B[i][i]  == 'T') cntol++;
	if (B[i][3-i] == 'O' || B[i][3-i] == 'T') cntor++;
}
if (cntol==4 || cntor==4) owon = true;
if (cntxl==4 || cntxr==4) xwon = true;


if (owon) { cout << "O won" << endl; }
else if (xwon) { cout << "X won" << endl; }
else if (full) cout << "Draw" << endl; else cout << "Game has not completed" << endl;

if (tt!=T) getline(cin,sp);

}
return 0;
}
