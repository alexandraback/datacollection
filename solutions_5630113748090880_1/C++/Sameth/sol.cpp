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
    int t;
    cin >> t;
    For(cases, t) {
        vector <bool> iseven(3000, true);
        int n;
        cin >> n;
        For(i, 2*n - 1) {
            For (j, n) {
                int x;
                cin >> x;
                iseven [x] = ! iseven [x];
            }
        }

        printf("Case #%d:", cases + 1);
        For(i, 3000) {
            if (!iseven [i]) printf(" %d", i);
        }
        printf("\n");
    }

}
