#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas){
		int A, B;
		int res = 0;
		scanf("%d %d", &A, &B);
		for(int n = A; n <= B; ++n){
			int m[8];
			int d = 0, upper = 1;
			while(upper < n) upper *= 10;
			for(int t1 = upper/ 10, t2 = 10; t2 < n; t1 /= 10, t2 *= 10){
				m[d] = n / t2 + n % t2 * t1;
				if(m[d] <= n || m[d] > B) continue;
				bool flag = true;
				for(int i = 0; i < d; ++i){
					if(m[d] == m[i]){
						flag = false;
						break;
					}
				}
				if(flag){
					++d;
					++res;
				}
			}
		}
		printf("Case #%d: %d\n", cas, res);
	}

	return 0;
}
