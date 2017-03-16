#include <cstdio>

using namespace std;

int main(void)
{
	int T, r, t, caseId = 1, numDraw = 0, areaPi;

	scanf("%d", &T);

	while(caseId <= T)
	{
		scanf("%d %d", &r, &t);

		numDraw = 0;
		
		areaPi = 2 * r  + 1;
		while(t >= areaPi)
		{
			numDraw++;
			t -= areaPi;
			areaPi += 4;
		}

		printf("Case #%d: %d\n", caseId, numDraw);
		caseId++;
	}
	return 0;
}
