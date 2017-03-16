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
const int N = 1e5;
const int INF = 1e9;


int n;
int a[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

struct G {
    bool operator () (int a, int b) {
        return a > b;
    }    
};

void solve() {
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, a[i]);
    int answer = mx;
    for (int i = 1; i < mx; i++) {
        multiset < int, G > q;
        for (int j = 0; j < n; j++)
            q.insert(a[j]); 
        int cnt = 0;
        for (;;) {
            int x = *(q.begin());
            if (x <= i)
                break;
            q.erase(q.begin());
            int r1 = i;
            int r2 = x - i;
            q.insert(r1);
            q.insert(r2);
            cnt++;
            if (cnt > answer)
                break;
        }
        answer = min(answer, i + cnt);
    }
    printf("%d\n", answer);


}

void printAns() {

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
            cerr << "test id: " << tt << endl;
            printf("Case #%d: ", tt + 1);
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}

