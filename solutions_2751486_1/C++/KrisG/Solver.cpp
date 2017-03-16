//
//  Solver.cpp
//  Google Code Jam 2013
//
//  Created by Kristopher Giesing on 4/12/13.
//  Copyright (c) 2013 Kristopher Giesing. All rights reserved.
//
#include <iostream>
#include <fstream>

#include <map>
#include <vector>
#include <set>
#include <list>

typedef size_t Solution;

class Solver
{
public:
	Solver(const std::string &iString, size_t iRunLen);
	
	void solve();
	
	Solution getSolution() { return mSolution; }
	
private:
	bool isConsonant(char iChar);
	bool startsRun(size_t index);
	
	size_t mRunLen;
	const std::string &mString;
	
	Solution mSolution;
	
};

Solver::Solver(const std::string &iString, size_t iRunLen)
: mString(iString),
  mRunLen(iRunLen),
  mSolution(0)
{
}

bool
Solver::isConsonant(char iChar) {
	return iChar!='a' && iChar!='e' && iChar!='i' && iChar!='o' && iChar!='u';
}

void
Solver::solve()
{
	size_t len = mString.size();
	std::list<size_t> runStarts;
	size_t curRunStart = -1;
	for (size_t i = 0; i < len; i++) {
		char c = mString[i];
		if (this->isConsonant(c)) {
			if (curRunStart == -1) {
				curRunStart = i;
			}
			if (i - curRunStart + 1 >= mRunLen) {
				runStarts.push_back(i - mRunLen + 1);
			}
		} else {
			curRunStart = -1;
		}
	}
	if (runStarts.size() > 0) {
		for (size_t i = 0; i < len; i++) {
			size_t nextRunStart = runStarts.front();
			size_t runEnd = nextRunStart + mRunLen;
			mSolution += len - runEnd + 1;
			if (i == nextRunStart) {
				runStarts.pop_front();
				if (runStarts.empty()) {
					break;
				}
			}
		}
	}
}

int main(int argc, const char * argv[])
{
//	std::string file = "/Users/kgiesing/Documents/Google Code Jam 2013/Google Code Jam 2013/Round 1c/Problem1/sample2.in.txt";
	std::string file = argv[1];
	std::ifstream input(file.c_str());
	file.replace(file.end()-6, file.end(), "out.txt");
	std::ofstream out(file.c_str());
	int nTests;
	input >> nTests;
	for (int i = 0; i < nTests; i++) {
		std::string s;
		size_t runLen;
		input >> s;
		input >> runLen;
		Solver solver(s, runLen);
		solver.solve();
		Solution solution = solver.getSolution();
		out << "Case #" << (i+1) << ": " << solution << "\n";
	}
	
    return 0;
}
