#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
int t, n, m, k;
bool check(int cnt)
{
    for(int a = 0; a <= n-2; a++)
        for(int b = 0; b <= m-2; b++)
        {
            int cost = 2*(a+b);
            int num = a*b + cost;
            if(num >= k && cost <= cnt) return 1;
            if(cost>=cnt) continue;
            if(cnt-cost >= k-num) return 1;
        }
    return 0;
}
int find()
{
    int l = 1, r = k;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(check(m)) r=m-1;
        else l=m+1;
    }
    return l;
}
int main() {
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    scanf("%d", &t);
    for(int i = 1; i<= t; i++)
    {
        int ans;
        scanf("%d%d%d", &n, &m, &k);
        if(n>m) swap(n,m);
        if(n==1) ans = k;
        else ans = find();
        printf("Case #%d: %d\n", i,ans);
    }
    return 0;
}
