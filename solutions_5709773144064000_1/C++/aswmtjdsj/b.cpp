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

using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = INT_MAX;

int main(){
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++) {
        double c, f, x;
        cin >> c >> f >> x;
        double t = 0., fc = 2., ans = x / fc; // max ans
        while(true) {
            double obj = x / fc, cost = c / fc + x / (fc + f);
            if(obj > cost) {
                t += c / fc;
                fc += f;
            }
            else {
                t += obj;
                ans = t;
                break;
            }
            //cout << t << endl;
        }
        printf("Case #%d: %.7f\n", cas, ans);
    }
}
