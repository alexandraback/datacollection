
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <vector>

struct InputData
{
	int mResultToBeat;
	int mSurprising;
	std::vector<int> mTotalScores;
};
std::vector<InputData> DataSets;

void LoadData(const char* fname)
{
	std::fstream fin;
	fin.open(fname);
	int numCases = 0;
	fin >> numCases;

	for (int i = 0; i < numCases; i++)
	{
		InputData inputData;
		int numPeople = 0;
		fin >> numPeople;
		fin >> inputData.mSurprising;
		fin >> inputData.mResultToBeat;
		for (int n = 0; n < numPeople; n++)
		{
			int score = 0;
			fin >> score;
			inputData.mTotalScores.push_back(score);
		}

		DataSets.push_back(inputData);
	}
}

//***RULES***
//(A) anything that is at least  (p, (p-1), (p-1)) == (3p - 2) is non suprising and max
//(B) anything that is at least  (p, (p-2), (p-2)) == (3p - 4) is max	
//
// Any (A) could be made suprising, so the answer is going to be equal to:
//    ANSWER = (A) + max((B),suprisingResults);
//
int CalculateMaxNumber(int p, int suprisingReults, std::vector<int> scores)
{
	int A = 0;
	int B = 0;

	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i] >= p)
		{
			if (scores[i] >= 3*p-2)
				A++;
			else if (scores[i] >= 3*p-4)
				B++;
		}
	}

	if (B > suprisingReults)
		B = suprisingReults;

	return A+B;
}


int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Please provide an input file\n");
		return 1;
	}
	LoadData(argv[1]);

	for (int i = 0; i < DataSets.size(); i++)
	{
		int max = CalculateMaxNumber(DataSets[i].mResultToBeat, 
			DataSets[i].mSurprising, DataSets[i].mTotalScores);

		printf("Case #%d: %d\n", i+1, max);
	}

	return 0;
}
