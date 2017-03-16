#include "HelperFunctions.h"
#include <map>

std::string solve(const std::string & s) {
	std::map<char, int> letterCounts;
	for(auto a = s.begin(); a != s.end(); a++) if(letterCounts.count(*a)) letterCounts[*a]++;
	else letterCounts.insert({ *a, 1 });

	std::map<int, int> numCounts;

	std::string answer;

	//Z is unique to 0:
	numCounts[0] = letterCounts['Z'];
	letterCounts['E'] -= letterCounts['Z'];
	letterCounts['R'] -= letterCounts['Z'];
	letterCounts['O'] -= letterCounts['Z'];
	letterCounts['Z'] = 0;

	//G is unique to 8:
	numCounts[8] = letterCounts['G'];
	letterCounts['E'] -= letterCounts['G'];
	letterCounts['I'] -= letterCounts['G'];
	letterCounts['H'] -= letterCounts['G'];
	letterCounts['T'] -= letterCounts['G'];
	letterCounts['G'] = 0;

	//U is unique to 4:
	numCounts[4] = letterCounts['U'];
	letterCounts['F'] -= letterCounts['U'];
	letterCounts['O'] -= letterCounts['U'];
	letterCounts['R'] -= letterCounts['U'];
	letterCounts['U'] = 0;

	//R is now unique to 3:
	numCounts[3] = letterCounts['R'];
	letterCounts['T'] -= letterCounts['R'];
	letterCounts['H'] -= letterCounts['R'];
	letterCounts['E'] -= 2 * letterCounts['R'];
	letterCounts['R'] = 0;

	//W is unique to 2:
	numCounts[2] = letterCounts['W'];
	letterCounts['T'] -= letterCounts['W'];
	letterCounts['O'] -= letterCounts['W'];
	letterCounts['W'] = 0;

	//O is now unique to 1:
	numCounts[1] = letterCounts['O'];
	letterCounts['N'] -= letterCounts['O'];
	letterCounts['E'] -= letterCounts['O'];
	letterCounts['O'] = 0;

	//F is now unique to 5:
	numCounts[5] = letterCounts['F'];
	letterCounts['I'] -= letterCounts['F'];
	letterCounts['V'] -= letterCounts['F'];
	letterCounts['E'] -= letterCounts['F'];
	letterCounts['F'] = 0;

	//X is unique to 6:
	numCounts[6] = letterCounts['X'];
	letterCounts['S'] -= letterCounts['X'];
	letterCounts['I'] -= letterCounts['X'];
	letterCounts['X'] = 0;

	//V is now unique to 7:
	numCounts[7] = letterCounts['V'];
	letterCounts['S'] -= letterCounts['V'];
	letterCounts['E'] -= 2 * letterCounts['V'];
	letterCounts['N'] -= letterCounts['V'];
	letterCounts['V'] = 0;

	//N is now unique to 9:
	numCounts[9] = letterCounts['N'] / 2;

	for(int a = 0; a < 10; a++) for(int b = 0; b < numCounts[a]; b++) answer.push_back(a + 48); //Convert to ascii.

	return answer;
}

int main() {
	std::string filename;
	std::cout << "Enter filename: ";
	std::getline(std::cin, filename);
	Problem p = getContentsOfFile(filename, 1, 0, 1, 0);
	int numCases = std::stoi(p.header[0]);
	std::vector<std::string> answers;
	for(int a = 0; a < numCases; a++) answers.push_back(solve(p.cases[a][0]));
	writeCasesToFile("Output.txt", answers);
	getchar();
}