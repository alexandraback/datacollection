#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int N, Num;
char S[MAXN];

int main() {
	//freopen("B.in", "r", stdin), freopen("B.out", "w", stdout);
	
	int Test;
	scanf("%d", &Test);
	for (int i = 1; i <= Test; i ++) {
		scanf("%s", S + 1);
		int Len = strlen(S + 1);
		S[0] = '.', Num = 0;
		for (int j = 1; j <= Len; j ++) 
			if (S[j] != S[Num]) S[++ Num] = S[j];
		if (S[Num] == '+') Num --;
		printf("Case #%d: %d\n", i, Num);
	}
}