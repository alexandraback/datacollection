// loopnumber.cpp : Defines the entry point for the console application.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;


map<int, int> g_factor_cache;

int GetFactor(int n)
{
	map<int, int>::iterator iter;
	if ( (iter = g_factor_cache.find(n)) != g_factor_cache.end())
	{
		return iter->second;
	}
	int result = 1;
	for (int i=1; i<= n; i++)
	{
		result *= i;
	}
	g_factor_cache[n]= result;
	return result;

}

int GetPair(int all_count)
{
	return GetFactor(all_count) / (2 * GetFactor(all_count - 2)); 
}

set<int> g_result_cache;

int GetLoopCount(const char* str, int small, int big){
	
	set<int> loopSet;
	for (int i= 0; i< strlen(str); i++)
	{
		char buffer[16] = {0};
		strcpy(buffer, str+i);
		strncpy(buffer + (strlen(str) - i), str, i);
		int number = atoi(buffer);
		if (number >= small && number <= big)
		{			
			g_result_cache.insert(number);
			loopSet.insert(number);	
		}
	}
	if (loopSet.size() > 1)
	{
 		printf(str);
 		printf("\n");
 		//printf("%d\n", count);
		int pair = GetPair(loopSet.size());
		printf("pair: %d\n", pair);
		return pair;
	}else
		return 0;
}



int GetLoopCount(int small, int big)
{
	int count = 0;

	char strSmall[10] = {0};
	itoa(small, strSmall, 10);

	char strBig[10] = {0};
	itoa(big, strBig, 10);

	int dig_count = strlen(strSmall);	

	for (int i = small; i<= big; i++)
	{
		if(g_result_cache.find(i) != g_result_cache.end())
			continue;
		char buffer[16] = {0};
		itoa(i, buffer, 10);

		count += GetLoopCount(buffer, small, big);
	}

	return count;
}

int main(int argc, char* argv[])
{
	FILE* fp = fopen("C-small-attempt1.in", "r");
	FILE* fout = fopen("c-small.out", "w");

	char buffer[128] = {0};
	fgets(buffer, 128, fp);
	
	int case_count = atoi(buffer);
	case_count = (case_count > 50? 50: case_count);

	for (int i=0; i< case_count; i++)
	{
		fgets(buffer, 128, fp);

		int small, big;
		sscanf(buffer, "%d %d", &small, &big);	

		g_result_cache.clear();
		
		int count = GetLoopCount(small, big);
		fprintf(fout, "Case #%d: %d\n", i+1, count);
	}

	fclose(fout);
	fclose(fp);
	return 0;
}
