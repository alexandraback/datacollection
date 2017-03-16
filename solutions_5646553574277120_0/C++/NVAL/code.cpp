#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <time.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")

#define mp make_pair
#define pb push_back 
#define ll long long
#define sz(x) (int)(x).size()

int mas[33];
bool vis[33];

int go(int cur, int ost, int cnt, int v) {
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	for(int i = 0; i < cnt; i++) {
		for(int j = v; j >= 0; j--) {
			if(vis[j] && j + mas[i] <= v) vis[j+mas[i]] = true;
		}
	}
	bool ok = true;
	for(int i = 0; i <= v; i++) {
		if(!vis[i]) ok = false;
	}
	if(ok) return 5 - ost;
	int res = 5;
	if(ost) {
		for(int i = cur + 1; i <= v; i++) {
			mas[cnt] = i;
			res = min(res, go(i, ost - 1, cnt + 1, v));
		}
	}
	return res;

}

int main()
{
	freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //freopen("a.in","rt",stdin);
    //freopen("a.out","wt",stdout);
	
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		int C, D, V;
		scanf("%d %d %d", &C, &D, &V);
		int res = 0;
		for(int i = 0; i < D; i++) scanf("%d", &mas[i]);
		res = go(0, 5, D, V);
		printf("Case #%d: %d\n", t, res);
	}



    return 0;
}