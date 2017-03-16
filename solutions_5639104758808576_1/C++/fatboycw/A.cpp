/*
 * Author: fatboy_cw
 * Created Time:  2015/4/11 10:48:25
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
const int maxn = 1000 + 5;
int t, n, ca;
char ch[maxn];

int main() {
    freopen("A.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        scanf("%s", ch);
        int cur = 0, add = 0;
        for(int i = 0; i <= n; i++) {
            int m = ch[i] - '0';
            if(cur < i) {
                add += i - cur;
                cur += i - cur;
            }
            cur += m;
        }
        printf("Case #%d: %d\n", ++ca, add);
    }
    return 0;
}

