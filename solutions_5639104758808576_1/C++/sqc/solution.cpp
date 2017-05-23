#include <stdlib.h>
#include <stdio.h>

int main() {
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int t; 
	scanf("%d", &t);
	int res = 0;
	int standupNum = 0;
	char ch;
	int curNum;
	int pNum; 
	for (int j = 1; j <= t; j++) {
		res = 0;
		standupNum = 0;
		scanf("%d ", &pNum);
		for (int i = 0; i <= pNum; i++) {
			 scanf("%c", &ch);
			 curNum = ch - '0';
			 if (standupNum >= i) {
				standupNum += curNum;
			} else {
				res += i - standupNum;
				standupNum += i - standupNum + curNum;
			}	
		}
		printf("Case #%d: %d\n", j, res);
	}
	return 0;
}
