#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int solve(int n, int m, int k){
	if(k < 5) return k;
	int wid = 3, hei = 3;
	int currin = 5, used = 4;
	n-=3;
	m-=3;
	while(currin < k && (n + m)>0){
		if(n){
			currin += wid;
			hei++;
			used += 2;
		}
		if(currin < k && m){
			currin += hei;
			wid++;
			used += 2;
		}
	}
	
	if(n+m == 0 && currin < k){
		used += k - currin;
	}
	if(currin > k) used -= 1;
	return used;
}

int main(){
	int Z;
	scanf("%d", &Z);
	for(int zz = 1; zz <= Z; ++zz){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		if(n <= 2 || m <= 2){
			printf("Case #%d: %d\n", zz, k);
			continue;
		}
		int res = solve(n, m, k);
		printf("Case #%d: %d\n", zz, res);
	}
	return 0;
}
