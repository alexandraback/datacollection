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

		int partecipants;
		iss >> partecipants;

		data.sum = 0;

		for(int i = 0; i < partecipants; i++)
		{
			int vote;

			iss >> vote;

			data.sum += vote;

			data.votes.push_back(vote);
		}

		taskList.push_back(data);
	 }
}
