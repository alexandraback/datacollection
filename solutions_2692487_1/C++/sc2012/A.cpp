#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int f[101000], g[1010000], x[110];

int min(int a, int b)
{
    if(a < b) return a;
    return b;
}

int fun(int tmp, int l ,int r) {
    int ans = 0;
    //cout << l <<" " << r<<endl;
    if (tmp <= x[l]) {
        //if (tmp == 1) return 10000;
        while (tmp <= x[l]) {
            ans ++;
            tmp += tmp-1;
        }
        return min(ans+fun(tmp, l, r), r-l+1);
    }

    while (l <= r && tmp > x[l]) {
        tmp += x[l];
        l++;
    }
    //cout << l <<" " <<r <<endl;
    if (l > r) return ans;
    return ans+fun(tmp, l, r);
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, c;
    cin>>T;
    for (c = 0; c < T; ++c) {
        int a, n;
        cin>>a>>n;
        for (int i = 0; i < n; ++i)
            cin>>x[i];
        if (a == 1) {
            printf("Case #%d: %d\n", c+1, n);
        } else {
            sort(x, x+n);
            printf("Case #%d: %d\n", c+1, fun(a,0,n-1));
        }
    }
    return 0;
}
