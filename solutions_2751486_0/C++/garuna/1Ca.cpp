#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
	int t, n, l, i, count, c, j, k, f, m, f1;
	scanf("%d", &t);

	for(i = 1; i <= t; i++) {
		string s;
		cin >> s;
		scanf("%d", &n);
		count = 0;

		for(l = s.size(); l >= n; l--) {
			for(j = 0; j + l <= s.size(); j++) {
				c = 0;
				f = 0;
				for(k = j; k+n <= j+l ; k++) {
					f1 = 0;
					for(m = k; m < k + n; m++) {
						if(s[m] == 'a' || s[m] == 'e' || s[m] == 'i' || s[m] == 'o' || s[m] == 'u')  {
							f1 = 1;
							break;
						}
					}

					if(f1 == 0) {
						f = 1;
						break;
					}
				}
				
				if(f == 1) {
					count++;
				}
			}
		}

		printf("Case #%d: %d\n", i, count);
	}

	return 0;
}
