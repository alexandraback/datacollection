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

const int Max = 2000005;
int ex[8],hib[Max];
int vst[Max], TRUE;
int next[Max];
int getNext(int n){
	int h = hib[n];
	do{
		while(n % 10 == 0) n /= 10;
	 	n = n / 10 + n % 10 * ex[h];
	}while(n >= Max);
	return n;
}
int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("Cs0.txt", "w", stdout);
	ex[0] = 1;
	for(int i = 1; i < 8; ++i) ex[i] = ex[i - 1] * 10;
	for(int i = 1, j = 0; i < Max; ++i){
		if(i >= ex[j]) ++j;
		hib[i] = j - 1;
	}
	++TRUE;
	for(int i = 1; i < Max; ++i) if(vst[i] < TRUE){
		int cur = i;
		do{
			next[cur] = getNext(cur);
			cur = next[cur];
			vst[cur] = TRUE;
		}while(cur != i);
	}

	int TT;
	scanf("%d", &TT);
	for(int cas = 1; cas <= TT; ++cas){
		int A, B;
		scanf("%d %d", &A, &B);
		++TRUE;
		llong tot = 0;
		for(int i = A; i <= B; ++i) if(vst[i] < TRUE){
			int cnt = 0, cur = i;
			do{
				cur = next[cur];
				if(A <= cur && cur <= B) ++cnt;
				vst[cur] = TRUE;
			}while(cur != i);
			tot += cnt * (cnt - 1) / 2;
		}
		printf("Case #%d: %lld\n", cas, tot);
	}
	return 0;
}

