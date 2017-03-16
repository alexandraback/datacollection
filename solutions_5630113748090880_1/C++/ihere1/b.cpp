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

int cnt[3000];

int main() {
	int TT;
	scanf("%d", &TT);
	for(int cc = 1; cc <= TT; ++cc){
		memset(cnt, 0, sizeof(cnt));
		int n;
		scanf("%d", &n);
		int x = n * (2 * n - 1);
		for(int i = 0; i < x; ++i){
			int y;
			scanf("%d", &y);
			cnt[y]++;
		}
		printf("Case #%d:", cc);
		for(int i = 0; i < 2900; ++i){
			if(cnt[i] % 2 == 1){
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}

