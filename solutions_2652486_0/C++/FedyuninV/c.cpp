#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)


int main() {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int t, r, n, m, k;
    cin >> t >> r >> n >> m >> k;
    int c[8];
    cout << "Case #1:\n";
    forn (test, r) {
        forn (i, 8) {
            c[i] = 0;
        }
        int temp;
        forn (i, k) {
            cin >> temp;
            int z = 0;
            while (temp % 2 == 0) {
                temp /= 2;
                z++;
            }
            c[3] = max(c[3], z / 2);
            c[1] = max(c[1], z % 2);
            z = 0;
            while (temp % 3 == 0) {
                temp /= 3;
                z++;
            }
            c[2] = max(c[2], z);
            z = 0;
            while (temp % 5 == 0) {
                temp /= 5;
                z++;
            }
            c[4] = max(c[4], z);

        }
        temp = n;
            forn (j, 8) {
                forn (ii, c[j]) {
                    cout << j + 1;
                }
                temp -= c[j];
            }
            forn (j, temp) {
                vector <int> tmp;
                tmp.clear();
                tmp.push_back(1);
                int currmin = 1;
                for (int i = 2; i < 5; i++) {
                    if (c[i] < c[currmin]) {
                        tmp.clear();
                        currmin = i;
                    }
                    if (c[i] == c[currmin]) {
                        tmp.push_back(i);
                    }
                }
                int g = tmp[rand() % tmp.size()];
                c[g]++;
                cout << g + 1;
            }
            cout << endl;
    }
	return 0;
}
