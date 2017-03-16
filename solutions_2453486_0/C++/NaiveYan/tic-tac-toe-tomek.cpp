#include <fstream>
#include <string> 

using namespace std;

char b[4][4];
string tmp;

int main() {
	ofstream fout ("a.out");
	ifstream fin ("a.in");
	bool d;
	int t, x, s1, s2, s3, s4, i, j;
	string y;
	fin >> t;
	getline(fin, tmp);
	s1 = 0;
	for(x = 1; x <= t; x++) {
		for(i = 0; i < 4; i++) fin.getline(b[i], 5);
		getline(fin, tmp);
		d = false;
		s3 = 0;
		s4 = 0;
		y = "Draw";
		for(i = 0; i < 4; i++) {
			s1 = 0;
			s2 = 0;
			for(j = 0; j < 4; j++) {
				switch(b[i][j]) {
					case 'O' :
						s1 += 2;
						break;
					case 'T' :
						s1 += 1;
						break;
					case 'X' :
						s1 -= 2;
						break;
					default :
						d = true;
				}
				switch(b[j][i]) {
					case 'O' :
						s2 += 2;
						break;
					case 'T' :
						s2 += 1;
						break;
					case 'X' :
						s2 -= 2;
						break;
					default :
						d = true;
				}
			}
			if((s1 + 5) * (s1 + 8) == 0 || (s2 + 5) * (s2 + 8) == 0) {
				y = "X won";
				break;
			}
			else if(s1 > 6 || s2 > 6) {
				y = "O won";
				break;
			}
			switch(b[i][i]) {
				case 'O' :
					s3 += 2;
					break;
				case 'T' :
					s3 += 1;
					break;
				case 'X' :
					s3 -= 2;
					break;
				default :
					d = true;
			}
			switch(b[i][3 - i]) {
				case 'O' :
					s4 += 2;
					break;
				case 'T' :
					s4 += 1;
					break;
				case 'X' :
					s4 -= 2;
					break;
				default :
					d = true;
			}
		}
		if(y == "Draw") {
			if((s3 + 5) * (s3 + 8) == 0 || (s4 + 5) * (s4 + 8) == 0) y = "X won";
			else if(s3 > 6 || s4 > 6) y = "O won";
			if(d && y == "Draw") y = "Game has not completed";
		}
		fout << "Case #" << x << ": " << y << '\n';
	}
	return 0;
}
