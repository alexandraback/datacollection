#include <iostream>
#include <fstream>

bool whoWin(int x, int r, int c) {
	if (((r*c) % x) != 0) return false;
	if (x > 6) return false;
	
	if (x < 3) return true;
	
	if (x == 3) {
		return r != 1 && c != 1;
	}
	
	if (x == 4) {
		if (c*r >=12) {
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	int n;
	std::ifstream input;
	std::ofstream output;
	input.open("D-small-attempt1.in");
	output.open("out.txt");
	input >> n;
	for (int i = 1;i<=n;i++) {
		int x;
		input >> x;
		int r;
		input >> r;
		int c;
		input >> c;
		bool winner = whoWin(x,r,c);
		output << "Case #" << i << ": " << (winner?"GABRIEL":"RICHARD") << std::endl;
	
	}
    input.close();
	output.close();
	return 0;
}
