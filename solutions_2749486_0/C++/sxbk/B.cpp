#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int TT;
	scanf("%d", &TT);

	for (int _ = 1;_ <= TT;_ ++)
	{
		printf("Case #%d: ", _);
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > 0) {
			for (int i = 1; i <= x; i++)
				printf("WE");
		} else {
			for (int i = 1; i <= -x; i++)
				printf("EW");
		}
		if (y > 0) {
			for (int i = 1; i <= y; i++)
				printf("SN");
		} else {
			for (int i = 1; i <= -y; i++)
				printf("NS");
		}
		printf("\n");
	}

	return 0;
}
