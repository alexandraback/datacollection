#include "HelperFunctions.h"

int reduce(std::string & s) {
	char findChar = s.front() == '-' ? '+' : '-';
	int endLoc = s.find(findChar);
	if(endLoc == -1) return findChar == '+';
	for(int a = 0; a < endLoc; a++) s[a] = findChar;
	return reduce(s) + 1;
}

int main() {
	std::string filename;
	std::cout << "Enter filename: ";
	std::getline(std::cin, filename);
	Problem p = getContentsOfFile(filename, 1, 0, 1, 0);
	int numCases = std::stoi(p.header[0]);
	std::vector<std::string> answers;
	for(int a = 0; a < numCases; a++) answers.push_back(std::to_string(reduce(p.cases[a][0])));
	writeCasesToFile("Output.txt", answers);
	getchar();
	getchar();
}