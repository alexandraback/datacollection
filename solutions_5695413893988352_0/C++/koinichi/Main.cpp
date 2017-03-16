#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool fit(char *s, int n, int l, int t)
{
	for (int i=0; i<l; i++) {
		if (s[i] != ((n/t)%10) + '0' && s[i] != '?') {
			return false;
		}
		t /= 10;
	}
	return true;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);


	int _n;
	scanf("%d", &_n);

	for (int _t=1; _t<=_n; _t++) {
		char a[5]={0}, b[5]={0};
		int l, t = 1;

	
		scanf("%s %s", a,b);
		for (l=0; a[l]; l++) { t *= 10; }
		int diff=t, co = t,ja = t;
		for (int i=0; i<t; i++) {
			for (int j=0; j<t; j++) {
				if (fit(a, i, l, t/10) && fit(b, j, l, t/10)) {
					if (abs(i-j) < diff) {
						diff = abs(i-j);
						co = i, ja = j;
					}
					else if (abs(i-j) == diff && i < co) {
						co = i, ja = j;
					}
					else if (abs(i-j) == diff && i == co && j <= ja) {
						co = i, ja = j;
					}
				}
			}
		}
		printf("Case #%d: %0*d %0*d\n", _t, l, co, l, ja);
	}
}
