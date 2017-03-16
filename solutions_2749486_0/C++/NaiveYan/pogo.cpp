#include <fstream>

using namespace std;

int main() {
	int t, x, y, xx, i;
	ifstream fin("b.in");
	ofstream fout("b.out");
	fin >> t;
	for(xx = 1; xx <= t; xx++) {
		fin >> x >> y;
		fout << "Case #" << xx << ": ";
		if(x < 0) for(i = 0; i < -x; i++) fout << "EW";
		if(x > 0) for(i = 0; i < x; i++) fout << "WE";
		if(y < 0) for(i = 0; i < -y; i++) fout << "NS";
		if(y > 0) for(i = 0; i < y; i++) fout << "SN";
		fout << "\n";
	}
	return 0;
}
