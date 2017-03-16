/*
 * InputParser.cpp
 *
 *  Created on: Mar 17, 2012
 *      Author: dasc
 */

#include "InputParser.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

InputParser::InputParser() {
}

InputParser::~InputParser() {
}

bool myfunction (int i, int j) { return (i<j); }

void InputParser::Parse(std::vector<InputData> &taskList)
{
	int lineNumber;
	std::cin >> lineNumber;
	std::cin.get();

	int count = 0;
	while(count++ < lineNumber) {
		InputData data;
		std::string line;
		getline(std::cin, line);

		std::istringstream iss(line);

		int number;
		iss >> number;

		for(int i = 0; i < number; i++)
		{
			std::string classLine;
			getline(std::cin, classLine);
			std::istringstream issl(classLine);

			std::vector<int> path;
			int numberOfPaths;
			issl >> numberOfPaths;
			for(int c = 0; c < numberOfPaths; c++)
			{
				int pathMember;
				issl >> pathMember;
				path.push_back(pathMember);
			}

			data.classPaths.push_back(path);
		}

		taskList.push_back(data);
	 }
}
