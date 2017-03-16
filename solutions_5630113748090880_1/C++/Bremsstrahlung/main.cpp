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
		int N;
		int heights[2501];

		input_file >> N;

		for (int i = 1; i <= 2500; i++) {
			heights[i] = 0;
		}

		int entries = (2 * N - 1) * N;
		for (int i = 0; i < entries; i++) {
			int h;
			input_file >> h;
			heights[h] += 1;
		}

		output_file << "Case #" << n << ":";

		for (int i = 1; i <= 2500; i++)
			if (heights[i] & 1)
				output_file << " " << i;
		
		output_file << std::endl;
	}

	input_file.close();
	output_file.close();

	return 1;
}