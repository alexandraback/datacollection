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

	outputData.bestCase = 1000000;

	double fullRight = 1;
	double sumOfPercentages = 0;
	std::vector<double> backspaceToHere;

	for(auto perc : inputData.correctnessPercentages)
	{
		fullRight *= perc;
		sumOfPercentages += perc;
	}

	int charsToComplete = inputData.totalNumberOfChars - inputData.numberOfTypedChars + 1;
	int fullEnter = inputData.totalNumberOfChars + 1;
	double keepTyping = charsToComplete * fullRight + (charsToComplete + fullEnter) * (1.0 - fullRight);

	double enterNow = 1 + fullEnter;

	for(int c = 1; c < inputData.numberOfTypedChars; c++)
	{
		int ifBackedEnough = charsToComplete + c * 2;
		int ifNotBackedEnough = ifBackedEnough + fullEnter;

		double upToHereProbability = 1;

		for(int i = 0; i < inputData.numberOfTypedChars - c; i++)
		{
			upToHereProbability *= inputData.correctnessPercentages[i];
		}

		double thisCaseAverage = ifBackedEnough * upToHereProbability + ifNotBackedEnough * (1.0 - upToHereProbability);

		// std::cout << keepTyping << " " << ifBackedEnough << " " << upToHereProbability << " " << thisCaseAverage << std::endl;

		if(thisCaseAverage < outputData.bestCase)
			outputData.bestCase = thisCaseAverage;
	}

	if(keepTyping < outputData.bestCase)
		outputData.bestCase = keepTyping;
	if(enterNow < outputData.bestCase)
		outputData.bestCase = enterNow;

	outputs.push_back(outputData);
}

void Solver::Solve(std::vector<InputData> &inputs, std::vector<OutputData> &outputs)
{
	for(auto data : inputs)
	{
		SolveCase(data, outputs);
	}
}
