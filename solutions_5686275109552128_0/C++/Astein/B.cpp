#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	if (argc == 3)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int D;
		scanf("%d", &D);
		vector<int> P(D);
		int ret = 1;
		int maxp = 0;
		for (int i = 0; i < D; ++i)
		{
			scanf("%d", &P[i]);
			ret += P[i] - 1;
			if (maxp < P[i]) maxp = P[i];
		}
		// base ret -> all pencake's height = 1
		for (int minc = 2; minc <= maxp; ++minc)
		{
			int cur = minc;
			for (int i = 0; i < D; ++i)
			{
				if (P[i] > minc) cur += (P[i] - 1) / minc;
			}
			if (ret > cur) ret = cur;
		}
		printf("Case #%d: %d\n", cn, ret);
	}
	return 0;
}
