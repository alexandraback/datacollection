#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "No input" << std::endl;
		return 0;
	}

	std::fstream input_file;
	std::fstream output_file;
	
	input_file.open(argv[1], std::fstream::in);
	output_file.open("output.txt", std::fstream::out);

	int T;
	input_file >> T;

	for (int n = 1; n <= T; n++) {
		std::string S;
		char word[2000];

		input_file >> S;

		char* begin = &word[999];
		char* end = &word[1000];

		output_file << "Case #" << n << ": ";

		*begin = S[0];
		for (int i = 1; i < S.length(); i++) {
			if (*begin <= S[i]) {
				begin--;
				*begin = S[i];
			}
			else {
				*end = S[i];
				end++;
			}
		}

		*end = 0;

		output_file << begin;
		output_file << std::endl;
	}

	input_file.close();
	output_file.close();

	return 1;
}