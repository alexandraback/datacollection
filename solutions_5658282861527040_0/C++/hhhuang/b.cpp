#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void run() {
	int a, b, k;
	int c = 0;
	scanf("%d%d%d", &a, &b, &k);
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			if ((i & j) < k)
				c++;
	printf("%d\n", c);
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d: ", t);
        run();
    }
    return 0;
}

