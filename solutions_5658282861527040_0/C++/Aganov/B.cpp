#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
//#include <math.h>

using namespace std;

int a, b, k, A, B, T, test, res;
int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for (test = 0; test < T; test++) {
        cin >> A >> B >> k;
        res = 0;
        for (a = 0; a < A; a++) {
            for (b = 0; b < B; b++) {
                if ((a & b) < k) {
                    res++;
                }
            }
        }

        cout << "Case #" << test + 1 <<": " << res << endl;

    }
    return 0;
}
