#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps = 1e-9;
const double pi = 3.141592653589397;
long long cas, CAS, l, r, mid, ans;
double R, T;


double calc(double l){
    double ret = (l - 1) * l * 2 + 2 * l * R + l;
    return ret;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> CAS;
    for (cas = 1; cas <= CAS; cas++){
        cin >> R >> T;
        l = 0; r = 2000000000;
        while (l <= r){
            mid = (l + r) / 2;
            if (calc((double)mid) <= T){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }

}
