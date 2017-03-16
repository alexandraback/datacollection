#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <functional>
#include <set>
#include <stdlib.h>
#define INF 0x3f3f3f3f
#define clc(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long ll;
int N, J, T;
const int mxn = 32;
int b[mxn];
int save[11];
ll append() {
    ll a = 1;
    for (int i = 1; i < N - 1; i++){
        b[i] = rand() % 2;
    }

    for (int i = 1; i < N - 1; i++) {
        a += pow(10, i) * b[i];
    }
    a += pow(10, N - 1);
    return a;
}
bool check(int base) {
    ll tra = 1;
    for (int i = 1; i < N - 1; i++) {
        tra += b[i] * pow(base, i);
    }
    tra += pow(base, N - 1);
    //printf("tra = %lld\n", tra);
    
    

    for (int i = 2; i < sqrt(tra) + 1; i++) {
          if (tra % i == 0) {
          save[base] = i;
          return false;
            }
    }
    
    return true;

}


int main()
{
    // freopen("/Users/akanork/desktop/1.in", "r", stdin);
    // freopen("/Users/akanork/desktop/1.out", "w", stdout);
   scanf("%d", &T);
   int kase = 1;
   while (T--) {
    scanf("%d %d", &N, &J);
    map<int, int> mp;
    int sum = 0, tmp; clc(save);
    printf("Case #%d:\n", kase++);
    while (sum < J) {
        tmp = 1;
        ll a = append();
        //printf("initial a = %d\n", a);
        for (int i = 2; i <= 10; i++) {
        if (check(i)) {tmp = 0; clc(save); break;}
    }
    if (tmp) {
        sum++;
        mp[a]++;
        if(mp[a] == 1) {
        printf("%lld ", a);
        for (int i = 2; i <= 10; i++) {
            printf("%d ", save[i]);
        }
        printf("\n");
        clc(save);
        }
    }
}
}


  return 0;
}