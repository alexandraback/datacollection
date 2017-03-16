// CodeJam 2014
// Autor: Benjamín de la Fuente Ranea

#include "BigIntegerLibrary.hh"

#include <stdarg.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

//#define FILE_INPUT	"D-small-attempt1"
#define FILE_INPUT	"D-large"

double chooseBetterLie(const vector<double>& blocksKen)
{
	const double greaterOne = blocksKen.back();
	const double next = *++blocksKen.rbegin();
	double selection = (greaterOne + next) / 2;
	
	// check doesn't exist
	auto iter = lower_bound(blocksKen.begin(), blocksKen.end(), selection);
	while (fabs(*iter - selection) < 0.00001)
	{
		selection = (selection + next) / 2;
		iter = lower_bound(blocksKen.begin(), blocksKen.end(), selection);
	}

	return selection;
}

// blocks are sorted from lesser to greater
double thinkToldNaomi(vector<double>& blocksNaomi, const vector<double>& blocksKen)
{
	const double minNaomi = blocksNaomi[0];
	if (minNaomi < blocksKen[0])
	{
		blocksNaomi.erase(blocksNaomi.begin());
		if (blocksKen.size() <= 1)
			return minNaomi;
		else
			return chooseBetterLie(blocksKen);
	}
	else
	{
		const double greaterOne = blocksNaomi.back();
		//blocksNaomi.pop_back();
		blocksNaomi.erase(blocksNaomi.begin());
		if (greaterOne > blocksKen.back())
			return greaterOne;
		else
			return chooseBetterLie(blocksKen);
	}
}

// blocks are sorted from lesser to greater
double chosenKen(double ChosenNaomi, vector<double>& blocks)
{
	for (auto iter = blocks.begin(); iter != blocks.end(); ++iter)
	{
		if (*iter > ChosenNaomi)
		{
			const double selection = *iter;
			blocks.erase(iter);
			return selection;
		}
	}

	const double selection = blocks[0];
	blocks.erase(blocks.begin());
	return selection;
}

void main()
{
	freopen(FILE_INPUT".in", "r", stdin);
	freopen(FILE_INPUT".out", "w", stdout);

	unsigned numCases;
	scanf("%d\n", &numCases);
	for (unsigned j = 1; j <= numCases; ++j)
	{
		unsigned numBlocks;
		scanf("%d\n", &numBlocks);
		vector<double> blocksNaomi(numBlocks);
		for (unsigned i = 0; i < numBlocks; ++i)
			scanf("%lf", &blocksNaomi[i]);

		vector<double> blocksKen(numBlocks);
		for (unsigned i = 0; i < numBlocks; ++i)
			scanf("%lf", &blocksKen[i]);

		sort(blocksNaomi.begin(), blocksNaomi.end());
		sort(blocksKen.begin(), blocksKen.end());
		vector<double> blocksNaomi2 = blocksNaomi;
		vector<double> blocksKen2 = blocksKen;

		unsigned deceitfulWar = 0, normalWar = 0;
		for (unsigned i = 0; i < numBlocks; ++i)
		{
			const double ChosenNaomi = blocksNaomi[0];
			blocksNaomi.erase(blocksNaomi.begin());
			const double ChosenKen1 = chosenKen(ChosenNaomi, blocksKen);
			if (ChosenNaomi > ChosenKen1)
				++normalWar;

			const double ToldNaomi = thinkToldNaomi(blocksNaomi2, blocksKen2);
			const double ChosenKen2 = chosenKen(ToldNaomi, blocksKen2);
			if (ToldNaomi > ChosenKen2)
				++deceitfulWar;
		}

		printf("Case #%d: %d %d\n", j, deceitfulWar, normalWar);
	}
}
