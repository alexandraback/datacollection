#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
        ifstream input;
        ofstream output;
        input.open("./Downloads/A-small-attempt0.in");
        output.open("result20160201");

        unsigned T;
        input >> T;

	for (unsigned t = 0; t < T; t ++) {
		string S;
		input >> S;

                string result = "";
                for (int i = 0; i < S.size(); i ++) {
                        if (i == 0 || result[0] <= S[i]) {
                                result = S[i] + result;
                        } else {
                                result = result + S[i];
                        }
                }
		output << "Case #" << t + 1 << ": " << result << endl;
	}

	return 0;
}
