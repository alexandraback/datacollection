#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int cal13[11][11] = { 0 }, cal23[11][11] = { 0 }, cal12[11][11] = {0};
int result[11][11][11] = { 0 };
int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T,J,P,S,k;
	int count = 0;
	scanf("%d", &T);
	int i = 0;
	while (T--)
	{
		i++;
		count = 0;
		memset(cal12, 0, sizeof(int) * 11 * 11);
		memset(cal13, 0, sizeof(int) * 11 * 11);
		memset(cal23, 0, sizeof(int) * 11 * 11);
		memset(result, 0, sizeof(int) * 11*11 * 11);
		scanf("%d%d%d%d", &J, &P, &S, &k);
		printf("Case #%d: ", i);
		for (int j = 1; j <= J; j++)
			for (int p = 1; p <= P; p++)
				for (int s = 1; s <= S; s++)
				{
					if (cal13[j][s] < k && cal12[j][p] < k && cal23[p][s] < k )
					{
						result[j][p][s] = 1;
						count++;
						cal13[j][s]++; cal12[j][p]++; cal23[p][s]++;
					}
				}
		printf("%d\n", count);
			for (int j = 1; j <= J; j++)
				for (int p = 1; p <= P; p++)
					for (int s = 1; s <= S; s++)
					{
						if (result[j][p][s] != 0)
							printf("%d %d %d\n", j, p, s);
					}
	}
	return 0;
}