#include <iostream>
#include <cstdio>
using namespace std;

int cnt[256] = {0};

void dec(char * s, int num) {
	for (char * i = s;*i;i++)
		cnt[*i] -= num;
}

void A() {
	//freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t;
	char s[2345];
	scanf("%d", &t);
	for (int cas = 1;cas <= t;cas++) {
		for (char i = 'A';i <= 'Z';i++)
			cnt[i] = 0;
		int dig[10] = {0};
		scanf(" %s", s);
		for (char * i = s;*i;i++)
			cnt[*i]++;
		dig[0] = cnt['Z'];
		dec("ZERO", dig[0]);
		dig[2] = cnt['W'];
		dec("TWO", dig[2]);
		dig[4] = cnt['U'];
		dec("FOUR", dig[4]);
		dig[1] = cnt['O'];
		dec("ONE", dig[1]);
		dig[3] = cnt['R'];
		dec("THREE", dig[3]);
		dig[5] = cnt['F'];
		dec("FIVE", dig[5]);
		dig[7] = cnt['V'];
		dec("SEVEN", dig[7]);
		dig[6] = cnt['X'];
		dec("SIX", dig[6]);
		dig[8] = cnt['G'];
		dec("EIGHT", dig[8]);
		dig[9] = cnt['E'];
		printf("Case #%d: ", cas);
		for (int i = 0;i < 10;i++)
			if (dig[i])
				for (int j = 0;j < dig[i];j++)
					printf("%d", i);
		printf("\n");
	}
}

int main() {
	A();
}