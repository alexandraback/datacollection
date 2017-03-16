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
#include <memory>
#include <math.h>
#include <stdio.h>
#include <string.h>

Solver::Solver() {
}

Solver::~Solver() {
}

void SolveCase(InputData &inputData, std::vector<OutputData> &outputs)
{
	//std::cout << "new case" << std::endl;

	OutputData outputData;
	outputData.isDiamond = false;

	for(auto path : inputData.classPaths)
	{
		//std::cout << "new class" << std::endl;

		std::vector<int> pathCopy = path;
		std::vector<int> nextPathCopy;
		std::vector<int> chain;

		while(pathCopy.size() > 0)
		{
			for(auto classNumber : pathCopy)
			{
				//std::cout << " " << classNumber;

				chain.push_back(classNumber);

				for(auto reducedClassNumber: inputData.classPaths[classNumber - 1])
				{
					//std::cout << "addo " << reducedClassNumber << std::endl;
					nextPathCopy.push_back(reducedClassNumber);
				}
			}

			//std::cout << std::endl;

			pathCopy = nextPathCopy;
			nextPathCopy.clear();
		}

		//find duplicates
		std::map<int, int> duplicates;
		for(int i = 0; i < inputData.classPaths.size(); i++)
		{
			duplicates[i] = 0;
		}

		for(auto classNumber : chain)
		{
			if(duplicates[classNumber - 1] > 0)
			{
				outputData.isDiamond = true;
				outputs.push_back(outputData);
				return;
			}
			else
				duplicates[classNumber - 1]++;
		}
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
