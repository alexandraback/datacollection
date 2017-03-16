#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

void itoa(long long int n, char *str) {
	char tmp[20];
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

int chk(long long int n) {
	char str[20];
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
	long long int A, B, sum;
	int total;
	long long int i, j;
	vector<long long int> table (100);

	j = 0;
	for ( i = 1 ; i <= 10000000 ; i++ ) {
		if ( chk(i) ) {
			table[j] = i * i;
			j++;
		}
	}
	total = j;

	scanf("%d", &T);
	for ( t = 1 ; t <= T ; t++ ) {
		scanf("%lld %lld", &A, &B);

		sum = 0;
		for ( i = 0 ; i < total ; i++ ) {
			if ( table[i] < A ) continue;
			if ( table[i] > B ) break;
			sum++;
		}

		printf("Case #%d: %lld\n", t, sum);
	}

	return 0;
}
