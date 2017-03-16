#include <bits/stdc++.h>

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

const int N = 16, J = 50;
const int OUT[9] = {7, 13, 21, 31, 43, 57, 73, 91, 111};

int main()
{
	printf("Case #1:\n");
	int kant = 0;

	for (int a = 0; a < N - 2; a += 3)
		for(int b = a + 3; b < N - 2; b += 3)
			for (int c = 1; c < N - 2; c += 3)
				for (int d = c + 3; d < N - 2; d += 3){
					if (kant >= J)
						continue;
					printf("1");
					REP(i, N - 2){
						if (i == a || i == b || i == c || i == d){
							printf("1");
						}
						else
							printf("0");
					}
					printf("1 ");
					REP(i, 9)
						printf("%d%c", OUT[i], " \n"[i == 8]);
					kant++;
				}
			
	return 0;
}

