#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	//set input/output stream
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");

	int T;
	char str[2000];
	char outputStr[4000];

	input >> T;
	for(int x = 1; x <= T; x++) {
		input >> str;
		int len = strlen(str);
		output << "Case #" << x << ": ";
		int start = 2000;
		int end = 2000;
		outputStr[2000] = str[0];
		for(int i = 1; i < len; i++) {
			if(str[i] >= outputStr[start]) {
				outputStr[--start] = str[i];
			} else {
				outputStr[++end] = str[i];
			}
		}

		//output
		for(int i = start; i <= end; i++) {
			output << outputStr[i];
		}
		output << endl;
	}

	return 0;
}

