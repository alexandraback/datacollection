//============================================================================
// Name        : A.cpp
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

long testCase() {

	long r, c, w;
	cin >> r >> c >> w;

	if(w == 1) {
		return r*c;
	}
	else if(c % w == 0) {
		return r * (c / w) + w - 1;
	}
	else{
		return r * (c / w) + w;
	}
}

int main() {

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	ifstream in("in.txt");
	cin.rdbuf(in.rdbuf());

	ofstream out("out.txt");
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": " << testCase() << '\n';
	}


	in.close();
	out.close();

	return 0;
}
