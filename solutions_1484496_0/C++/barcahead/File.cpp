#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int f[20];
int v[20], p[20];
int dp[2000001];
int n, s, flag, t;
vector<int> v1,v2;

void solve(int c, int k) {
    if (t<2 && c == s) {
        if (t==0) {
        for (int i=0; i<n; i++) {
            if (v[i]) v1.push_back(f[i]);
        }
            t++;
        }
        else {
            for (int i=0; i<n; i++) {
                if (v[i]) v2.push_back(f[i]);
            }
            t++;
        }
        return;
    }
    for (int i=k; i<n; i++) {
        if (!v[i] && c+f[i]<=s) {
            v[i] = 1;
            solve(c+f[i],i+1);
            v[i] = 0;
        }
    }
}

int main() {
    freopen("/Users/fengyelei/Desktop/in.in", "r", stdin);
    freopen("/Users/fengyelei/Desktop/out", "w", stdout);
    int T;scanf("%d",&T);
    for (int c=1; c<=T; c++) {
        scanf("%d",&n);
        int i, j;
        for (i=0; i<n; i++) {
            scanf("%d", &f[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        s = -1;
        for (i=0; i<n; i++) {
            for (j=n*100000; j>=0; j--) {
                if (dp[j]) dp[j+f[i]]++;
                if (dp[j] == 2) {s=j;break;}
            }
            if (s!=-1) break;
        }
        printf("Case #%d: \n", c);
        if (s==-1) printf("Impossible\n");
        else {
            v1.resize(0);
            v2.resize(0);
            flag = 0;
            t=0;
            memset(v,0,sizeof(v));
            memset(p,0,sizeof(p));
            solve(0,0);
            for (i=0; i<v1.size(); i++) {
                printf("%d ", v1[i]);
                //p[v1[i]] = 1;
            }
            printf("\n");
//            v2.resize(0);
//            flag = 0;
//            memset(v,0,sizeof(v));
//            solve(0,0);
            for (i=0; i<v2.size(); i++) {
                printf("%d ", v2[i]);
            }
            printf("\n");
        }
    }
}