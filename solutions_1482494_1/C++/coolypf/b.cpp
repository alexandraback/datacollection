#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Level
{
	int a, b;
	bool pass1, pass2;
	bool operator < (const Level &ano) const { return (b > ano.b); }
} lv[10000];

int main()
{
	int ccc; 
	scanf("%d", &ccc);
	for (int cc = 1; cc <= ccc; ++cc)
	{
		memset(lv, 0, sizeof(lv));
		
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &lv[i].a, &lv[i].b);
			
		sort(lv, lv + n);
		
		int pstar = 0, star = 0, trial = 0;
		while (1)
		{
			for (int i = 0; i < n; ++i)
			{
				if (lv[i].pass2 || lv[i].b > star) continue;
				lv[i].pass2 = true;
				if (lv[i].pass1) star += 1;
				else star += 2;
				trial++;
				break;
			}
			if (star > pstar)
			{
				pstar = star;
				continue;
			}
			
			for (int i = 0; i < n; ++i)
			{
				if (lv[i].pass2 || lv[i].pass1 || lv[i].a > star) continue;
				lv[i].pass1 = true;
				star += 1;
				trial++;
				break;
			}
			if (star == pstar) break;
		}
		if (star == 2 * n) printf("Case #%d: %d\n", cc, trial);
		else printf("Case #%d: Too Bad\n", cc);
	}
	return 0;
}