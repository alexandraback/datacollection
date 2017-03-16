// vudduu - Codejam 2016 Round 1B
// Problem C
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

int N;

vector<pair<string, string> > v;
bool ori[1005];

vector<vector<int> > G0, G1;
vector<int> F0, F1;
bool T0[1005], T1[1005];

void dfs(int it, int&tot) {
    F(j, G0[it].S) {
        int i = G0[it][j];
        if(T0[F0[i]] == false && T1[F1[i]] == false) {
            T0[F0[i]] = T1[F1[i]] = ori[i] = true;
            tot--;
            F(k, G0[i].S) {
                if(T0[F0[G0[i][k]]] == false || T1[F1[G0[i][k]]] == false) {
                    dfs(G0[i][k], tot);
                }
            }
            F(k, G1[i].S) {
                if(T0[F0[G1[i][k]]] == false || T1[F1[G1[i][k]]] == false) {
                    dfs(G1[i][k], tot);
                }
            }
        }
    }
    F(j, G1[it].S) {
        int i = G1[it][j];
        if(T0[F0[i]] == false && T1[F1[i]] == false) {
            T0[F0[i]] = T1[F1[i]] = ori[i] = true;
            tot--;
            F(k, G0[i].S) {
                if(T0[F0[G0[i][k]]] == false || T1[F1[G0[i][k]]] == false) {
                    dfs(G0[i][k], tot);
                }
            }
            F(k, G1[i].S) {
                if(T0[F0[G1[i][k]]] == false || T1[F1[G1[i][k]]] == false) {
                    dfs(G1[i][k], tot);
                }
            }
        }
    }
    if(T0[F0[it]] == false || T1[F1[it]] == false) {
        T0[F0[it]] = true;
        T1[F1[it]] = true;
        tot--;
    }
}

void solve() {
    cin >> N;
    memset(ori, 0, sizeof(ori));
    memset(T0, 0, sizeof(T0));
    memset(T1, 0, sizeof(T1));
    v.resize(N);
    F0.resize(N);
    F1.resize(N);
    G0 = vector<vector<int> > (N);
    G1 = vector<vector<int> > (N);
    int it0 = 0;
    int it1 = 0;
    int tot = N;
    F(i, N) {
        cin >> v[i].first >> v[i].second;
        F(j, i) {
            if(v[i].first == v[j].first) {
                G0[i].PB(j);
                G0[j].PB(i);
                F0[i] = F0[j];
            }
            if(v[i].second == v[j].second) {
                G1[i].PB(j);
                G1[j].PB(i);
                F1[i] = F1[j];
            }
        }
        if(G0[i].S == 0) F0[i] = it0++;
        if(G1[i].S == 0) F1[i] = it1++;
    }
    F(i, N) {
        if(G0[i].S == 0 || G1[i].S == 0) {
            ori[i] = true;
            tot--;
            T0[F0[i]] = true;
            T1[F1[i]] = true;
        }
    }
    F(i, N) {
        if(T0[F0[i]] == false || T1[F1[i]] == false) {
            dfs(i, tot);
        }
    }
    printf("%d\n", tot);
}

int main(){
	//freopen("in.txt", "r", stdin);
	freopen("C-small-attempt2.in", "r", stdin);
	//freopen("C-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}
