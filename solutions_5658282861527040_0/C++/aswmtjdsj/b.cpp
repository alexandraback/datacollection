#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>

using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = INT_MAX;
const double eps = 1e-8;

int sgn(double x) {
    return fabs(x) < eps ? 0:x < -eps ? -1:1;
}

int main(){
    int T;
    cin >> T;
    for(int c = 1; c <= T; c++) {
        int a, b, k, ans = 0;
        cin >> a >> b >> k;
        for(int i = 0; i < a; i++) {
            for(int j = 0;j < b; j++) {
                int biu = i & j;
                if(biu < k) {
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", c, ans);
    }
}
