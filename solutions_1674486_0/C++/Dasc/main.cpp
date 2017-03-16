/*
 * main.cpp
 *
 *  Created on: Mar 17, 2012
 *      Author: dasc
 */

#include <vector>
#include "InputData.h"
#include "OutputData.h"
#include "InputParser.h"
#include "OutputWriter.h"
#include "Solver.h"

int main(int argc, char **argv)
{
	std::vector<InputData> taskList;

	InputParser parser;
	parser.Parse(taskList);

	std::vector<OutputData> outputList;
	Solver solver;
	solver.Solve(taskList, outputList);

	OutputWriter writer;
	writer.Write(outputList);

	return 0;
}
