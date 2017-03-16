
#include <iostream>
#include <fstream>

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
		
		// Get the number of Googlers
		unsigned int N;
		in >> N;
		
		// Get the number of surprising triplets
		unsigned int S;
		in >> S;
		
		// Get p
		unsigned int p;
		in >> p;
		
		// Iterate through all the Googlers
		unsigned int result = 0;
		for (unsigned int n = 0; n < N; n++) {
			unsigned int total;
			in >> total;
			
			unsigned int q = total / 3;
			unsigned int r = total % 3;
			
			if (r == 0) {
				if (q >= p) {
					result++;
				} else if (S > 0 && q > 0 && q < 10 && q+1 >= p) {
					result++;
					S--;
				}
			} else if (r == 1) {
				if (q + 1 >= p) {
					result++;
				}
			} else {
				if (q + 1 >= p) {
					result++;
				} else if (S > 0 && q < 9 && q+2 >= p) {
					result++;
					S--;
				}
			}
		}
		
		// Ouput the result
		std::cout << "Case #" << i << ": " << result << std::endl;
	}
	
	return 0;
}
