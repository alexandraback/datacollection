#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

ofstream out("out.txt");


map<int, int> cache;


int main() {
	ifstream f("B-small-attempt0 (2).in");
	int T;
	f >> T;

	for (int q = 0; q < T; q++) {
		cache.clear();
		int x, y;
		f >> x >> y;
		bool negx = false, negy= false;
		string result;

		if (x < 0) {
			x = -x;
			negx = true;
		}
		if (y < 0) {
			y = -y;
			negy = true;
		}

		for (int i = 0; i<(2*x); i++) {
			if((i+negx)%2) result += "E";
			else result += "W";
		}

		for (int j = 0; j<(2*y); j++) {
			if((j+negy)%2) result += "N";
			else result += "S";
		}

		out << "Case #" << q + 1 << ": " << result << endl;

	}

	return 0;
}
