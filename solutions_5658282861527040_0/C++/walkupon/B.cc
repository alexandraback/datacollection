#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#define LL long long
using namespace std;

int main (){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, tt = 0;
    int n;
    scanf("%d", &t);
    while(t--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        for(int i = 0; i < a; ++i) for(int j = 0; j < b; ++j){
            ans += ((i & j) < c);
        }
        printf("Case #%d: %d\n", ++tt, ans);
    }
    return 0;
}
