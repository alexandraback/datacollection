#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		int N,S,p,ans = 0;
		scanf("%d%d%d",&N,&S,&p);
		for(int i=0;i<N;++i) {
			int a,b;
			scanf("%d",&a);
			if(a%3 == 0) b = a/3;
			else b = a/3 + 1;
			if(b >= p) ++ans;
			else if((a >= 2 && a <= 28) && S && b == p-1 && (a%3 == 0 || a%3 == 2)) {
				++ans;
				--S;
			}
		}
		printf("Case #%d: %d\n",cn,ans);
	}
}
