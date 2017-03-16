#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int t,k,c,s;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d",&k);
		scanf("%d",&c);
		scanf("%d",&s);
		printf("Case #%d: ",i);
		for(int j=1;j<=k;j++) {
			printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}