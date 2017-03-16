#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define LD long double
#define LL long long

using namespace std;

int t,x,y,n,num,k;
LL ceng,pre,now,p;
double ans;

int c(int m,int n){
	int tx = 1;
	for (int i = 1; i <= n; i++){
		tx = tx * (m - i + 1) / i;
	}
	return tx;
} 

int main(){

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	scanf("%d", &t);
	for (int z = 1; z <= t; z++){
		scanf("%d%d%d", &n, &x, &y);
		ceng = (abs(x) + y) / 2 + 1;
		pre = ((ceng - 2) * 2) * (ceng - 1) + (ceng - 1);
		now = ((ceng - 1) * 2) * ceng + ceng;
		//		cout << ceng << pre << now;
		if (n <= pre) ans = 0;
		else if (n >= now) ans = 1;
		else{
			p = ceng * 2 - 1;
			n = n - pre;
			k = y + 1;
			if (n >= k + p - 1){
				ans = 1;
			}
			else if (k == p){
				ans = 0;
			}
			else{
				ans = 0;
				for (int j = k; j <= n; j++){
					ans = ans + c(n,j);
				}
				num = 1;
				for (int j = 1; j <= n; j++){
					num = num * 2;
				}
				ans = ans / num;
			}
		}
		printf("Case #%d: %.7lf\n", z, ans);
	}

 	return 0;

}
