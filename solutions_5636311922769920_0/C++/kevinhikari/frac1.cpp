#include <cstdio>
#include <iostream>

using namespace std;
int t,k,c,s;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &k, &c, &s);
		printf("Case #%d:",i+1);
		for (int j = 0; j < k; j++) {
			printf(" %d",j+1);
		}
		printf("\n");
	}
}