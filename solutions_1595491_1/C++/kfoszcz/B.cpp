#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int z;
	scanf("%d", &z);
	for (int nr = 1; nr <= z; nr++)
	{
		int googlers, surprising, p;
		scanf("%d%d%d", &googlers, &surprising, &p);
		int min_ns; // minimal not surprising score
		int min_s;  // minimal surprising score
		if (p == 0)
		{
			min_ns = min_s = 0;
		}
		else if (p == 1)
		{
			min_ns = min_s = 1;
		}
		else
		{
			min_ns = 3*p - 2;
			min_s = 3*p - 4;
		}
		
		int answer = 0;
		while (googlers--)
		{
			int score;
			scanf("%d", &score);
			if (score >= min_ns)
				answer++;
			else if (score >= min_s && surprising > 0)
			{
				answer++;
				surprising--;
			}
		}
		printf("Case #%d: %d\n", nr, answer);
	}
	return 0;
}
