using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXN = 1000005;
double p [MAXN];
double acum[MAXN];
double val [MAXN];

int main(){
    int T;
    int run = 1;
    cin >> T;
    while (T--){ 
        int a, b;
        cin >> a  >> b;
        
        acum[0] = 1.0;
        for (int i = 1; i <= a; i++){
            cin >> p[i];
            acum[i] = acum[i - 1] * p[i];
        }
        
        // If I erase k letters
        double best = 2 + b;
        for (int k = 0; k <= a; k++){
            best = min(best, acum[a - k] * (b - a + 1 + 2 * k) + (1 - acum[a - k]) * (2 * b - a + 2 + 2 * k));
        }
        
        printf("Case #%d: %.6lf\n", run++, best);
        
        
        
    }
    return 0;
}
