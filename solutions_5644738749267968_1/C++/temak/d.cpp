#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

// #define double long double

#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int N;
vector<double> a;
vector<double> b;


void solve(int t) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int war = 0;
    int j = 0;
    for (int i = 0; i < N; ++i) {
        while (j < N && b[j] < a[i])
            j++;
        if (j == N) {
            war = N - i;
            j = -1;
            break;
        }
        j++;
    }
    if (j == N) {
        war = 0;
    }
    
    int dec_war = 0;
    int i = 0;
    for (int j = 0; j < N; ++j) {
        while (i < N && a[i] < b[j]) {
            i++;
        }
        if (i == N) {
            dec_war = j;
            i = -1;
            break;
        }
        i++;
    }
    if (i == N) {
        dec_war = N;
    }
    assert(dec_war >= war);
    printf("Case #%d: %d %d\n", t+1, dec_war, war);
    
   
}


    
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int T;
    scanf("%d", &T);
    a.reserve(1000);
    b.reserve(1000);
    
    for (int t = 0 ; t < T; ++t) {
        scanf("%d ", &N);
        for (int i = 0; i < N; ++i) {
            a.push_back(0);
            scanf("%lf", &a[i]);
        }
        for (int i = 0; i < N; ++i) {
            b.push_back(0);
            scanf("%lf", &b[i]);
        }
        solve(t);
        a.clear();
        b.clear();
        
    }
    
    return 0;
}

