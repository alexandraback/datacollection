#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <locale>
#include <cmath>
#include <queue>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    ifstream cin("B-small-attempt0 (1).in");
#endif
    ofstream cout("out.txt");
    int T = 0;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";

        int N;
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++)
            cin >> a[i] >> b[i];
        string err = "Too Bad";
        vector<int> used(N);
        int usedNum = 0;
        int stars = 0;
        int res = 0;
        while(usedNum < N) {
            res++;
            // find unused max stars
            int add = 0;
            int ind = 0;
            int last = 0;
            for (int j = 0; j < N; j++) {
                if (used[j] == 2)
                    continue;
                if (b[j] <= stars) {
                    ind = j;
                    add = 2;
                    break;
                }
                if (used[j] >= 1)
                    continue;
                if (a[j] <= stars && b[j] > last) {
                    ind = j;
                    add = 1;
                    last = b[j];
                }
            }
            if (add) {
                //cout << add << "\t" << ind << endl;
                usedNum += add == 2;
                stars += add - used[ind];
                //cout << stars << endl;
                used[ind] = add;
                continue;
            }
            break;
        }
        if (usedNum < N)
            cout << err;
        else
            cout << res;
        cout << endl;
    }
}
