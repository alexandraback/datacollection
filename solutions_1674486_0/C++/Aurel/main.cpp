
#include <iostream>
#include <fstream>
#include <vector>

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
		
		bool result = false;
		
		// Get the number of classes
		int N;
		in >> N;
		
		std::vector<std::vector<int> > links(N);
		for (int n = 0; n < N; n++) {
			links[n].resize(N);
		}
		for (int n = 0; n < N; n++) {
			int m;
			in >> m;
			
			for (int j = 0; j < m; j++) {
				int other;
				in >> other;
				other--;
				
				if (result == true) {
					continue;
				}

				if (links[n][other] == 1) {
					result = true;
					continue;
				}
				
				links[n][other] = 1;
				
				for (int k = 0; k < N; k++) {
					if (k == n) {
						continue;
					}
					
					if (links[k][n] == 0) {
						continue;
					}
					
					if (links[k][other] == 1) {
						result = true;
						break;
					}
					links[k][other] = 1;
				}
				
				for (int k = 0; k < N; k++) {
					if (links[other][k] == 0) {
						continue;
					}
					
					if (links[n][k] == 1) {
						result = true;
						break;
					}
					
					links[n][k] = 1;
				
					for (int l = 0; l < N; l++) {
						if (l == n) {
							continue;
						}
						
						if (links[l][n] == 0) {
							continue;
						}
						
						if (links[l][k] == 1) {
							result = true;
							break;
						}
						links[l][k] = 1;
					}
				}
				
				if (result == true) {
					continue;
				}
			}
		}
		
		// Ouput the result
		std::cout << "Case #" << i << ": " << ((result == true) ? "Yes" : "No") << std::endl;
		std::cerr << "Case #" << i << ": " << ((result == true) ? "Yes" : "No") << std::endl;
	}
	
	return 0;
}
