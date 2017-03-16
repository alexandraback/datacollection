
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
	int T;
	in >> T;
	
	// Iterate through all test cases
	for (int i = 1; i <= T; i++) {
		
		// Get the number of contestants
		int N;
		in >> N;
		
		// Get their score
		std::vector<float> scores(N);
		float X = 0;
		for (int n = 0; n < N; n++) {
			in >> scores[n];
			X += scores[n];
		}
		
		// Ouput the result
		std::cout << "Case #" << i << ":";
		
		for (int n = 0; n < N; n++) {
			float result;
			for (int achieved = scores[n]; achieved <= scores[n] + X; achieved++) {
				float remaining = scores[n] + X - achieved;
				float contestantsValue = 0;
				float contestants = 0;
				for (int k = 0; k < N; k++) {
					if (k == n) {
						continue;
					}
					
					if (scores[k] > achieved) {
						continue;
					}
					
					contestants++;
					contestantsValue += scores[k];
				}
				if (contestants == 0) {
					continue;
				}
				
				if ((remaining + contestantsValue) / contestants > achieved) {
					continue;
				}
				
				result = contestantsValue / contestants + X / contestants - scores[n];
				result /= (X + X / contestants);
				result *= 100;
				if (result < 0) {
					result = 0;
				}
				break;
			}
			std::cout << " " << result;
		}
		std::cout << std::endl;
	}
	
	return 0;
}
