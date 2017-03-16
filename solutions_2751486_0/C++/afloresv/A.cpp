#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, lenW;
char word[110];
int mem[110][110];

bool isCons (char c) {
	return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
}

int dp (int ind, int llevo) {
	if (mem[ind][llevo]!=-1) {
		return mem[ind][llevo];
	} else if (llevo==n) {
		return mem[ind][llevo] = lenW-ind+1;
	} else if (ind==lenW) {
		return mem[ind][llevo] = 0;
	} else if (isCons(word[ind])) {
		return mem[ind][llevo] = dp(ind+1, llevo+1);
	} else {
		return mem[ind][llevo] = dp(ind+1, 0);
	}
}

int main() {
	int T, t, res;
	scanf("%d\n", &T);
	for (int t=1 ; t<=T ; t++) {
		scanf("%s %d\n", word, &n);
		lenW = strlen(word);
		res = 0;
		memset(mem, -1, sizeof(mem));
		for (int i=0 ; i<lenW ; i++)
			res += dp(i,0);
		printf("Case #%d: %d\n", t, res);
	}
	return 0;
}
