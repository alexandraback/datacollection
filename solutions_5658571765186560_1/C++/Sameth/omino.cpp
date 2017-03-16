#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define For(i, n) for (int i = 0; i < (int) n; ++i)
#define SIZE(x) ((int) (x).size())
#define mp(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#ifndef DG
#define DG 0
#endif
#define LOG(...) (DG ? fprintf(stderr, __VA_ARGS__) : 0)

int main(){
    int x, r, c, T;
    scanf("%d", &T);
    For(cases, T) {
        scanf("%d %d %d", &x, &r, &c);
        if (r > c) swap(r, c);
        if (x > 6 || (r * c) % x != 0) {
            printf("Case #%d: RICHARD\n", cases + 1);
            continue;
        }
        int minr = (x + 1) / 2;
        int minc = x;
        if (r < minr || c < minc) {
            printf("Case #%d: RICHARD\n", cases + 1);
            continue;
        }
        if (x == 4 && r == 2) {
            printf("Case #%d: RICHARD\n", cases + 1);
            continue;
        }
        if (x == 5 && r == 3 && c < 6){
            printf("Case #%d: RICHARD\n", cases + 1);
            continue;
        }
        if (x == 6 && r == 3) {
            printf("Case #%d: RICHARD\n", cases + 1);
            continue;
        }
        
        printf("Case #%d: GABRIEL\n", cases + 1);
    }

}
