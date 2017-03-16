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
		std::string seq;

		input_file >> seq;

		output_file << "Case #" << n << ": ";

		int flip = 0;
		char last_char = seq[0];
		for (int i = 1; i < seq.length(); i++) {
			if (seq[i] != last_char) {
				flip++;
				last_char = seq[i];
			}
		}

		if (last_char == '-') {
			flip++;
		}

		output_file << flip << std::endl;
	}

	input_file.close();
	output_file.close();

	return 1;
}