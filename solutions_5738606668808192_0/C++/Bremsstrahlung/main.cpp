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

	long T, N, J;
	input_file >> T;
	input_file >> N;
	input_file >> J;

	output_file << "Case #1:" << std::endl;

	unsigned long coin = (1 << (N - 1)) + 1;
	int i = 1;

	while (i <= J) {
		int divisors[9];
		int base = 2;
		while (base <= 10) {
			unsigned long coin_cast = 0;
			for (int k = 1; k <= N; k++) {
				coin_cast *= base;
				coin_cast += ((coin >> (N - k)) & 0x0001);
			}

			int j = base + 1;
			while (j < 10000) {
				if (coin_cast % j == 0) {
					divisors[base - 2] = j;
					break;
				}
				j++;
			}

			if (j == 10000)
				break;
			base++;
		}

		if (base > 10) {
			for (int k = 1; k <= N; k++) {
				output_file << ((coin >> (N - k)) & 0x01);
			}
			output_file << " ";
			for (int j = 0; j < 9; j++)
				output_file << " " << divisors[j];
			output_file << std::endl;
			i++;
		}

		coin += 2;
	}

	input_file.close();
	output_file.close();

	return 1;
}