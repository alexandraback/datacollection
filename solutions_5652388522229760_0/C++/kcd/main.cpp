#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>



using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }

vector<int> Digits(LL n) {
    vector<int> result;
    while (n > 0) {
        result.push_back(n % 10);
        n /= 10;
    }
    return result;
}

void Solution() {
    LL n;
    cin >> n;
    if (n == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }

    set<int> digits;
    int answer = -1;
    for (int i = 1; i <= 1000; ++i) {
        vector<int> d = Digits(n * i);
        digits.insert(d.begin(), d.end());
        if (digits.size() == 10) {
            answer = i;
            break;
        }
    }
    if (answer == -1) {
        cout << "INSOMNIA" << endl;
        return;
    }
    cout << answer * n << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
//        cerr << "Case #" << i + 1 << ": Done!" << endl;
    }

    return 0;
}


