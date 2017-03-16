
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <map>


unsigned int getNumberLength(unsigned int n)
{
	std::ostringstream stream;
	stream << n;
	return stream.str().size();
}

unsigned int shiftOne(unsigned int n, unsigned int p)
{
	unsigned int r = n % 10;
	n = (n/10) + r*p;
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
		// Get the case parameters
		unsigned int A, B;
		in >> A;
		in >> B;
		
		unsigned int length = getNumberLength(A);
		unsigned int power = pow(10, length - 1);
		
		unsigned int result = 0;
		for (unsigned int n = A; n < B; n++) {
			std::map<unsigned int, bool> added;
			unsigned int m = n;
			for (unsigned int shifts = 0; shifts < length - 1; shifts++) {
				m = shiftOne(m, power);
				
				if (m > n && m <= B && !added[m]) {
					result++;
					added[m] = true;
				}
			}
		}
		
		// Ouput the result
		std::cout << "Case #" << i << ": " << result << std::endl;
	}
	
	return 0;
}
