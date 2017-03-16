#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <time.h>
using namespace std;
typedef long long llong;

inline int bit(int x, int i){ return (x>>i) & 1;}
inline int setb(int x, int i){ return x | (1 << i);}
inline int clrb(int x, int i){ return x & (~(1 << i));}
inline int lowb(int x){return x & (-x);}

int best[31][2];
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("Bl.txt", "w", stdout);
	
	memset(best, -1, sizeof(best));
	int tot = 0, tots = 0;
	for(int a = 0;a <= 10; ++a){
		for(int b = a; b <= a + 2 && b <= 10; ++b){
			for(int c = b; c <= a + 2 && c <= 10; ++c){
				//++tot;
				//if(c == a + 2) ++tots;
				int sum = a + b + c;
				if(c == a + 2) best[sum][1] = c;
				else best[sum][0]= c;
			}
		}
	}
	//printf("%d %d\n", tot, tots);
	//for(int i = 0;i <= 30; ++i) printf("%d %d\n", best[i][0], best[i][1]);
	
	int TT;
	scanf("%d", &TT);
	for(int cas = 1; cas <= TT; ++cas){
		int N, S, p;
		scanf("%d %d %d", &N, &S, &p);
		int cnt0 = 0, cnt1 = 0;
		for(int i = 0;i < N; ++i){
			int t;
			scanf("%d", &t);
			if(best[t][0] >= p) ++cnt0;
			else if(best[t][1] >= p) ++cnt1;
		}
		printf("Case #%d: %d\n", cas, cnt0 + min(cnt1, S));
	}
	return 0;
}

