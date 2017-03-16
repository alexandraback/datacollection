#include <iostream>
#include <fstream>
using namespace std;

long long data[15];

int main(){
	ifstream fin;
	fin.open("A-small-attempt0.in");
	ofstream fout;
	fout.open("A-small-attempt0.out");

	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		int r, c, w;
		fin >> r >> c >> w;

		fout << "Case #" << T << ": ";
		fout << ((c + w - 1) / w + w - 1) * r;
		fout << endl;
	}

}