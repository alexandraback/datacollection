#include <bits/stdc++.h>

using namespace std;

int i, j, k, n, t, l, f, fake, mx = 0;
string s[20][2];

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.ans", "w", stdout);
	
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		cin >> n;
		for (j = 0; j < n; j++)
			cin >> s[j][0] >> s[j][1];
		
		mx = 0;
		for (j = 0; j < (1 << n); j++) {
			fake = 0;
			for (k = 0; k < n; k++) {
				if ((j & (1 << (n - k - 1))) == 0) {
// 					cout << j << " : " << k << endl;
					f = 0;
					for (l = 0; l < n; l++) {
// 						cout << k << " " << l << " " << s[k][0] << " " << s[l][0] << " " << (j & (1 << (n-l-1))) << endl;
						if (l != k && (j & (1 << (n-l-1))) != 0 && s[k][0].compare(s[l][0]) == 0) {
							f = 1;
							break;
						}
					}
					
					if (f == 1)
					for (l = 0; l < n; l++) {
						if (l != k && (j & (1 << (n-l-1))) != 0 && s[k][1].compare(s[l][1]) == 0) {
							f = 2;
							break;
						}
					}
// 					cout << f << endl;
					if (f == 2)
						fake++;
				}
			}
			if (fake > mx)
				mx = fake;
		}
		printf("Case #%d: %d", i + 1, mx);
		printf("\n");
	}
	
	return 0;
}