#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define intl long long
using namespace std;

intl k,c,s;

int main() {
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int t,T; 
	for (scanf("%d",&T),t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		cin >> k >> c >> s;
		for (intl i = 1LL; i <= k; i++) {
			intl p = i;
			for (int j = 1LL; j < c; j++) {
				p = (p - 1LL) * k + i;
			}
			cout << p << " ";
		}
		putchar('\n');
	}
	return 0;
}	
