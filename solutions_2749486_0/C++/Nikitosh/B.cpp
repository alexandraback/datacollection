#include<cstdio>
#include<algorithm>

using namespace std;

int T, x, y;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int g = 0; g < T; g++)
	{
		printf("Case #%d: ", g + 1);
		scanf("%d%d", &x, &y);
		if (x >= 0)
			for (int i = 0; i < x; i++)
				printf("WE");
   		if (x < 0)
			for (int i = 0; i < abs(x); i++)
				printf("EW");
		if (y >= 0)
			for (int i = 0; i < y; i++)
				printf("SN");
   		if (y < 0)
			for (int i = 0; i < abs(y); i++)
				printf("NS");
		puts("");
	}
	return 0;
}
