#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

double solve() {
    int a,b;
    double res;
    cin >> a >> b;
    vector<double> p(a);
    res = b+2; //C
    for (int i=0; i<a; i++) {
        cin >> p[i];
    }
    double prob = 1.0;
    res = min(res, (b+a+1)*prob);
    for (int i=0; i<a; i++) {
        prob *= p[i];
        res = min(res, (b-a+1+2*(a-i-1))*prob+((b-a+1+2*(a-i-1))+b+1)*(1-prob));
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << setprecision(10);
    for (int i=0; i<n; i++) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}
