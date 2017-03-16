#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	freopen("large.in","r",stdin);
	freopen("large.out","w",stdout);
	int T,cases;
	scanf("%d ",&T);
	for (cases=1;cases<=T;cases++){
		char s[120];
		scanf("%s ", s);
		int num = 0;
		for (int i=0;i<strlen(s)-1;i++)
			if (s[i] != s[i+1]) {
				num ++;
			}

		if (s[strlen(s)-1] == '-') num++;

		printf("Case #%d: %d\n",cases, num);
	}
}