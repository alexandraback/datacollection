
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>


struct Level
{
	int CompletedStars;
	int OneStarReq;
	int TwoStarReq;
};

bool SortByHighestTwoStars(Level A, Level B) 
{
	return (A.TwoStarReq > B.TwoStarReq);
}

void ClearOutTwoStars(int& stars, int& played, std::vector<Level>& lvls)
{
	int prevStars = -1;
	while (prevStars != stars)
	{
		prevStars = stars;

		for (int i = 0; i < lvls.size(); i++)
		{
			if (lvls[i].CompletedStars == 2) continue;

			if (lvls[i].TwoStarReq <= stars)
			{
				stars += 2 - lvls[i].CompletedStars;
				lvls[i].CompletedStars = 2;
				played++;
			}	
		}
	}
}



int CalculateMinLevels(std::vector<Level> lvls)
{
	int stars = 0;
	int played = 0;

	std::sort(lvls.begin(), lvls.end(), SortByHighestTwoStars);
	
	ClearOutTwoStars(stars, played, lvls);

	bool madeChange = true;
	while (madeChange)
	{
		madeChange = false;
	
		for (int i = 0; i < lvls.size(); i++)
		{
			if (lvls[i].CompletedStars > 0) continue;

			if (lvls[i].OneStarReq <= stars)
			{
				lvls[i].CompletedStars = 1;
				played++;
				stars += 1;
				madeChange = true;
				break;
			}
		}

		ClearOutTwoStars(stars, played, lvls);	
	}

	for (int i = 0; i < lvls.size(); i++)
	{
		if (lvls[i].CompletedStars != 2)
		{
			played = -1;
			break;
		}
	}

	return played;
}


int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Please provide an input file\n");
		return 1;
	}
	std::fstream fin;
	fin.open(argv[1]);

	int testCases = 0;
	fin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		std::vector<Level> levels;
		int numLevels;
		fin >> numLevels;
		for (int l = 0; l < numLevels; l++)
		{
			Level lvl;
			fin >> lvl.OneStarReq >> lvl.TwoStarReq;

			//ensure two star require is always higher than 1 star req.
			if (lvl.TwoStarReq < lvl.OneStarReq)
			{
				int swapsie = lvl.OneStarReq;
				lvl.OneStarReq = lvl.TwoStarReq;
				lvl.TwoStarReq = swapsie;
			}
			lvl.CompletedStars = 0;

			levels.push_back(lvl);
		}

		int result = CalculateMinLevels(levels);

		if (result == -1)
		{
			printf("Case #%d: Too Bad\n", i+1);
		}
		else
		{
			printf("Case #%d: %d\n", i+1, CalculateMinLevels(levels));
		}
		
	}

	fin.close();
	return 0;
}
