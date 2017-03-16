#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
using namespace std;
int TC, T;
char S[105];
int main() {
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.txt", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.txt", "w", stdout);
	scanf("%d", &TC);
	while (T < TC) {
		scanf("%s", S);
		int last = 0, count = 0;
		for (int i = 0; S[i]; i++) {
			if (S[i] == '+' && last != 1) {
				last = 1;
				count++;
			}
			else if (S[i] == '-' && last != -1) {
				last = -1;
				count++;
			}
		}
		if (last == 1) count--;
		printf("Case #%d: %d\n", ++T, count);
	}
}
