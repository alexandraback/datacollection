#include <stdio.h>
#include <vector>
#include <algorithm>

int war(const std::vector<double>& naomi, const std::vector<double>& ken)
{
	int score = 0;
	std::vector<double>::const_iterator itr2 = ken.begin();
	for(std::vector<double>::const_iterator itr = naomi.begin(); itr != naomi.end(); itr++)
	{
		while(itr2 != ken.end() && *itr2 < *itr)
			itr2++;
		if(itr2 != ken.end())
			itr2++;
		else
			score++;
	}
	return score;
}

int dwar(const std::vector<double>& naomi, const std::vector<double>& ken)
{
	int score = 0;
	std::vector<double>::const_iterator itr2 = naomi.begin();
	for(std::vector<double>::const_iterator itr = ken.begin(); itr != ken.end(); itr++)
	{
		while(itr2 != naomi.end() && *itr2 < *itr)
			itr2++;
		if(itr2 != naomi.end()){
			itr2++;
			score++;
		}
	}
	return score;
}

int main()
{
    FILE * pFile = fopen("D-large.in", "r");
	int T;
	fscanf(pFile, "%d", &T);
	for(int t = 0; t < T; t++)
	{
		double temp;
		int N;
		fscanf(pFile, "%d", &N);
		std::vector<double> naomi, ken;
		for(int i = 0; i < N; i++)
		{
			fscanf(pFile, "%lf", &temp);
			naomi.push_back(temp);
		}
		for(int i = 0; i < N; i++)
		{
			fscanf(pFile, "%lf", &temp);
			ken.push_back(temp);
		}
		std::sort(naomi.begin(), naomi.end());
		std::sort(ken.begin(), ken.end());
		printf("Case #%d: %d %d\n", t+1, dwar(naomi, ken), war(naomi, ken));
	}
	fclose(pFile);
	return 0;
}