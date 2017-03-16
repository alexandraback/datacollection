#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <hash_set>
#include <map>
#include <set>
#include <array>

#define FILE_BUF_SIZE 512
#define MAX_K 100
#define MAX_S 100

using namespace std;



int main()
{
	// Prepare file
	FILE* inputFile;
	fopen_s(&inputFile, "B-small-attempt2.in", "r");
	if (inputFile == nullptr)
	{
		printf("Input file open error!\n");
	}

	FILE* outputFile;
	fopen_s(&outputFile, "Small-Output.txt", "w");
	if (outputFile == nullptr)
	{
		printf("Output file open error!\n");
	}

	// Read count of test case
	char fileBuf[FILE_BUF_SIZE + 1];
	fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);
	int countOfTestCase = atoi(fileBuf);

	int k = 0;
	int l = 0;
	int s = 0;
	char targetWord[MAX_S + 1];
	for (int caseNo = 1; caseNo <= countOfTestCase; caseNo++)
	{
		memset(targetWord, NULL, sizeof(targetWord));

		// Read K, L, S
		fscanf(inputFile, "%d %d %d", &k, &l, &s);
		fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);

		// Read keyboard letter
		std::map<char, int> keyobardLetterMap;
		fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);
		for (int i = 0; i < k; i++)
		{
			auto it = keyobardLetterMap.find(fileBuf[i]);
			if (it != keyobardLetterMap.end())
				it->second++;
			else
				keyobardLetterMap.emplace(fileBuf[i], 1);
		}

		// Read target word
		std::set<char> targetLetterSet;
		fgets(targetWord, MAX_S + 1, inputFile);
		for (int i = 0; i < l; i++)
		{
			targetLetterSet.emplace(targetWord[i]);
		}

		// Enough keyboard letter?
		bool enough = true;
		for (int i = 0; i < l; i++)
		{
			auto it = keyobardLetterMap.find(targetWord[i]);
			if (it == keyobardLetterMap.end())
			{
				enough = false;
				break;
			}
		}

		// Always true
		bool alwaysTrue = false;
		if (keyobardLetterMap.size() ==1 && targetLetterSet.size() == 1)
			alwaysTrue = true;

		if (enough == false || alwaysTrue == true)
		{
			fprintf(outputFile, "Case #%d: 0.0 \n", caseNo);
			continue;
		}



		int maxBanana = s / l;				
		
		int result = -1;
		for (int i = 0; i < l - 1; i++)
		{
			if (strncmp(&(targetWord[l - i - 1]), targetWord, i + 1) == 0)
			{
				result = i;
			}
		}

		if (result != -1)
		{
			result++;

			int tempS = s;
			tempS -= l;
			maxBanana = 1;
			maxBanana += (tempS / (l - result));

			double oneProbability = 1.f;
			for (int i = 0; i < l; i++)
			{
				auto it = keyobardLetterMap.find(targetWord[i]);
				oneProbability *= static_cast<double>(it->second) / static_cast<double>(k);
			}

			double probability = oneProbability;
			oneProbability = 1.f;
			for (int i = result; i < l; i++)
			{
				auto it = keyobardLetterMap.find(targetWord[i]);
				oneProbability *= static_cast<double>(it->second) / static_cast<double>(k);
			}
			probability += (oneProbability * (maxBanana - 1));

			double remain = maxBanana - probability * maxBanana;
			fprintf(outputFile, "Case #%d: %6f \n", caseNo, remain);
		}
		else
		{
			double probability = 1.f;
			for (int i = 0; i < l; i++)
			{
				auto it = keyobardLetterMap.find(targetWord[i]);
				probability *= static_cast<double>(it->second) / static_cast<double>(k);
			}

			double remain = maxBanana - probability * maxBanana;
			fprintf(outputFile, "Case #%d: %6f \n", caseNo, remain);
		}

	}

	return 1;
}
