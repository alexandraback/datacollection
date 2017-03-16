#include "HelperFunctions.h"
#include <sstream>

int main() {
	Problem p = getContentsOfFile("Input.txt", 1, 0, 1, 0);
	long long numCases = std::stoi(p.header[0]);
	std::vector<std::string> answers;
	for(long long a = 0; a < numCases; a++) {
		std::stringstream ss = std::stringstream{ p.cases[a][0] };
		long long k, c, s; ss >> k >> c >> s;
		std::string answer;
		if(s < k) answer = "IMPOSSIBLE";
		else {
			long long tiles = 1; for(long long b = 0; b < c; b++) tiles *= k;
			for(long long b = 1; b <= tiles; b += tiles / k) {
				answer += std::to_string(b) + ' ';
			}
			answer.pop_back();
		}
		answers.push_back(answer);
	}
	writeCasesToFile("Output.txt", answers);
	getchar();
}