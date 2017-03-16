
#include "common.h"
void SovleB(char * input)
{
	INT ln;
	READ(ln), NL;
	for (INT i = 0; i < ln; i++)
	{
		INT x,y;
		READ(x), READ(y), NL;
		vector<vector<pair<bool, INT>>> f(x, vector<pair<bool, INT>>(y));
		for (INT j = 0; j < x; j++)
		{
			for (INT k = 0; k < y; k++)
			{
				f[j][k].first = false;
				READ(f[j][k].second);
			}
			NL;
		}
		for (INT j = 0; j < x; j++)
		{
			INT m = 0;
			for (INT k = 0; k < y; k++)
			{
				if (f[j][k].second > m) m = f[j][k].second;
			}
			for (INT k = 0; k < y; k++)
			{
				if (f[j][k].second == m)
					f[j][k].first = true;
			}
		}
		for (INT k = 0; k < y; k++)
		{
			INT m = 0;
			for (INT j = 0; j < x; j++)
			{
				if (f[j][k].second > m) m = f[j][k].second;
			}
			for (INT j = 0; j < x; j++)
			{
				if (f[j][k].second == m)
					f[j][k].first = true;
			}
		}
		bool solvable = true;
		for (INT j = 0; solvable && j < x; j++)
		{
			for (INT k = 0; solvable && k < y; k++)
			{
				if (!f[j][k].first)
					solvable = false;
			}
		}
		if (solvable)
		{
			fprintf(stdout, "Case #%I64d: YES\n", i + 1);
		}
		else
		{
			fprintf(stdout, "Case #%I64d: NO\n", i + 1);
		}
	}
}