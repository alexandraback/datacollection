// googledancer.cpp : Defines the entry point for the console application.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <utility>

using namespace std;

int GetMaxNumber(int supperise, int least_score, multiset<int>& score_set)
{
	int no_supperise_score = least_score + 2*(least_score - 1 > 0? least_score - 1: 0);
	int supperise_score = least_score + 2*(least_score - 2 > 0? least_score - 2: 0);

	multiset<int>::iterator iter = score_set.lower_bound(no_supperise_score);

	int no_supperise_count = distance(iter, score_set.end());

	multiset<int>::iterator low_iter = score_set.lower_bound(supperise_score);
	int supperise_count = distance(low_iter, iter);
	supperise_count = (supperise_count > supperise ? supperise:supperise_count);
	

	return no_supperise_count + supperise_count;
}

int main(int argc, char* argv[])
{
	FILE* fp = fopen("B-small-attempt0.in", "r");
	FILE* fout = fopen("B-small.out", "w");

	char buffer[512] = {0};
	fgets(buffer, 512, fp);
	
	int case_count = atoi(buffer);
	case_count = (case_count > 100? 100: case_count);

	for (int i=0; i< case_count; i++)
	{
		fgets(buffer, 512, fp);
		char* pStr = strtok(buffer, " ");
		int number = atoi(pStr);

		pStr = strtok(NULL, " ");
		int supperise = atoi(pStr);

		pStr = strtok(NULL, " ");
		int least_score = atoi(pStr);

		multiset<int> score_set;		
		for (int j=0; j< number; j++)
		{
			pStr = strtok(NULL, " ");
			int score = atoi(pStr);
			score_set.insert(score);
		}

		int count = GetMaxNumber(supperise, least_score, score_set);
		fprintf(fout, "Case #%d: %d\n", i+1, count);

	}

	fclose(fout);
	fclose(fp);

	return 0;
}
