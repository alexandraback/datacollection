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

//0 1 2 3  4  5  6  7
//1 i j k -1 -i -j -k

int mult [8] [8] = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {1, 4, 3, 6, 5, 0, 7, 2},
    {2, 7, 4, 1, 6, 3, 0, 5},
    {3, 2, 5, 4, 7, 6, 1, 0},
    {4, 5, 6, 7, 0, 1, 2, 3},
    {5, 0, 7, 2, 1, 4, 3, 6},
    {6, 3, 0, 5, 2, 7, 4, 1},
    {7, 6, 1, 0, 3, 2, 5, 4}};

int inv [8] = {0, 5, 6, 7, 4, 1, 2, 3};

int translation[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3};

#ifndef DG
#define DG 0
#endif
#define LOG(...) (DG ? fprintf(stderr, __VA_ARGS__) : 0)

int main(){
    int T;
    scanf("%d", &T);
    For(cases, T) {
        ll l, x;
        char c;
        int state = 0;
        scanf("%lld %lld", &l, &x);
        if (x > 16) {
            x = 12 + (x % 4);
            if (x == 8) x = 16;
        }
        vector <int> sequence (l * x), prefix(l * x + 1);
        For(i, l) {
            scanf(" %c", &c);
            sequence [i] = translation [c - 'a'];
        }
        For(i, l) {
            for (int j = 1; j < x; j++) {
                sequence [i + l*j] = sequence [i];
            }
        }
        prefix [0] = 0;
        For(i, l * x) {
            prefix [i + 1] = mult[prefix [i]] [sequence [i]];
            if (state == 0 && prefix [i] == 1) state = 1;
            if (state == 1 && prefix [i] == 3) state = 2;
        }
        if (prefix.back() != 4 || state < 2) {
            printf("Case #%d: NO\n", cases + 1);
        }
        else printf("Case #%d: YES\n", cases + 1);

    }

}
