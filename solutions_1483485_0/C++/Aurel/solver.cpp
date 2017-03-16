
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " inputfile" << std::endl;
		return 1;
	}
	
	std::ifstream in(argv[1]);
	
	// Mapping deduced from the examples
	char mapping[256];
	mapping['a'] = 'y';
	mapping['b'] = 'h';
	mapping['c'] = 'e';
	mapping['d'] = 's';
	mapping['e'] = 'o';
	mapping['f'] = 'c';
	mapping['g'] = 'v';
	mapping['h'] = 'x';
	mapping['i'] = 'd';
	mapping['j'] = 'u';
	mapping['k'] = 'i';
	mapping['l'] = 'g';
	mapping['m'] = 'l';
	mapping['n'] = 'b';
	mapping['o'] = 'k';
	mapping['p'] = 'r';
	mapping['q'] = 'z';
	mapping['r'] = 't';
	mapping['s'] = 'n';
	mapping['t'] = 'w';
	mapping['u'] = 'j';
	mapping['v'] = 'p';
	mapping['w'] = 'f';
	mapping['x'] = 'm';
	mapping['y'] = 'a';
	mapping['z'] = 'q';
	mapping[' '] = ' ';
	
	
	// Get the number of test cases
	unsigned int N;
	in >> N;
	
	// Remove the line with the number of test cases
	std::string line;
	std::getline(in, line);
	
	// Iterate through all test cases
	for (unsigned int i = 1; i <= N; i++) {
		// Read the next line from the input
		std::getline(in, line);
		
		// Translate this line from Googlerese
		std::cout << "Case #" << i << ": ";
		
		unsigned int l = line.size();
		for (unsigned int k = 0; k < l; k++) {
			std::cout << mapping[line[k]];
		}
		
		std::cout << std::endl;
	}
	
	return 0;
}
