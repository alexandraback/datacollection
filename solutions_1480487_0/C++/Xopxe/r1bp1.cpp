#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main(int argc, char* argv[])
{
	int numCases;
	std::cin >> numCases;
	for (int i=0; i<numCases; i++)
	{
		int numberContestants;
		std::cin >> numberContestants;
		std::vector<int> judgePoints;
		judgePoints.reserve(numberContestants);
		std::vector<int> ordered;
		ordered.reserve(numberContestants);
		int sum = 0;
		for (int j=0; j<numberContestants; ++j)
		{
			int point;
			std::cin >> point;
			sum += point;
			judgePoints.push_back(point);
			ordered.push_back(point);
		}
		sort(ordered.begin(), ordered.end());
		int skip = 0;
		int skipPoints = 0;
		std::vector<int>::reverse_iterator it;
		for (it=ordered.rbegin(); it!=ordered.rend(); ++it)
		{
			if ((*it)>((2*sum)/numberContestants))
			{
				skip++;
				skipPoints += (*it);
			}
		}
		std::cout << "Case #" << (i+1) << ":";
		for (int j=0; j<numberContestants; ++j)
		{
			double result = 0;
			double need = (double)(2*sum-skipPoints)/(numberContestants-skip) - judgePoints[j];
			if (need <= 0)
				result = 0;
			else
				result = (double) need/sum;
			std::cout << " " << std::setiosflags(std::ios::fixed) << std::setprecision(6) << (result*100);
		}
		std::cout << std::endl;
	}
	return 0;
}

