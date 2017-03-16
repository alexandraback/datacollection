#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main(void)
{
	unsigned int number_of_tests;
	scanf("%u\n", &number_of_tests);
	for (unsigned int test = 0; test < number_of_tests; ++test)
	{
		printf("Case #%u:", test + 1);

		unsigned int block_count;
		scanf("%u\n", &block_count);

		set<double> naomi;
		for (unsigned int block = 0; block < block_count; ++block)
		{
			double weight;
			scanf(" %lf", &weight);
			naomi.insert(weight);
		}

		set<double> ken;
		for (unsigned int block = 0; block < block_count; ++block)
		{
			double weight;
			scanf(" %lf", &weight);
			ken.insert(weight);
		}

		//Deceitful War
		unsigned int score = 0;
		set<double>::reverse_iterator naomi_it = naomi.rbegin();
		for (set<double>::reverse_iterator ken_it = ken.rbegin(); ken_it != ken.rend(); ++ken_it)
		{
			if (*naomi_it > *ken_it)
			{
				++score;
				++naomi_it;
			}
		}
		printf(" %d", score);

		//Regular War
		score = 0;
		for (set<double>::iterator it = naomi.begin(); it != naomi.end(); ++it)
		{
			//Ken picks
			set<double>::iterator ken_pick = upper_bound(ken.begin(), ken.end(), *it);
			if (ken_pick == ken.end())
			{
				++score;
				ken.erase(ken.begin());
			}
			else
			{
				ken.erase(ken_pick);
			}
		}
		printf(" %d\n", score);
	}
}
