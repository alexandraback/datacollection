#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char s[1005];

int main() {
    int cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <= cn; ci++) {
        int smax = 0;
        scanf("%d %s", &smax, s);
        int cur = s[0] - '0', ans = 0;
        for(int i = 1; i <= smax; i++) {
            if(cur < i) {
                ans += i - cur;
                cur = i;
            }
            cur += s[i] - '0';
        }
        printf("Case #%d: %d\n", ci, ans);
    }
    return 0;
}

