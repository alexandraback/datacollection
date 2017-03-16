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
#define INF 0x3f3f3f3f
#define clc(x) memset(x, -1, sizeof(x))
using namespace std;
typedef long long ll;
const int mxn = 210000;
int T;
int a[105], b[105], k, ans = 0;
bool check() {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        if (a[i]) sum++;
    }
    if (sum == k) return true;
    else return false;
}


int main()
{
    // freopen("/Users/akanork/desktop/1.in", "r", stdin);
    // freopen("/Users/akanork/desktop/1.out", "w", stdout);
    scanf("%d\n", &T);
    int kase = 1;
    while (T--) {
        ans = 0;
        int sum = 0;
        k = 0;
        clc(a); clc(b);
        char c;
        while(scanf("%c", &c) == 1 && (c == '+' || c == '-')) {
           // printf("c = %c\n", c);
            if (c == '+') {a[k] = 1; sum++;}
            else a[k] = 0;
            k++;
    }
    // for (int i = 0; i < k; i++) printf("%d", a[i]);
    // printf("\n");
    while (!check()){
        if (a[0]){
            ans++;
            for (int i = 0; i < k; i++) {
                if (a[i]) a[i] = 0;
                else break;
            }
        }
        else {
            ans++;
            for (int i = 0; i < k; i++) {
                if (!a[i]) a[i] = 1;
                else break;
            }

        }

    } 

printf("Case #%d: %d\n", kase++, ans);
        
  }
  return 0;
}