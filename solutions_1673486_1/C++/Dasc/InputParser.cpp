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

		iss >> data.numberOfTypedChars;
		iss >> data.totalNumberOfChars;

		getline(std::cin, line);
		std::istringstream issPerc(line);

		for(int i = 0; i < data.numberOfTypedChars; i++)
		{
			double percentage = 1;
			issPerc >> percentage;
			data.correctnessPercentages.push_back(percentage);

			//std::cout << percentage;
		}
		//std::cout << std::endl;

		taskList.push_back(data);
	 }
}
