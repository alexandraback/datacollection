#include <cstdio>
#include <algorithm>

#define MAX_N 1000005

using namespace std;

char buff[100];

int lg10(int x) {
	sprintf(buff, "%d", x);
	return strlen(buff);
}

int pw10(int x) {
	if (x == 0) return 1;
	else return 10 * pw10(x - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int rayge = 1; rayge <= t; rayge++) {
	
		int a, b, cnt = 0;
		scanf("%d %d", &a, &b);
		
		int numdig = lg10(a);
		
		for (int i = a; i <= b; i++) {
			int used[numdig];
			for (int j = 0; j < numdig; j++) used[j] = -1;
			int tmp;
			for (int rots = 0; rots < numdig; rots++) {
				tmp = (i / pw10(rots)) + (i % pw10(rots)) * pw10(numdig - rots);
				if (i < tmp && a <= tmp && tmp <= b && lg10(tmp) == numdig) {
					bool nxt = false;
					for (int q = 0; q < rots; q++) if (used[q] == tmp) nxt = true;
					if (nxt) continue;
					used[rots] = tmp;
					cnt++;
				}
				//printf("%d %d\n", i, tmp);
			}
			
		}
		
		printf("Case #%d: %d\n",rayge,  cnt);
	}
}