#include <stdio.h>

long long int solve(long long unsigned int n) {
    if (n == 0) return 0;

    int digits[10];
    for (int i = 0; i < 10; ++i) {
	digits[i] = 0;
    }

    long long int m;
    int i = 1;
    while (1) {
	m = n*i;

	while (m>0) {
	    ++digits[m%10];
	    m/=10;
	}

	int ok = 1;
	for (int i = 0; i < 10; ++i) {
	    if (digits[i] == 0) {
		ok = 0;
		break;
	    }
	}

	if (ok) {
	    return n*i;
	}

	++i;
    } 

    return 0;
}

int main()
{
    int T;
    int tmp;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
	scanf("%d", &tmp);
	long long int ans = solve(tmp);
	if (ans)
	    printf("Case #%d: %d\n", i+1, ans);
	else
	    printf("Case #%d: INSOMNIA\n", i+1);
    }
}
