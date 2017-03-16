#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define si() (scanf("%d", &TEMP), TEMP);

using namespace std;

int TEMP;

int table[]{
	3, 2, 5, 2, 7, 2, 3, 2, 11
};

void solve2() {

}


void solve1() {
	int cnt = 0;
	printf("Case #1:\n");
	for (int i = -1; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			for (int k = j + 1; k < 7; k++) {
				printf("1");
				for (int l = 0; l < 7; l++) {
					if (i == l || l == k || l == j) {
						printf("11");
					}
					else {
						printf("00");
					}
				}
				printf("1 3 2 5 2 7 2 3 2 11\n");
				cnt++;
				if (cnt == 50) return;
			}
		}
	}
	printf("%d\n", cnt);
}

int main(void) {
	freopen("output.txt", "w", stdout);/*
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N = si();
	for (int i = 0; i < N; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}*/
	solve1();
}