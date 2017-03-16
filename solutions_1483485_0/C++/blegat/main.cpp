#include <stdio.h>
#include <assert.h>
//              a    b    c    d    e    f    g    h    i    j    k    l    m    n    o    p    q    r    s    t    u    v    w    x    y    z
char ci[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main (void) {
    int T;
    int scanned = scanf("%d", &T);
	assert(getchar() == '\n');
    for (int currentcase = 1; currentcase <= T; ++currentcase) {
		char c = 0;
		printf("Case #%d: ", currentcase);
		while ((c = getchar()) != '\n') {
			if (c == ' ') {
				putchar(' ');
			} else {
				putchar(ci[c - 'a']);
			}
		}
		putchar('\n');
    }
    return 0;
}
