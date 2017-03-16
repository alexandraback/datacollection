#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ifstream in("D-small-attempt0.in");
	ofstream out;
	out.open("d.output");
	int t; 
	in >> t;
	for(int z = 0; z < t; z++) {
		int x, r, c;
		in >> x >> r >> c;
		if(x >= 7){
			out << "Case #" << z+1 << ": RICHARD" << endl;
			continue;
		}
		if(x <= 2) {
			if(r*c % x == 0)
				out << "Case #" << z+1 << ": GABRIEL" << endl;
			else
				out << "Case #" << z+1 << ": RICHARD" << endl;
			continue;
		}
		if(x == 3) {
			if(r*c % x == 0 && r >= 2 && c >= 2)
				out << "Case #" << z+1 << ": GABRIEL" << endl;
			else
				out << "Case #" << z+1 << ": RICHARD" << endl;
			continue;
		}
		if(x == 4 || x == 5) {
			if(r*c % x == 0 && r >= 3 && c >= 3)
				out << "Case #" << z+1 << ": GABRIEL" << endl;
			else
				out << "Case #" << z+1 << ": RICHARD" << endl;
			continue;
		}
		if(x == 6) {
			if(r*c % x == 0 && r >= 4 && c >= 4)
				out << "Case #" << z+1 << ": GABRIEL" << endl;
			else
				out << "Case #" << z+1 << ": RICHARD" << endl;
			continue;
		}
		

	}


	out.close();
	return 0;
}
