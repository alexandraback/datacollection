#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <cstring>


using namespace std;
typedef long long LL;
#define x1 gjigu
#define y1 djigd
template<typename T>
inline T Abs(const T& value) { return value < 0 ? -value : value; }
template<typename T>
inline T Sqr(const T& value) { return value * value; }

const int maxn = 2 * 1001 * 1000;

vector<int> a[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 1; i <= maxn; ++i) {
        vector<int> num;
        int val = i;
        while (val > 0) {
            num.push_back(val % 10);
            val /= 10;
        }
        reverse(num.begin(), num.end());
        for (int first = 0; first < num.size(); ++first) {
            val = 0;
            for (int j = 0; j < num.size(); ++j)
                val = val * 10 + num[(first + j) % num.size()];
            if (val > i)
                a[i].push_back(val);
        }
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
    }

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; ++t) {
        int A, B;
        cin >> A >> B;
        int ans = 0;
        for (int i = A; i < B; ++i)
            for (int j = 0; j < a[i].size(); ++j)
                if (a[i][j] <= B)
                    ++ans;
        cout << "Case #" << t+1 << ": " << ans << endl;
    }


    return 0;
}
