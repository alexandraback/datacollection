#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>


#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define pii piar < int, int >


using namespace std;


const int MAXN = 3000;


typedef long long LL;


int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        cout << "Case #" << q + 1 << ": ";
        int n;
        cin >> n;
        vector < int > line (MAXN);
        for (int i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int a;
                cin >> a;
                line[a]++;
            }
        }

        for (int i = 0; i < MAXN; ++i) {
            if (line[i] % 2 == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}