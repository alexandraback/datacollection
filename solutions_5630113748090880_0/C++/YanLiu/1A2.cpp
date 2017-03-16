#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
        ifstream input;
        ofstream output;
        input.open("./Downloads/B-small-attempt0.in");
        output.open("result20160202");

        unsigned T;
        input >> T;

	for (unsigned t = 0; t < T; t ++) {
		unsigned N;
		input >> N;
                vector<int> num_c(2501, 0);
                for (int i = 0; i < 2 * N - 1; i ++) {
                        for (int j = 0; j < N; j ++) {
                                int temp;
                                input >> temp;
                                num_c[temp] ++;
                        }
                }

                vector<int> result;
                for (int i = 0; i <= 2500; i ++) {
                        if (num_c[i] % 2 == 1) {
                                result.push_back(i);
                        }
                }

		output << "Case #" << t + 1 << ": ";
                for (int i = 0; i < result.size(); i ++) {
                         output << result[i] << " ";
                }
                output << endl;
	}

	return 0;
}
