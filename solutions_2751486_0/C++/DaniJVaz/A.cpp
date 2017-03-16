#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

typedef long long ll;

using namespace std;

char word[20000000];

bool vowel(char a) {
	return a=='a' or a=='e' or a=='i' or a=='o' or a=='u';
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n, lastpos, c, l;
		ll before, after, total = 0;

		scanf("%s %d", word, &n);
		l = strlen(word);

		lastpos = -1;
		c = 0;
		for (int i=0; i<l; i++) {
			if (vowel(word[i]))
				c = 0;
			else
				++c;

			if (c >= n) {
				i = i-n+1;
				before = i - lastpos;
				lastpos = i;

				i = i+n-1;
				after = l - i;
				total += before * after;
			}
		}


		printf("Case #%d: %I64d\n", iC, total);
	}
	return 0;
}