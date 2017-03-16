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
    int res, standing, actual, numofpeople;
    scanf("%d", &T);
    For(cases, T) {
        res = 0; standing = 0;
        scanf("%d", &numofpeople);
        For(i, numofpeople + 1) {
            scanf("%1d", &actual);
            res += max (0, i - standing);
            standing = max(standing, i);
            standing += actual;
        }
        printf("Case #%d: %d\n", cases+1, res);
    }

}
