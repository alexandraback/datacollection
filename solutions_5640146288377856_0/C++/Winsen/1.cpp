#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("A-small-attempt2.in");
	ofstream fout("output.txt");
	int t, ans;
	fin >> t;
	for (int i=0; i<t; i++) {
		int now, c, w;
		ans = 0;
		fin >> now >> c >> w;  
		while ((2*w)<=c) {
			c -= w;
			ans ++;
		}
		if (c==w) ans += w; else ans += (w+1);
		fout << "Case #" << i+1 << ": " << ans << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
