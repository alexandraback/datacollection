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
#define clc(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long ll;
const int mxn = 210000;
int T;
void input(set<int> &se, int n){
    int b = n;
    while(b) {
        se.insert(b % 10);
        b /= 10;
    }
    // for (set<int>::iterator it = se.begin(); it != se.end(); it++) {printf("se = %d\n", *it);}
    // printf("se.size = %lu\n", se.size());
    return;
}
    

int main()
{
    // freopen("/Users/akanork/desktop/1.in", "r", stdin);
    // freopen("/Users/akanork/desktop/1.out", "w", stdout);
    scanf("%d", &T);
    int kase = 1;
    while (T--) {
        set<int> se;
        int ans, n, k = 0;
        scanf("%d", &n);
        for (int i = 1; i <= 2000; i++) {
            if (se.size() < 10) {
                input(se, i * n);
                //for (set<int>::iterator it = se.begin(); it != se.end(); it++) {printf("se = %d\n", *it);}
            }
            else {
                k = i;
                break;
            } 
        }

        if (!k) {
            printf("Case #%d: INSOMNIA\n", kase++);
        }
        else
        {
            ans = (k - 1) * n;
            printf("Case #%d: %d\n", kase++, ans);
        }    

    }


    return 0;
}