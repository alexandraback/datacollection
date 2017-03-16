#include <cstring>
#include <string>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << k << ": ";
        for (int i = 1; i <= c; ++i) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}