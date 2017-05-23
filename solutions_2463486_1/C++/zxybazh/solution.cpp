#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#define fo(i, l, r) for (int i = l; i <= r; ++i)
#define fd(i, r, l) for (int i = r; i >= l; --i)
#define LL long long
using namespace std;

int cases, a[20], d[10000000], t;
LL n, m, ans, tans;

bool pal(LL x) {
    if (x == 0) return false;
    int t;
    for (t = 0; x; x/=10){
        a[++t] = x % 10;
    }
    for (int i = 1; i <= t / 2; i++)
        if (a[i] != a[t-i+1]) return false;
    return true;
}

int findd(int l, int r, LL x) {
    int mid, ans = 0;
    while (l <= r) {
        mid = (l+r) / 2;
        if (d[mid]*(LL)d[mid] < x) {
            ans = mid;
            l = mid +1;
        } else r = mid - 1;
    }
    return ans;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
	cin >>cases; t = 0;
	for (int i = 1; i <= 1e7; i++) if (pal(i) && pal(i * (LL)i)) d[++t] = i;
	for (int _ = 1; _ <= cases; _++) {
        cout << "Case #"<< _ <<": ";
        cin >> n >> m;
        tans = findd(1, t, n);
        ans = findd(1, t, m+1)-tans;
        //cout << tans <<" " << ans + tans <<endl;
        cout <<ans <<endl;
	}
	return 0;
}
