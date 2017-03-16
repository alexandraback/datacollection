/*
 * OutputWriter.cpp
 *
 *  Created on: Mar 17, 2012
 *      Author: dasc
 */

#include "OutputWriter.h"
#include <fstream>
#include <iostream>
#include <sstream>

OutputWriter::OutputWriter() {
}

OutputWriter::~OutputWriter() {
}

void OutputWriter::Write(std::vector<OutputData> &outputList)
{
	std::ofstream myfile;

	std::cout.precision(6);

	int c = 0;
	for(auto outputData : outputList)
	{
		c++;
		std::string line;
		std::stringstream lineStream;

		lineStream << "Case #" << c << ": " << std::fixed << outputData.bestCase << std::endl;
		line = lineStream.str();

		std::cout << line;
	}
}

