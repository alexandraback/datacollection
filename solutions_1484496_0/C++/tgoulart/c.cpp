#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

#define DEBUG
#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) 
#endif

int SUM(const vector <int> &v) {
    int ans = 0;
    for (int i=0; i < v.size(); ++i) {
        ans += v[i];
    }
    return ans;
}

void solve(int id) {
    printf("Case #%d:\n", id);
    
    int v[505];
    int n, sum = 0;
    
    scanf("%d", &n);
    for (int i=0; i < n; ++i) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    
    vector <int> table(sum+1, 0);
    table[0] = 1;
    sum = 0;
    
    for (int i=0; i < n; ++i) {
        for (int j=sum; j >= 0; --j) {
            if (table[j] != 0) {
                table[j+v[i]] += table[j];
            }
        }
        sum += v[i];
    }
    
    int index = -1;
    for (int i=0; i <= sum; ++i) {
        if (table[i] > 1) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        puts("Impossible");
        return;
    }
    
    vector <int> a, b;
    vector <bool> used(n, false);
    int total = index;
    
    for (int i=0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        if (v[i] <= total && table[total-v[i]] != 0) {
            a.push_back(v[i]);
            total -= v[i];
            used[i] = true;
            printf("%d ", v[i]);
        }
    }
    puts("");
    
    total = index;
    for (int i=0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        if (v[i] <= total && table[total-v[i]] != 0) {
            b.push_back(v[i]);
            total -= v[i];
            used[i] = true;
            printf("%d ", v[i]);
            if (total == 0) break;
        }
    }
    puts("");
    
    assert(SUM(a) == SUM(b));
}

int main() {
    int t, T = 1;
    
    scanf("%d ", &t);
    while (t--) {
        solve(T++);
    }
    
    return 0;
}
