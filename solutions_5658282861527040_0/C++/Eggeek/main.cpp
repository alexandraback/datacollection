#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a,b,k;

void work() {
	scanf("%d%d%d",&a,&b,&k);
	int ans = 0;
	for (int i=0; i<a; i++ ) {
		for (int j=0; j<b; j++ ) {
			if ((i&j) < k) ans++;
		}
	}
	printf("%d\n",ans);
}

int main() {
	int cas;
	freopen("test.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&cas);
	for (int i=1; i<=cas; i++ ) {
		printf("Case #%d: ",i);
		work();
	}
	return 0;
}
