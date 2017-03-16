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


int main() {

    freopen("input_B.txt", "r", stdin);
    freopen("outputB.txt", "w", stdout);

    int T, A, B, K;
    cin >> T;

    for(int cas = 1; cas <= T; cas ++) {

        int ret = 0;
        cin >> A >> B >> K;

        for(int i = 0; i < A; i++) {
            for(int j = 0; j < B; j++) {
                if( (i & j) < K ) {
                    ret ++;
                }
            }
        }

        printf("Case #%d: %d\n", cas, ret);

    }

}
