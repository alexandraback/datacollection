#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

string str[102];
int ret = 0, oc[30], N;
const int MOD = 1000000007;

bool check(int ar[]) {
    string ref;
    for(int i = 0; i < N; i++) {
        ref += str[ar[i]];
    }

    // << ref << endl;

    int cc[30];
    memset(cc, 0, sizeof(cc));
    cc[ref[0] - 'a'] = 1;

    for(int i = 1; i < ref.size(); i++) {
        if(ref[i] != ref[i - 1]) {
            if( cc[ref[i - 1] - 'a'] != oc[ref[i - 1] - 'a']) {
                return false;
            }
        }
        cc[ ref[i] - 'a' ] ++;
    }
    return true;
}

void recur(int cur, int mask_bit, int ar[]) {

    if(cur == N) {
        ret += check(ar);
        if( ret >= MOD ) {
            ret -= MOD;
        }
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!(mask_bit & (1 << i))) {
            int br[10];
            for(int j = 0; j < 10; j++) {
                br[j] = ar[j];
            }
            br[cur] = i;
            recur(cur + 1, mask_bit|(1 << i), br);
        }
    }

}

int main() {

    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);

    int T;
    cin >> T;

    for(int cas = 1; cas <= T; cas ++) {

        cin >> N;

        memset(oc, 0, sizeof(oc));
        for(int i = 0; i < N; i++) {
            cin >> str[i];
            for(int j = 0; j < str[i].size(); j++) {
                oc[str[i][j] - 'a'] ++;
            }
        }

        int ar[10];
        for(int i = 0; i < 10; i++) {
            ar[i] = -1;
        }
        ret = 0;
        recur(0, 0, ar);
        printf("Case #%d: %d\n", cas, ret);

    }

}
