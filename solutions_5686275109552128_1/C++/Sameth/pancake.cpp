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
    int T;
    scanf("%d", &T);
    int maxi, n, x, res, moving;
    vector <int> plates;
    For(cases, T) {
        scanf("%d", &n);
        res = 10000;
        maxi = -1;
        plates.resize(n);
        For(i, n) {
            scanf("%d", &plates[i]);
            maxi = max(maxi, plates [i]);
        }
        res = maxi;
        
        for(int i = 1; i < maxi; i++) {
            moving = 0;
            For(j, n) {
                moving += (plates [j] - 1)/ i;
            }
            res = min(res, moving + i);
        }

        printf("Case #%d: %d\n", cases + 1, res);

    }
}
