#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long llong;
typedef long double ldouble;

vector<int> pred;

void print(int x) 
{
    while (x > 0) {
        printf("%d ", pred[x]);
        x -= pred[x];

    }
    printf("\n");
}

int main()
{
    #ifdef DEBUG
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
 
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        printf("Case #%d:\n", tt + 1);
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        pred.assign(sum + 1, -1);
        pred[0] = 0;
        bool fond = false;
        for (int i = 0; i < n; ++i) {
            int cur = a[i];
            for (int j = sum; j >= cur; --j) {
                if (pred[j - cur] != -1) {
                    if (pred[j] != -1) {
                        print(j);
                        pred[j] = cur;
                        print(j);    
                        fond = true;
                        break;
                     
                    }
                    pred[j] = cur;
                }
                
            } 
            if (fond) break;
        }

        if (!fond) {
            puts("Impossible");
        }
    }

    return 0;
}
