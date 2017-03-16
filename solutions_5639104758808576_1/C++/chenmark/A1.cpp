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

const int MAXN = 1010;

int T; int maxs; string str_in;

int scnt[MAXN];

bool good(int x) {
    int standing = x + scnt[0];

    for (int i = 1; i <= maxs; i++) {
        if (standing < i && scnt[i] > 0) return false;
        standing += scnt[i];
    }

    return true;
}

int main() {
    cin >> T;

    for (int test = 0; test < T; test++) {
        cin >> maxs >> str_in;

        memset(scnt, 0, sizeof scnt);

        for (int i = 0; i <= maxs; i++) {
            scnt[i] = str_in[i] - '0';
        }

        int hi = 1000; int lo = 0;

        while (lo < hi) {
            int mid = (hi + lo) >> 1;

            if (!good(mid)) {
                lo = mid+1;
            }
            else {
                hi = mid;
            }
        }

        cout << "Case #" << (test+1) << ": " << lo << "\n";
    }
    
    return 0; 
}
