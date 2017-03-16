#include <stdio.h>

int f(char *w, int s, int L, int n) {
    int i, j = 0;
    for (i = s; i < L; i++)  {
	if (w[i] != 'a' && w[i] != 'e' && w[i] != 'i' && w[i] != 'o' && w[i] != 'u')
	    j++;
	else
	    j = 0;

	if (j == n)
	    return i;
    }
    return -1;
}

int main() {  
    int T, n, t, i, L, x, c;
    char w[1000001];
    
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
	scanf("%s %i", w, &n);

	L = strlen(w);
	c = 0;
	x = -1;
	for (i = 0; i < L - n + 1; i++) {
	    if (x < i + n)
		x = f(w, i, L, n);

	    if (x == -1)
		break;

	    c += L - x;
	} 

	printf("Case #%d: %d\n", t + 1, c);
    }

    return 0;
}
