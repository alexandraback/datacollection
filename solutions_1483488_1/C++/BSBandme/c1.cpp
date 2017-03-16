/*
 * c.cpp
 *
 *  Created on: 2012-4-14
 *      Author: cj
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>

using namespace std;

bool f[2000010];

int main(){
	int ncase;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &ncase);
	for(int i1 = 0; i1 < ncase; i1++){
		long long ans = 0;
		memset(f, 0, sizeof(f));
		int st, en;
		scanf("%d%d", &st, &en);
		int di = 1, i;
		for(i = 0; st >= di; i++, di *= 10);
		di /= 10; int l = i;
		for(int i = st; i <= en; i++){
			if(f[i]) continue;
			f[i] = 1;
			int n = 1, num = i;
			for(int j = 0; j < l - 1; j++){
				num = (num % di) * 10+ num / di;
				if(num <= en && num >= st && !f[num]){
					f[num] = 1;
					n++;
				}
			}
			ans += n * (n - 1) / 2;
		}
		printf("Case #%d: %lld\n", i1 + 1, ans);
	}
	return 0;
}




