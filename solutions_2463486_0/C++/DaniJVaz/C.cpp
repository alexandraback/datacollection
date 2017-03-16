#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

char buff[200];

bool isPalindrome(int n) {
	sprintf(buff, "%d", n);
	int s;
	for (s=0; buff[s] != '\0'; s++);

	for(int i=0; i<s/2; i++)
		if (buff[i] != buff[s-1-i])
			return false;
	return true;
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		long long sa, sb; 
		// Use %lld in unix
		scanf("%I64d %I64d", &sa, &sb);

		long long a = int(floor(sqrt(sa))), b = int(ceil(sqrt(sb)));
		while (a*a < sa) ++a;
		while (b*b > sb) --b;


		int c = 0;
		for (long long i=a; i<=b; i++) {
			if (isPalindrome(i) and isPalindrome(i*i))
				++c;
		}

		printf("Case #%d: %d\n", iC, c);
	}
	return 0;
}
