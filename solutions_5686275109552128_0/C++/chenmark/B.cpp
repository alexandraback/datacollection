#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define FF first
#define SS second
#define MP make_pair
#define PB push_back

#define MOD 1000000007
#define INF 2000000000

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int MAXP = 1010;
int cnt[MAXP];

int T, d;

int main() {
    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {
        scanf("%d", &d); int res = INF;

        memset(cnt, 0, sizeof cnt); int p;

        for (int i = 0; i < d; i++) {
            scanf("%d", &p);
            cnt[p]++;
        }

        for (int max_start = 1000; max_start >= 1; max_start--) {
            int tot_splits = 0;
            
            for (int i = max_start+1; i < MAXP; i++) {
                int splits = i / max_start - (i % max_start == 0);
                tot_splits += cnt[i] * splits;
            }

            res = min(res, tot_splits + max_start);
        }

        cout << "Case #" << test << ": " << res << "\n";
    }
    
    return 0; 
}
