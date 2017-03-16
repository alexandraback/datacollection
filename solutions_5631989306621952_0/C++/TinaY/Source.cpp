#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int T;
	ofstream cout("A-small-attempt0.out");
	ifstream cin("A-small-attempt0.in");
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string input, output = "";
		cin >> input;
		stringstream input_stream(input);
		char nextChar, maxChar = (char) 0;
		while (input_stream >> nextChar) {
			stringstream out_stream;
			if ((int)nextChar >=(int)maxChar) {
				out_stream << nextChar << output;
				maxChar = nextChar;
			}
			else {
				out_stream << output << nextChar;
			}
			output = out_stream.str();
		}
		cout << "Case #" << i + 1 << ": " << output << endl;
	}
	return 0;
}