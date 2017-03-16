#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n, sum1;
const double eps = 1e-7;
const int N = 500;
int a[N];
double b[N];

bool ok(int k, double rate){
    for (int i = 0; i < n; i++) b[i] = a[i];
    double sum = sum1;
    b[k] += sum * rate;
    sum *= (1 - rate);
    for (int i = 0; i < n; i++)
        if (i != k && b[i] < b[k]){
            double p = b[k] - b[i];
            if (sum < p) return true;
            sum -= p;
        }
    if (sum > eps) return false; else return true;
}
void solve(){
    cin >> n; sum1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum1 += a[i];
    }
    for (int i = 0; i < n; i++){
        double l = 0, r = 100;
        while (fabs(l - r) > eps){
            double mid = (l + r) / 2;
            if (ok(i, mid / 100)) r = mid;
                else l = mid;
        }
         printf(" %.7f", l);
    }
    cout << endl;

}

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int T; cin >> T;
    for (int i = 1; i <= T; i++){
        printf("Case #%d:" , i);
        solve();
    }
}
