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
#include <iomanip>

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

		std::cout << "Case #" << c << ": " << (outputData.isDiamond ? "Yes" : "No") << std::endl;

		//std::cout << " " << std::setiosflags(std::ios::fixed) << std::setprecision(6) <<  result;
	}
}

