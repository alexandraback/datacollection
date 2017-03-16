// gcj_2c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int Solve(int C, int D, int V, map<int, bool>* coins)
{
	int result = 0;
	for (int counter = 1; counter <= V; ++counter)	// check every price
	{
		if (coins->find(counter) != coins->end())
		{
			continue;
		}
		else
		{
			map<int, bool> dyn = map<int, bool>();
			map<int, bool> dyn2 = map<int, bool>();
			auto den = coins->begin();
			bool flag = true;
			bool found = false;			
			for (int weight = 0; weight <= C; ++ weight)
			{
				int r = (*den).first * weight;
				if (r == counter)
				{
					flag = false;
					found = true;
				}
				dyn.insert(std::pair<int, bool>((*den).first * weight, true));			
			}
			den++;
			while (den != coins->end() && flag && !found)
			{
				for (auto iterCount = dyn.begin(); iterCount != dyn.end(); ++iterCount)
				{
					for (int weight = 0; weight <= C; ++ weight)
					{
						int r = (*iterCount).first + (*den).first * weight;
						if (r == counter)
						{
							flag = false;
							found = true;
							goto nextCoin;
						}
						if (dyn2.find(r) == dyn2.end())
						{
							dyn2.insert(std::pair<int, bool>(r, true));
						}
					}
				}
				dyn.clear();
				dyn = std::map<int, bool>(dyn2.begin(), dyn2.end());
				dyn2.clear();
				if (dyn.size() == 0)
				{
					std::cout << "Error!";
				}
				den++;
			}
nextCoin:
			if (!found)
			{
				coins->insert(std::pair<int, bool>(counter, true));
			}
		}
	}
	return coins->size() - D;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input = ifstream("input.txt");
	ofstream output = ofstream("output.txt");
	int T = 0;
	input >> T;
	for (int counter = 0; counter < T; ++ counter)
	{
		int C = 0, D = 0, V = 0;
		input >> C;
		input >> D;
		input >> V;
		int den = 0;
		map<int, bool> coins = map<int, bool>();
		for (int denCount = 0; denCount < D; ++denCount)
		{
			input >> den;
			coins.insert(std::pair<int, bool>(den, true));
		}
		int result = Solve(C,D,V, &coins);
		output << "Case #" << counter + 1 << ": " << result << "\r\n";
	}
	output.flush();
	output.close();
	input.close();
	return 0;
}

