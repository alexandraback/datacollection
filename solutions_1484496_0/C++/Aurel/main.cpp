
#include <iostream>
#include <fstream>
#include <vector>

int N;
std::vector<int> numbers;

// Numbers 0 ... k-1 are already done
int solve(std::vector<int> partition, int total1, int total2, int totalRestant, int k)
{
	if (total1 == total2 && total1 > 0) {
		for (int set = 1; set <= 2; set++) {
			for (unsigned int i = 0; i < k; i++) {
				if (partition[i] == set) {
					std::cout << numbers[i] << " ";
				}
			}
			std::cout << std::endl;
		}
		return 1;
	}

	if (k >= N) {
		return 0;
	}

	if (total1 > total2 + totalRestant || total2 > total1 + totalRestant) {
		return 0;
	}

	partition[k] = 1;
	if (1 == solve(partition, total1 + numbers[k], total2, totalRestant - numbers[k], k+1)) {
		return 1;
	}

	partition[k] = 2;
	if (1 == solve(partition, total1, total2 + numbers[k], totalRestant - numbers[k], k+1)) {
		return 1;
	}
	
	partition[k] = 0;
	if (1 == solve(partition, total1, total2, totalRestant - numbers[k], k+1)) {
		return 1;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " inputfile" << std::endl;
		return 1;
	}
	
	std::ifstream in(argv[1]);
	
	// Get the number of test cases
	unsigned int T;
	in >> T;
	
	// Iterate through all test cases
	for (unsigned int i = 1; i <= T; i++) {
		
		// Get the number of numbers
		in >> N;
		
		// Get the numbers
		numbers.resize(N);
		int total = 0;
		for (unsigned int n = 0; n < N; n++) {
			in >> numbers[n];
			total += numbers[n];
		}
		
		std::vector<int> partition(N);
		std::cout << "Case #" << i << ":" << std::endl;
		if (0 == solve(partition, 0, 0, total, 0)) {
			std::cout << "Impossible" << std::endl;
		}
	}
	
	return 0;
}
