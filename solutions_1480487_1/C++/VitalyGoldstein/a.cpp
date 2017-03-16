#include <iostream>
#include <vector>

using namespace std;

double solve(double cur, double sum, const vector<double>& a)
{
    double l = 0.0, r = 1.0;
    const int ITER = 100;
    for(int i = 0; i < ITER; ++i) {
        double p = (l + r) * 0.5;
        double curScore = cur + sum * p;
        double sump = p;
        for(int i = 0; i < a.size(); ++i) {
            double minp = (curScore - a[i]) / sum;
            sump += std::max(minp, 0.0);
        }
        if (sump >= 1.0) r = p; else l = p; 
    }
    return (l + r) * 0.5;
}

void solve(const vector<double>& a)
{
    double sum = 0.0;
    for(int i = 0; i < a.size(); ++i) {
        sum += a[i];
    }
    for(int i = 0; i < a.size(); ++i) {
        vector<double> b = a;
        b.erase(b.begin() + i);
        printf(" %0.10f", solve(a[i], sum, b) * 100.0);
    }
}

int main()
{
    int tst;
    cin >> tst;
    for(int iter = 0; iter < tst; ++iter) {
        int n;
        cin >> n;
        vector<double> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        printf("Case #%d:", iter + 1);
        solve(a);
        printf("\n");
    }
    return 0;
}
