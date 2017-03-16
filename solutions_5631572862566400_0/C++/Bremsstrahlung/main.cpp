#include <iostream>
#include <fstream>
#include <string>

struct node {
	int loop;
	int pos;
	int bf;
	int special;
};

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
		node F[1001];

		output_file << "Case #" << n << ": ";

		input_file >> N;
		for (int i = 1; i <= N; i++) {
			F[i].loop = 0;
			F[i].pos = 0;
			F[i].special = 0;
			input_file >> F[i].bf;
		}

		for (int i = 1; i <= N; i++) {
			if (F[F[i].bf].bf == i) {
				F[i].special = 1;
			}
		}
		
		int result = 0;

		for (int i = 1; i <= N; i++) {
			if (F[i].special) {
				continue;
			}
			int current = i;
			int len = 1;
			while (F[current].loop != i && !F[current].special) {
				if (F[current].pos > len) {
					len = 0;
					break;
				}
				F[current].pos = len;
				F[current].loop = i;
				current = F[current].bf;
				len++;
			}

			if (F[current].special && F[current].special < len) {
				F[current].special = len;
			}
			else if (len) {
				int loop = len - F[current].pos;
				if (result < loop) {
					result = loop;
				}
			}
		}

		int base = 0;
		int max1 = 0;
		int max2 = 0;
		for (int i = 1; i <= N; i++) {
			if (F[i].special) {
				if (F[F[i].bf].special == 1) {
					if (F[i].special == 1) {
						base++;
					}
					else {
						if (F[i].special > max1) {
							max2 = max1;
							max1 = F[i].special;
						}
						else if(F[i].special > max2) {
							max2 = F[i].special;
						}
					}
				}
				else {
					int loop = F[i].special + F[F[i].bf].special;
					if (loop > result)
						result = loop;
				}
			}	
		}

		int loop = base + max1 + max2;
		if (loop > result) {
			result = loop;
		}

		output_file << result;
		output_file << std::endl;
	}

	input_file.close();
	output_file.close();

	return 1;
}