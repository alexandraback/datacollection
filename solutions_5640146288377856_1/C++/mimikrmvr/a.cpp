#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ifstream in;
	in.open("A-large (1).in");
	//in.open("input.txt");
	ofstream out;
	out.open("outputAlarge.txt");
	int t;
	in >> t;
	for (int ti = 1; ti <= t; ti++) {
		int r, c, w;
		in >> r >> c >> w;
		int ans = r * c / w - 1 + w;
		if (c % w != 0) {
			ans++;
		}
		out << "Case #" << ti << ": " << ans << endl;
	}
	out.close();
	return 0;
}
