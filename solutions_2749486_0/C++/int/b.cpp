#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t ++){
		int x, y;
		scanf("%d%d", &x, &y);
		printf("Case #%d: ", t + 1);
		if (x > 0){
			for (int i = 0; i < x; i ++)
				printf("WE");
		}
		if (x < 0){
			for (int i = 0; i < -x; i ++)
				printf("EW");
		}
		if (y > 0){
			for (int i = 0; i < y; i ++)
				printf("SN");
		}
		if (y < 0){
			for (int i = 0; i < -y; i ++)
				printf("NS");
		}
		puts("");
	}
	return 0;
}
