#include "HelperFunctions.h"
#include <map>
#include <set>

std::map<std::string, std::pair<int, bool> > word1Appearances, word2Appearances;

std::string solve(std::vector<std::string> s) {
	word1Appearances.clear();
	word2Appearances.clear();

	std::set< std::pair<std::string, std::string> > topics;
	for(auto a = s.begin(); a != s.end(); a++) {
		std::string word1, word2;
		auto b = a->begin();
		while(*b != ' ') {
			word1.push_back(*b);
			b++;
		}
		b++;
		while(b != a->end()) {
			word2.push_back(*b);
			b++;
		}

		if(word1Appearances.count(word1)) word1Appearances[word1].first++;
		else word1Appearances.insert({ word1, { 1, false } });

		if(word2Appearances.count(word2)) word2Appearances[word2].first++;
		else word2Appearances.insert({ word2, { 1, false } });

		topics.insert({ word1, word2 });
	}

	//Cut out things with original words.
	bool changesMade = true;
	while(changesMade) {
		changesMade = false;
		for(auto a = topics.begin(); a != topics.end();) {
			bool shouldErase = false;
			if(word1Appearances[a->first].first == 1 && !word1Appearances[a->first].second) {
				word1Appearances.erase(a->first);
				shouldErase = true;
			}
			if(word2Appearances[a->second].first == 1 && !word2Appearances[a->second].second) {
				word2Appearances.erase(a->second);
				shouldErase = true;
			}

			if(shouldErase) {
				changesMade = true;
				if(word1Appearances.count(a->first)) {
					word1Appearances[a->first].first--;
					word1Appearances[a->first].second = true;
				}
				if(word2Appearances.count(a->second)) {
					word2Appearances[a->second].first--;
					word2Appearances[a->second].second = true;
				}
				a = topics.erase(a);
			}
			else a++;
		}
	}

	return std::to_string(int(topics.size()));
}

int main() {
	std::string filename;
	std::cout << "Enter filename: ";
	std::getline(std::cin, filename);
	Problem p = getContentsOfFile(filename, 1, 0, 0, 0); //Using modified one for this:
	int numCases = std::stoi(p.header[0]);
	std::vector<std::string> answers;
	for(int a = 0; a < numCases; a++) answers.push_back(solve(p.cases[a]));
	writeCasesToFile("Output.txt", answers);
	getchar();
}