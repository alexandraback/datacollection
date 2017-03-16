#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 12
using namespace std;
int maxgain = 0;
int r = 0, n = 0, E = 0;
int val[N];
void solve(int e, int act, int gain){
	if(act == n){
		if(gain > maxgain){
			maxgain = gain;
		}
		return;
	}
	for(int i = 0; i <= e; i++){
		solve(min(e - i + r, E), act + 1, gain + val[act] * i);
	}
}
int main(){
	int ncase;
	scanf("%d", &ncase);
	for(int nn = 1; nn <= ncase; nn++){
		maxgain = 0;
		scanf("%d%d%d", &E, &r, &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &val[i]);
		}
		solve(E, 0, 0);
		printf("Case #%d: %d\n", nn, maxgain);
	}
	return 0;
}