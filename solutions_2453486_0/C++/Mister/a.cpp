#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
char B[5][5];
char winner;
void test(char a,char b,char c,char d) {
	if(a == 'T') a = b;
	else if(b == 'T') b = a;
	else if(c == 'T') c = a;
	else if(d == 'T') d = a;
	if(a != '.' && a == b && b == c && c == d) winner = a;
}
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		scanf("%s%s%s%s",B[0],B[1],B[2],B[3]);
		winner = '.';
		// horizontal
		for(int i=0;i<4;++i) {
			test(B[i][0],B[i][1],B[i][2],B[i][3]);
			test(B[0][i],B[1][i],B[2][i],B[3][i]);
		}
		test(B[0][0],B[1][1],B[2][2],B[3][3]);
		test(B[0][3],B[1][2],B[2][1],B[3][0]);
		printf("Case #%d: ",cn);
		if(winner != '.') {
			printf("%c won\n",winner);
		}
		else {
			bool done = 1;
			for(int i=0;i<4;++i)
				for(int j=0;j<4;++j)
					if(B[i][j] == '.') done = 0;
			if(!done) printf("Game has not completed\n");
			else printf("Draw\n");
		}
	}
}
