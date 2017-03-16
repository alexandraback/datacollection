#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[111];

int main() {
	int T;
	int K,C,S;
	scanf("%d",&T);
	for (int tt = 1 ;tt <= T;tt++) {
		printf("Case #%d: ",tt);

		scanf("%s",s);
		int N = strlen(s);

		char sign = s[0];
		int res = 0;
		for (int i=1;i<N;i++) {
			if (s[i] != sign) {
				res++;
				sign = s[i];
			}
		}
		if (sign != '+')
			res++;
		cout<<res<<endl;

	}

}
