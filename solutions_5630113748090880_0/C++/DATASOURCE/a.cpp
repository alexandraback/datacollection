/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2016-04-16 09:29
# Filename: 		a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 120;

int cnt[3000];
int res[MAXN];
int mp[MAXN][MAXN];
 
int main(){
    int t, n;
    cin >> t;
    for(int Case = 1; Case <= t; Case++){
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < 2 * n - 1; i++){
            for(int j = 0; j < n; j++){
                cin >> mp[i][j];
                cnt[mp[i][j]]++;
            }
        }
        cout <<"Case #"<< Case <<": ";
        int dx = 0;
        for(int i = 1; i <= 2500; i++)
            if(cnt[i] & 1) res[dx++] = i;
        for(int i = 0; i < dx; i++){
            cout << res[i];
            if(i == dx - 1) cout << endl;
            else cout <<" ";
        }
    }
    return 0;
}

