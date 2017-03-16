#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum tic{DOTNUM,TNUM,XNUM,ONUM};
enum game{XWIN=0,OWIN,DRAW,NCOMP};
const string word[4]={
	"X won",
	"O won",
	"Draw",
	"Game has not completed"};
int main() {
	ifstream in("q1.in");
	ofstream out("q1.out");

	int t,caseNum = 1;
	in >> t;
	while (caseNum <=t) {
		tic ticMap[4][4]={};
		string line;
		bool ncomp_flag = false;
		for (int i=0;i<4;i++) {
			in >> line;
			for (int j=0;j<4;j++) {
				switch (line[j] ) {
				case 'X':
					ticMap[i][j] = XNUM;
					break;
				case 'O':
					ticMap[i][j] = ONUM;
					break;
				case 'T':
					ticMap[i][j] = TNUM;
					break;
				case '.':
					ticMap[i][j] = DOTNUM;
					ncomp_flag = true;
					break;
				}
			}
		}
		game winner = ncomp_flag ? NCOMP : DRAW;

		bool x_found = false;
		for (int i=0;i<4;i++) {
			bool x_flag = true;
			for (int j=0;j<4;j++) {
				if (!(ticMap[i][j]==XNUM || ticMap[i][j]== TNUM)) {
					x_flag = false;
					break;
				}
			}
			if (x_flag) {
				x_found = true;
				break;
			}
			x_flag = true;
			for (int j=0;j<4;j++) {
				if (!(ticMap[j][i]==XNUM || ticMap[j][i]== TNUM)) {
					x_flag = false;
					break;
				}
			}
			if (x_flag) {
				x_found = true;
				break;
			}
		}
		bool x_flag = true;
		for (int i=0;i<4;i++) {
			if (!(ticMap[i][i]==XNUM || ticMap[i][i]== TNUM)) {
				x_flag = false;
				break;
			}
		}
		if (x_flag) {
			x_found = true;
		}
		x_flag = true;
		for (int i=0;i<4;i++) {
			if (!(ticMap[i][3-i]==XNUM || ticMap[i][3-i]== TNUM)) {
				x_flag = false;
				break;
			}
		}
		if (x_flag) {
			x_found = true;
		}
//-------------------------------------------------

		bool o_found = false;
		for (int i=0;i<4;i++) {
			bool o_flag = true;
			for (int j=0;j<4;j++) {
				if (!(ticMap[i][j]==ONUM || ticMap[i][j]== TNUM)) {
					o_flag = false;
					break;
				}
			}
			if (o_flag) {
				o_found = true;
				break;
			}
			o_flag = true;
			for (int j=0;j<4;j++) {
				if (!(ticMap[j][i]==ONUM || ticMap[j][i]== TNUM)) {
					o_flag = false;
					break;
				}
			}
			if (o_flag) {
				o_found = true;
				break;
			}
		}
		bool o_flag = true;
		for (int i=0;i<4;i++) {
			if (!(ticMap[i][i]==ONUM || ticMap[i][i]== TNUM)) {
				o_flag = false;
				break;
			}
		}
		if (o_flag) {
			o_found = true;
		}
		o_flag = true;
		for (int i=0;i<4;i++) {
			if (!(ticMap[i][3-i]==ONUM || ticMap[i][3-i]== TNUM)) {
				o_flag = false;
				break;
			}
		}
		if (o_flag) {
			o_found = true;
		}

		if (x_found && !o_found)
			winner = XWIN;
		else if (!x_found && o_found)
			winner = OWIN;
		out << "Case #" << caseNum << ": " << word[winner] << endl;
		caseNum++;
	}
	in.close();
	out.close();
}