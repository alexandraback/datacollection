/*
 * Author: fatboy_cw
 * Created Time:  2013/4/13 12:19:05
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 100 + 5;

int t, n, m, mat[maxn][maxn], ca;

bool allRow(int r, int v) {
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        if(mat[r][i] != -1) cnt++;
    }
    if(cnt == 0) return false;
    for(int i = 0; i < m; i++) {
        if(mat[r][i] != -1 && mat[r][i] != v) return false;
    }
    for(int i = 0; i < m; i++) {
        mat[r][i] = -1;
    }
    return true;
}

bool allCol(int c, int v) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(mat[i][c] != -1) cnt++;
    }
    if(cnt == 0) return false;
    for(int i = 0; i < n; i++) {
        if(mat[i][c] != -1 && mat[i][c] != v) return false;
    }
    for(int i = 0; i < n; i++) {
        mat[i][c] = -1;
    }
    return true;
}

bool delMat() {
    int mini = maxint;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] != -1) get_min(mini, mat[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(allRow(i, mini)) {
            return true;
        }
    }
    for(int j = 0; j < m; j++) {
        if(allCol(j, mini)) {
            return true;
        }
    }
    return false;
}

bool check() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] != -1) cnt++;
        }
    }
    return cnt == 0;
}

void outMat() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    freopen("B.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        while(delMat()) {
        }
        if(check()) {
            printf("Case #%d: YES\n", ++ca);
        }
        else {
            printf("Case #%d: NO\n", ++ca);
        }
    }
    return 0;
}

