#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

#define OK puts("OK")
const int N = 110;
int t, n, s, p;

int b[N];

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B1.out", "w", stdout);
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int i;
    int ans;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &n, &s, &p);
        ans = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            if(b[i]/3 >= p) ans++;
            else if(b[i]/3 == p-1 && b[i]%3 != 0) ans++;
            else if(b[i]%3 == 0){
                if(b[i]/3 == p-1 && b[i] != 0 && s){
                    s--;ans++;
                }
            }
            else if(b[i]%3 == 2){
                if(b[i]/3 == p-2 && s){
                    s--;ans++;
                }
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}