#include "stdafx.h"

void SovleD(char * input)
{
	TRACE("started...");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		Int N; 
		READ(N);NL;
		vector<Float> Naomi(N);
		vector<Float> Ken(N);
		for (Int j = 0; j < N; j++)
		{
			READ(Naomi[j]);
		}
		NL;
		for (Int j = 0; j < N; j++)
		{
			READ(Ken[j]);
		}
		NL;
		sort(Naomi.begin(), Naomi.end());
		sort(Ken.begin(), Ken.end());
		Int p = 0;
		for (Int j = N - 1; j >= 0; j--)
		{
			if (Naomi[j] > Ken[j + p])
				p++;
		}
		Int p2 = 0;
		for (Int j = 0; j < N; j++)
		{
			if (Naomi[N - p2 - 1] > Ken[N - j - 1])
			{
				p2++;
			}
			else if (Naomi[j-p2] >  Ken[N - j - 1])
			{
				p2 += N - j;
				break;
			}
		}
		PRINT("Case #%I64d: %I64d %I64d\n", i + 1, p2, p);
	}
	TRACE("ended.");
}