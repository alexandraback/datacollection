#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int ans,n,ori,cur,t,add;
int a[200];

int main(){
	
   	freopen("a.in", "r", stdin);
  	freopen("a.out", "w", stdout);
	
	scanf("%d", &t);
	for (int z = 1; z <= t; z++){
		scanf("%d%d", &ori, &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		ans = 10000;
		if (ori == 1){
			ans = n;
		}
		else
		for (int i = 1; i <= n + 1; i++){
			add = 0;
			cur = ori;
			for (int j = 1; j < i; j++){
				while (cur <= a[j]){
					add++;
					cur = cur * 2 - 1;
				}
				cur = cur + a[j];
			}
			ans = min(ans, add + n + 1 - i);
		}
		printf("Case #%d: %d\n", z, ans);
	}

 	return 0;

}
