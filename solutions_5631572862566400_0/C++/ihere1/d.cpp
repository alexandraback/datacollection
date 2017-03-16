#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;

int jie[20];
int order[20], a[20];

int check(int x){
	for(int i = 0; i < x; ++i){
		int l = i - 1, r = i + 1;
		if(l < 0) l += x;
		if(r == x) r = 0;
		if(order[l] != a[order[i]] && order[r] != a[order[i]])
			return 0;
	}
	return 1;
}

int main() {
	jie[1] = 1;
	for(int i = 2; i <= 10; ++i)jie[i] = jie[i - 1] * i;
	int TT;
	scanf("%d", &TT);
	for(int cc = 1; cc <= TT; ++cc){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			a[i]--;
		}
		int ans = 0;
		for(int z = 0; z < jie[n]; ++z){
			int tmp = z;
			for(int i = 0; i < n; ++i){
				order[i] = i;
			}
			for(int i = 0; i < n; ++i){
				int now = tmp % (n - i);
				swap(order[i], order[i + now]);
				tmp /= (n - i);
			}
			for(int i = 2; i <= n; ++i){
				if(check(i)){
					ans = max(ans, i);
				}
			}
		}
		printf("Case #%d: %d\n", cc, ans);
	}
	return 0;
}

