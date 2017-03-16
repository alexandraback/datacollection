#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9;

int x, r, c;

void read() {
    scanf("%d%d%d", &x, &r, &c);
}

int solve() {
    if (r < c) swap(r, c);    
    if ((r * c) % x != 0) return 0;
    if (x <= 2) {
        return 1;
    }
    if (x == 3) {
        return c >= 2;
    }
    if (x == 4) {
        return c >= 3;
    }
    assert(false);
}

void printAns(int x) {
    if (x == 1) 
        printf("GABRIEL\n");
    else
        printf("RICHARD\n");
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            printf("Case #%d: ", tt + 1);
            read();
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}

