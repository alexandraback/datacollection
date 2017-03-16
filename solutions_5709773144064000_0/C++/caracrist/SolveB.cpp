#include "stdafx.h"

void SovleB(char * input)
{	
	TRACE("started...");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		Float C,F,X;
		READ(C);READ(F);READ(X);NL;
		Float g = C/F;
		Float time = 0;
		Float inc = 2;
		while((X / (inc + F) + C / inc) < (X / inc))
		{
			time += C / inc;
			inc += F;
		}
		time += X / inc;
		PRINT("Case #%I64d: %lf\n", i + 1, time);
	}
	TRACE("ended.");
}