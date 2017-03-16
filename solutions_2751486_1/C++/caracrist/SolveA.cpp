#include "common.h"

void SovleA(char * input)
{
	fprintf(stderr, __FUNCTION__ " started...\n");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		string s;
		Int N;
		READ(s); READ(N); NL;
		Int res = 0;
		if (N > s.size()) {
			fprintf(stdout, "Case #%I64d: 0\n", i + 1);
			continue;
		}
		Int totalCount = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'a' ||
				s[j] == 'e' ||
				s[j] == 'i' ||
				s[j] == 'o' ||
				s[j] == 'u')
			{
				s[j] = '0';
			}
			else 
			{
				totalCount++;
				s[j] = '1';
			}
		}
		Int leftCount = std::count(&s[0], (&s[0]) + N, '1');
		Int rightCount = totalCount - leftCount;
		Int ll = 0;
		Int pl = 0;

		for (int k = 0; k <= s.size() - N && (leftCount + rightCount >= N);  k++)
		{
			if (leftCount == N)
			{
				//Int len = 1;
				//Int prevK = k;
				//for (Int j = k + N; j < s.size() && s[j] == '1'; j++)
				//{
				//	len++;
				//}
				Int leftSide = (ll + 1) - pl;
				Int rightSide = (s.size() - N - k + 1);
				res += (leftSide * rightSide);
				ll = pl = k + 1;
			} else {
				ll = k + 1;
			}
			if (s[k] == '1')
				leftCount--;
			if (k < s.size() - N && s[k + N] == '1') {
				leftCount++;
				rightCount--;
			}		
		}
		//fprintf(stderr, "Case #%I64d: %s\n", i + 1, s.c_str());
		fprintf(stdout, "Case #%I64d: %I64d\n", i + 1, res);
	}
	fprintf(stderr, "\n" __FUNCTION__ " ended.\n");
}