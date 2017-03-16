#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 1000
#define maxst 2000000

using namespace std;

struct sums{int sum; int mask;};

int n, t, num;
int sm[maxn];
sums cur[maxst];

bool cmp(const sums &a, const sums &b){return(a.sum < b.sum || a.sum == b.sum && a.mask < b.mask);}

int add(const int &x, const int &msk, int &num){
	cur[num].sum = x;
	cur[num].mask = msk;
	++num;
	return 0;
}

int gen(const int &l, const int &r, const int &cs, const int &cm){
	if(l == r + 1)add(cs, cm, num);
	else{
		gen(l + 1, r, cs + sm[l], cm * 2 + 1);
		gen(l + 1, r, cs, cm * 2);
	}
}

int obr(const int &id){
	scanf("%d", &n);
	num = 0;
	for(int i = 1; i <= n; ++i)scanf("%d", &sm[i]);
	gen(1, n, 0, 0);
	sort(cur, cur + num, cmp);
	int i = 0;
	while(i < num - 1 && (cur[i].sum != cur[i + 1].sum || (cur[i].mask & cur[i + 1].mask != 0)))++i;
	printf("Case #%d:\n", id);
	if(i == num - 1)printf("Impossible\n");
	else{
		int am = cur[i].mask, bm = cur[i + 1].mask;
		//printf("am %d, bm %d\n", am, bm);
		for(int i = n; i >= 1; --i){
			if(am % 2 != 0)printf("%d ", sm[i]);
			//printf("am = %d %d\n", am, am % 2);
			am /= 2;
		}
		printf("\n");
		for(int i = n; i >= 1; --i){
			if(bm % 2 != 0)printf("%d ", sm[i]);
			bm /= 2;
		}
		printf("\n");
	}
	return 0;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)obr(i);

	return 0;
}
