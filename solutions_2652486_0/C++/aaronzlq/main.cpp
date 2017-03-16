#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

#define  clr(arr, x)  memset(arr, (x), sizeof(arr))
#define  rep(i, n)  for(int i = 0; i < (n); i++)
#define  repu(i, l, r)  for(int i = (l); i <= (r); i++)
#define  repd(i, r, l)  for(int i = (r); i >= (l); i--)
#define  MP  make_pair
#define  PB  push_back
#define  reget(str)  freopen(str, "r", stdin)
#define  vi  vector<int>

typedef long long llg;

void run() {
    int T, r, n, m, K, p[10];
    scanf("%d", &T);
    scanf("%d%d%d%d", &r, &n, &m, &K);
    printf("Case #1:\n");
    while(r--) {
        bool flag, yes;
        rep(i, K)  scanf("%d", p+i);
        yes = false;
        repu(i, 2, m)  repu(j, 2, m)  repu(k, 2, m) {
            flag = true;
            if(yes)  break;
            rep(t, K) {
                if(1==p[t] || i==p[t] || j==p[t] || k==p[t] || i*j==p[t] || i*k==p[t] || j*k==p[t] || i*j*k==p[t])
                    continue;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                yes = true;
                printf("%d%d%d\n", i, j, k);
            }
        }
    }
}

int main() {
	reget("data.in");
    freopen("data.out", "w", stdout);
	run();
	return  0;
}
















