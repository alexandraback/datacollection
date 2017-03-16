#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <math.h>

void itoa(int n, char *str) {
	char tmp[10];
	int i = 0, j;

	bzero(tmp, sizeof(tmp));
	while ( n != 0 ) {
		tmp[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	tmp[i] = '\0';
	for ( j = 0 ; j < i ; j++ )
		str[j] = tmp[i-1-j];
	str[j] = '\0';
}

int chk(int n) {
	char str[10];
	int len;
	int i;

	itoa(n, str);
	len = strlen(str);
	for ( i = 0 ; i < len / 2 ; i++ ) {
		if ( str[i] != str[len-1-i] ) return 0;
	}

	itoa(n*n, str);
	len = strlen(str);
	for ( i = 0 ; i < len / 2 ; i++ ) {
		if ( str[i] != str[len-1-i] ) return 0;
	}
	return 1;
}

int main() {
	int T, t;
	int A, B, sum;
	int i;
	int p[1001];

	bzero(p, sizeof(p));

	for ( i = 1 ; i <= 32 ; i++ ) {
		if ( chk(i) ) {
			p[i*i] = 1;
		}
	}

	scanf("%d", &T);
	for ( t = 1 ; t <= T ; t++ ) {
		scanf("%d %d", &A, &B);

		sum = 0;
		for ( i = A ; i <= B ; i++ ) {
			if ( p[i] ) sum++;
		}

		printf("Case #%d: %d\n", t, sum);
	}

	return 0;
}
