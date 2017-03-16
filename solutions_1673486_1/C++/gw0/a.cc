#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(t, i, n) for (t i = 0; i < n; ++i)

using namespace std;

int main()
{
    int T;
    cin >> T;
    std::vector<double> v;
    for (int i = 0, A, B; i < T && cin >> A >> B; ++i) {
        v.resize(A);
        rep (int, j, A)
            cin >> v[j];
        
        double result = numeric_limits<double>::max();
        rep (int, j, A) {
            double pc = accumulate(v.begin(), v.end()-j, 1.0, multiplies<double>());
            double e = 2*j + B - A + 1;
            e += (1-pc) * (B+1);
            result = min(result, e);
        }
        result = min<double>(result, A+B+1);
        result = min<double>(result, B+2);
        cout << "Case #" << i+1 << ": " << setprecision(20) << result << '\n';
    }
}
