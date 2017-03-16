#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("D-small-attempt0.in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcases, n, m, k;
    cin >> testcases;
    for (int id = 1; id <= testcases; id++) {
        cin >> n >> m >> k;
        cout << "Case #" << id << ":";
        for (int j = 1; j <= k; j++) {
            cout << " " << j;
        }
        cout << endl;
    }

}
