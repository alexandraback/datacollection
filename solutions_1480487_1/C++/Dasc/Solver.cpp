/*
 * Solver.cpp
 *
 *  Created on: Mar 17, 2012
 *      Author: dasc
 */

#include "Solver.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

#include <math.h>

Solver::Solver() {
}

Solver::~Solver() {
}


void SolveCase(InputData &inputData, std::vector<OutputData> &outputs)
{
	//std::cout << "new case" << std::endl;

	OutputData outputData;

	int totalPoints = inputData.sum * 2;
	double averagePoints = (double)totalPoints / (double) inputData.votes.size();

	int howmanyCanLoose = 0;
	for(auto vote : inputData.votes)
	{
		if(vote <= averagePoints)
			howmanyCanLoose++;
		else
			totalPoints -= vote;
	}

	//std::cout << howmanyCanLoose << std::endl;

	double neededAverage = (double)totalPoints / howmanyCanLoose;

	for(auto vote : inputData.votes)
	{
		//std::cout << " points "<< vote << std::endl;
		double neededAdditionalPoints = neededAverage - (double)vote;

		double result = (neededAdditionalPoints / (double)inputData.sum) * 100.0;
		if(result < 0)
			result = 0;


		outputData.results.push_back(result);

	}

	outputs.push_back(outputData);
}

void Solver::Solve(std::vector<InputData> &inputs, std::vector<OutputData> &outputs)
{
	for(auto data : inputs)
	{
		SolveCase(data, outputs);
	}
}
