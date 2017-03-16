#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin;
	fin.open("D-small-attempt0.in");
	ofstream fout;
	fout.open("D-small-attempt0.out");

	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		int x, r, c;
		fin >> x >> r >> c;

		if (r < c){
			int tmp = r;
			r = c;
			c = tmp;
		}

		int flag = 0, flag2 = 0;
		while (1){
			if (x >= 7)
				break;

			if ((r*c) % x != 0)
				break;

			if (x == 2){
				flag = 1;
				break;
			}

			if (x == 4 && r == 4 && c == 2){
				break;
			}

			for (int i = 1; i <= (x + 1) / 2; i++){
				if (c < i || r < x + 1 - i){
					flag2 = 1;
				}
			}
			if (flag2)
				break;

			flag = 1;
			break;
		}



		fout << "Case #" << T << ": ";
		if (flag){
			fout << "GABRIEL";
		}
		else{
			fout << "RICHARD";
		}
		fout << endl;
	}

}