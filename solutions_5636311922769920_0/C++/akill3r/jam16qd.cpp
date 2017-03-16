#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
    	int k, c, s;
    	scanf("%d%d%d", &k, &c, &s);
    	printf("Case #%d: ", i);
    	for (int j = 1; j <= s; ++j) printf("%d ", j);
    	printf("\n");
    }
	return 0;
}