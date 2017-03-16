#include <iostream>
#include <fstream>

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
		int K, C, S;

		input_file >> K;
		input_file >> C;
		input_file >> S;

		output_file << "Case #" << n << ":";

		if (C * S < K) {
			output_file << " IMPOSSIBLE" << std::endl;
			continue;
		}

		unsigned long table[100];
		table[0] = 1;
		for (int i = 1; i < C; i++) {
			table[i] = table[i - 1] * K;
		}

		int checked = 0;
		while (checked < K) {
			unsigned long pos = 1;
			for (int i = 0; i < C; i++) {
				if (checked + i >= K)
					break;
				pos += table[i] * (checked + i);
			}
			output_file << " " << pos;
			checked += C;
		}
		

		output_file << std::endl;
	}

	input_file.close();
	output_file.close();

	return 1;
}