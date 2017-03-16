#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	// freopen("test.in","r",stdin);
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);

	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++){
		int x[110];
		int a, n;
		scanf("%d%d", &a, &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &x[i]);


		if(a == 1){
			printf("Case #%d: %d\n", ti, n);
			continue;
		}

		sort(x,x+n);
		int mn = n;
		int c = 0;
		for(int i = 0; i < n; i++){
			while(a <= x[i]){
				a += a-1;
				c++;
			}
			a += x[i];
			if(mn > c+n-i-1){
				mn = c+n-i-1;
			}
		}

		printf("Case #%d: %d\n", ti, mn);
	}
	return 0;
}