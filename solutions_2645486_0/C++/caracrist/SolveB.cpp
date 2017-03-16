#include "common.h"

Int MaxGain(Int i, vector<Int> &costs, Int R, Int E, Int maxE)
{
	Int sum = 0;
	for (Int i = 0; i < costs.size(); i++)
	{
		if (i == costs.size() - 1) {
			sum += (E * costs[i]);
			continue;
		}
		if (costs[i] > costs[i+1]) {
			sum += (E * costs[i]);
			E = R;
			continue;
		}
		Int freeE = R - (maxE - E);
		if (freeE > 0) {
			sum += (freeE * costs[i]);
			E = maxE;
			continue;
		}
		E = E + R;
	}
	return sum;
}

void SovleB(char * input)
{	
	fprintf(stderr, __FUNCTION__ " started...\n");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		Int E,R,N;
		vector<Int> costs;
		READ(E), READ(R), READ(N), NL;
		for(Int j = 0; j < N; j++)
		{
			Int A;
			READ(A);
			costs.push_back(A);
		}
		NL;
		Int maxGain = MaxGain(0, costs, R, E, E);
		fprintf(stdout, "Case #%I64d: %I64d\n", i + 1, maxGain);
	}
	fprintf(stderr, "\n" __FUNCTION__ " ended.\n");
}