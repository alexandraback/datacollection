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
		long N;

		input_file >> N;

		output_file << "Case #" << n << ":";

		if (N == 0) {
			output_file << " INSOMNIA" << std::endl;
			continue;
		}

		unsigned int digits = 0;
		long count = 0;

		while (digits != 0x03FF) {
			count += N;
			std::string number = std::to_string(count);
			for (int i = 0; i < number.length(); i++) {
				digits |= 1 << (number[i] - '0');
			}
		}

		output_file << " " << count << std::endl;
	}

	input_file.close();
	output_file.close();

	return 1;
}