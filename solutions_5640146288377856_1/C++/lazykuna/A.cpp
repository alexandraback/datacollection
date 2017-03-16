#include <iostream>
#include <fstream>
using namespace std;

ifstream in;
ofstream out;
int n;
int r,c,w;

void process(int idx) {
	int tricks = c/w;
	int ret = tricks * r;
	// fill left area
	ret += w-1;
	ret += (c%w >= 1);
	
	cout << "Case #" << idx << ": " << ret << "\n";
	//cout << "Case #" << idx << "\n";
}

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "please enter input.txt argv\n";
		return -1;
	}

	in.open(argv[1]);
	out.open("output.txt");

	in >> n;

	for (int i=0; i<n; i++) {
		in >> r >> c >> w;
		process(i+1);
	}

	in.close();
	out.close();

	return 0;
}
