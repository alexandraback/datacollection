#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("C-small-1-attempt2.in", "r", stdin);
	freopen("C-small-1-attempt2.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int n;
		scanf("%d", &n);
		vector<int> d, h, m;
		for (int i = 0; i < n; ++i)
		{
			int dd, hh, mm;
			scanf("%d%d%d", &dd, &mm, &hh);
			for (int j = 0; j < mm; ++j)
			{
				d.push_back(dd);
				m.push_back(mm);
				h.push_back(hh + j);
			}
		}
		
		printf("Case #%d: ", cn);
		if (d.size() == 1)
		{
			printf("0\n");
		}
		else
		{
			double a00 = ((360 - d[0]) % 360) * h[0] / 360.0;
			double a01 = a00 + h[0];
			double a10 = ((360 - d[1]) % 360) * h[1] / 360.0;
			double a11 = a10 + h[1];

			if (a01 < a10 || a11 < a00) { printf("1\n"); }
			else printf("0\n");
			
		}
	}
	return 0;
}