/*       Jason Lau  -  Lawnmower       */
#include <stdio.h>
#include <string.h>

#define MAXN	50

void printStatus(int tcase);

int main(void) {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		printStatus(i);
	return 0;
}

typedef long long ll;

ll expandToOddDigit(int a);
ll expandToEvenDigit(int a);
int isPalindrome(ll a);

void printStatus(int tcase) {
	int a, b, cnt = 0, i;
	scanf("%d%d", &a, &b);
	for (i = 1; ; i++) {
		ll n = expandToOddDigit(i);
		ll m = expandToEvenDigit(i);
		n *= n; m *= m;
		if (n >= a && n <= b && isPalindrome(n))
			cnt++;
		if (m >= a && m <= b && isPalindrome(m))
			cnt++;
		if (n > b && m > b) break;
	}
	printf("Case #%d: %d\n", tcase, cnt);
}

ll expandToOddDigit(int a) {
	char tmp[MAXN];
	int i, len, j;
	ll ans = 0;
	sprintf(tmp, "%d", a);
	len = strlen(tmp);
	for (i = len - 2, j = len; i >= 0; i--, j++)
		tmp[j] = tmp[i];
	tmp[j] = '\0';
	sscanf(tmp, "%lld", &ans);
	return ans;
}

ll expandToEvenDigit(int a) {
	char tmp[MAXN];
	int i, len, j;
	ll ans = 0;
	sprintf(tmp, "%d", a);
	len = strlen(tmp);
	for (i = len - 1, j = len; i >= 0; i--, j++)
		tmp[j] = tmp[i];
	tmp[j] = '\0';
	sscanf(tmp, "%lld", &ans);
	return ans;
}

int isPalindrome(ll a) {
	char tmp[MAXN];
	int i, len;
	sprintf(tmp, "%lld", a);
	len = strlen(tmp);
	for (i = len / 2; i < len; i++)
		if (tmp[i] != tmp[len - i - 1]) return 0;
	return 1;
}
