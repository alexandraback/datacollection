/*
 * Author: fatboy_cw
 * Created Time:  2013/5/5 0:10:26
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef long long lint;

const int maxn = 100 + 5;

lint T, A, N, sz[maxn], f[maxn][maxn], cas, MAX = 1000001;
queue< pair<lint, lint> > Q;

bool update(lint &u, lint v) {
    if(v > MAX) v = MAX;
    if(u == -1 || u < v) {
        u = v;
        return true;
    }
    return false;
}

int main() {
    freopen("A.out", "w", stdout);
    cin >> T;
    while(T--) {
        //scanf("%d%d", &A, &N);
        cin >> A >> N;
        for(int i = 0; i < N; i++) {
            //scanf("%d", sz + i);
            cin >> sz[i];
        }
        sort(sz, sz + N);
        memset(f, -1, sizeof(f));
        while(!Q.empty()) Q.pop();
        Q.push(make_pair(0, 0));
        f[0][0] = A;
        while(!Q.empty()) {
            lint u = Q.front().first;
            lint v = Q.front().second;
            lint w = f[u][v];
            if(w < 0) while(1);
            Q.pop();
            if(u == N) continue;
            if(w > sz[u]) {
                if(update(f[u + 1][v], f[u][v] + sz[u])) {
                    Q.push(make_pair(u + 1, v));
                }
            }
            if(v < N) {
                if(update(f[u][v + 1], f[u][v] * 2 - 1)) {
                    Q.push(make_pair(u, v + 1));
                }
            }
            if(v < N) {
                if(update(f[u + 1][v + 1], f[u][v])) {
                    Q.push(make_pair(u + 1, v + 1));
                }
            }
        }
        lint ans = -1;
        for(int i = 0; i <= N; i++) {
            if(f[N][i] != -1) {
                ans = i;
                break;
            }
        }
        printf("Case #%d: ", ++cas);
        cout << ans << endl;
    }
            
    return 0;
}

