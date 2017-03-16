#include "HelperFunctions.h"
#include <map>

int val(const std::vector<int> & v, std::string s) {
	int loc = 0;
	for(auto a = s.begin(); a != s.end(); a++) if(*a == '?') {
		*a = v[loc] + 48;
		loc++;
	}
	std::string cs, js;
	auto a = s.begin();
	while(*a != ' ') {
		cs.push_back(*a);
		a++;
	}
	a++;
	while(a != s.end()) {
		js.push_back(*a);
		a++;
	}
	int coderScore = std::stoi(cs);
	int jammerScore = std::stoi(js);
	return (abs(coderScore - jammerScore) * 1000000) + coderScore * 1000 + jammerScore;
}

int lowestValueFound; std::vector<int> answer;
int getLowest(int length, std::vector<int> v, const std::string & s) {
	if(length == 0) {
		int vl = val(v, s);
		if(vl < lowestValueFound) {
			answer = v;
			lowestValueFound = vl;
		}
		return vl;
	}
	int lowestVal = INT_MAX;
	for(int a = 0; a < 10; a++) {
		v.push_back(a);
		int vl = getLowest(length - 1, v, s);
		if(lowestVal > vl) lowestVal = vl;
		v.pop_back();
	}
}

std::string solve(std::string s) {
	int length = std::count(s.begin(), s.end(), '?');
	lowestValueFound = INT_MAX;
	getLowest(length, std::vector<int>(), s);
	int loc = 0;
	for(auto a = s.begin(); a != s.end(); a++) if(*a == '?') {
		*a = answer[loc] + 48;
		loc++;
	}
	return s;
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