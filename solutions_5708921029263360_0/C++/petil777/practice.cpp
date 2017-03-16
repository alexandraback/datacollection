#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <stdlib.h>
using namespace std;
#define ll long long
#define mp make_pair
int lev, test, arr[51][51];
ll B, M;
int J, P, S, lim;
map<pair<int, int>, int> M1, M2, M3;
map<pair<int, pair<int, int> >, int > all;
int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C0.txt", "w", stdout);

	scanf("%d", &test);
	while (test--){
		++lev;
		M1.clear(); M2.clear(); M3.clear(); all.clear();
		scanf("%d%d%d%d", &J, &P, &S, &lim);
		for (int i = 1; i <= J; i++){
			for (int j = 1; j <= P; j++){
				for (int k = 1; k <= S; k++){
					if (all.find(mp(i, mp(j, k))) != all.end())continue;
					if (M1[mp(i, j)] == lim) continue;
					if (M2[mp(j, k)] == lim)continue;
					if (M3[mp(i, k)] == lim)continue;
					M1[mp(i, j)]++; M2[mp(j, k)]++; M3[mp(i, k)]++;
					all[mp(i, mp(j, k))]++;
				}
			}
		}
		printf("Case #%d: %d\n", lev, all.size());
		auto it = all.begin();
		while (it != all.end()){
			printf("%d %d %d\n", it->first.first, it->first.second.first, it->first.second.second);
			++it;
		}
	}
}