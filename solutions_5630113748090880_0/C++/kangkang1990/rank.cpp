#include <fstream>
#include <iostream>

using namespace std;

int main() {
	//set input/output stream
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");

	int T;
	int m[4000];
	int N;
	input >> T;
	for(int x = 1; x <= T; x++) {
		input >> N;
		//init m array
		for(int i = 1; i < 3000; i++) {
			m[i] = 0;
		}
		for(int i = 1; i < 2 * N; i++) {
			for(int j = 0; j < N; j++) {
				int height;
				input >> height;
				m[height] = m[height] ^ 1;
			}
		}

		//output
		output << "Case #" << x << ": ";
		for(int i = 1; i < 3000; i++) {
			if(m[i] == 1) {
				output << i << " ";
			}
		}
		output << endl;
	}
	return 0;
}
