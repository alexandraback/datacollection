#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int t,n,i,a[1005],p[1005],j;

int main(){
	scanf("%d", &t);
	int testcase = 0;
	while(++testcase <= t){
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
		for(i = 1; i <= n; i++)
		p[i] = i;
		int ans = 0;
		do{
			for(i = 1; i <= n; i++){
				bool flag = 1;
				for(j = 1; j <= i; j++){
					int l = j - 1;
					if(j - 1 == 0)
					l += i;
					int r = j + 1;
					if(j + 1 > i)
					r -= i;
					if(p[l] != a[p[j]] && p[r] != a[p[j]])
					flag = 0;
				}
				if(flag)
				ans = max(ans, i);
			}
		}while(next_permutation(p + 1, p + 1 + n));
		printf("Case #%d: ", testcase);
		printf("%d\n", ans);
	}
}

