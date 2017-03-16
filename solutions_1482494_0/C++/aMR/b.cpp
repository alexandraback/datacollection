#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
typedef long long lint;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

const int maxn = 1100;

int n;
int a[maxn], b[maxn];
int used[maxn];
int cnt = 0, rating = 0;

int work() {
    int ret = 0, k = -1, fin = 1;
    for (int i=0; i<n; ++i) {
        if(used[i] == 2) continue;
        fin = 0;
        if(rating >= b[i]) {
            ret = 2 - used[i];
            used[i] = 2;
            return ret;
        }
        if(used[i] == 0 && rating >= a[i]) {
            if (k == -1 || b[i] > b[k]) {
                k = i;
            }
        }
    }
    if (fin) return 0;
    if (-1 == k) return -1;
    used[k] = 1;
    return 1;
}

int solve() {
    cnt = rating = 0;
    memset(used, 0, sizeof(used));
    while(1) {
        int r = work();
        if (-1 == r) return -1;
        if (0 == r) return cnt;
        rating += r;
        ++ cnt;
        if (rating == n*2) return cnt;
    }
    return -1;
}

int main()
{
    int z;
    scanf("%d", &z);
    for (int i=1; i<=z; ++i) {
        scanf("%d", &n);
        for (int j=0; j<n; ++j) {
            scanf("%d%d", &a[j], &b[j]);
        }
        int ans = solve();
        printf("Case #%d: ", i);
        if (ans == -1) puts("Too Bad");
        else printf("%d\n", ans);
    }
    return 0;
}

