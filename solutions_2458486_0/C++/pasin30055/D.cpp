#include <iostream>
#include <cstdio>

#define MAX_N 20
#define MAX_K 40
#define MAX_T 205

using namespace std;

int k,n,s[MAX_K];
int mk;
int o[MAX_N], a[MAX_N][MAX_K];
int deg[MAX_K];
bool is[1<<MAX_N];
int enp[1<<MAX_N];
int path[1<<MAX_N][MAX_N];
int keys[1<<MAX_N][MAX_K];
int cou[MAX_T];
bool chk;

inline void clear() {
    for (int i = 0 ; i < MAX_T ; i ++) cou[i] = 0;
    for (int i = 0 ; i < (1<<n) ; i ++) is[i] = false;
}

int main() {
    int tests;
    scanf("%d", &tests);
    for (int test = 0 ; test < tests ; test ++) {
	scanf("%d %d", &k, &n);
	clear();
	for (int i = 0 ; i < k ; i ++) {
	    scanf("%d", &s[i]);
	    cou[s[i]] ++;
	}
	for (int i = 0 ; i < n ; i ++) {
	    scanf("%d %d", &o[i], &deg[i]);
	    cou[o[i]] ++;
	    for (int j = 0 ; j < deg[i] ; j ++) {
		scanf("%d", &a[i][j]);
		cou[a[i][j]] ++;
	    }
	}
	for (int i = 0 ; i < MAX_T ; i ++) {
	    if (i == 0) cou[i] = cou[i] > 0 ? 1 : 0;
	    else cou[i] = cou[i] > 0 ? cou[i - 1] + 1 : cou[i - 1];
	}
	mk = cou[MAX_T - 1] + 1;
	for (int i = 0 ; i < k ; i ++) s[i] = cou[s[i]];
	for (int i = 0 ; i < n ; i ++) {
	    o[i] = cou[o[i]];
	    for (int j = 0 ; j < deg[i] ; j ++) {
		a[i][j] = cou[a[i][j]];
	    }
	}
	is[0] = true;
	enp[0] = 0;
	for (int i = 0 ; i < mk ; i ++) keys[0][i] = 0;
	for (int i = 0 ; i < k ; i ++) keys[0][s[i]] ++;
	for (int i = 1 ; i < (1<<n) ; i ++) {
	    for (int j = 0 ; j < n ; j ++) {
		if ((i&(1<<j))!=0 && is[i - (1<<j)]) {
		    if (keys[i - (1<<j)][o[j]] > 0) {
			if (!is[i]) {
			    for (int key = 0 ; key < mk ; key ++) {
				keys[i][key] = keys[i - (1<<j)][key];
			    }
			    keys[i][o[j]] --;
			    for (int l = 0 ; l < deg[j] ; l ++) {
				keys[i][a[j][l]] ++;
			    }
			}
			chk = true;
			if (is[i]) {
			    for (int l = 0 ; l < enp[i - (1<<j)] ; l ++) {
				if (path[i][l] < path[i - (1<<j)][l]) {
				    chk = false;
				    break;
				} else if (path[i][l] > path[i - (1<<j)][l]) {
				    break;
				}
			    }
			}
			if (chk) {
			    is[i] = true;
			    for (int l = 0 ; l < enp[i - (1<<j)] ; l ++) {
				path[i][l] = path[i - (1<<j)][l];
			    }
			    path[i][enp[i - (1<<j)]] = j;
			    enp[i] = enp[i - (1<<j)] + 1;
			}
		    }
		}
	    }
	}
	if (is[(1<<n) - 1]) {
	    printf("Case #%d:", test + 1);
	    for (int i = 0 ; i < n ; i ++) printf(" %d", path[(1<<n) - 1][i] + 1);
	    printf("\n");
	} else {
	    printf("Case #%d: IMPOSSIBLE\n", test + 1);
	}
    }
    return 0;
}
