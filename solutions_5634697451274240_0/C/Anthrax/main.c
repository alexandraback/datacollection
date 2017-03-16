#include <stdio.h>

int solve(char *pc) {
    int inv = 0;

    int count = 0;
    while(*pc) ++pc;
    --pc;
    while(*pc) {
	//printf("%c == %c : %d\n", *pc, '+'+2*inv, *pc == '+'+2*inv);
	if (*pc == '-'-2*inv) {
	    inv = 1-inv;
	    count++;
	}
	--pc;
    }

    return count;
}

int main()
{
    int T;
    char tmp[101];
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
	scanf("%s", &tmp);
	//printf("%s\n", tmp);
	int ans = solve(tmp);
	printf("Case #%d: %d\n", i+1, ans);
    }
}
