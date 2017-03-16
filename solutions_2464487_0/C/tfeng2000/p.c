#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <math.h>
using namespace std;

int debug = 0;
void get_result(unsigned long long  r, unsigned long long  t) {
    // cout << r << " " << t << endl;
    unsigned long long  start = 1, end = (int)sqrt(t); 
    while (start <= end) {
        unsigned long long  mid = start  + (end - start)/2;
        double a1 = 2 * mid + 2 * r - 1;
        double a2 = t / mid;
        // cout << mid << " " << a1 << " " << a2 << endl;
        if (a1 == a2) {
            end = mid;
            break;
        } else if (a1 < a2) {
            start = mid + 1; 
        } else {
            end = mid - 1; 
        }
    }
    cout << end << endl;
}

int main() { 
    int T; 
    string str;

    cin >> T;
    getline(cin, str);
    unsigned long long  r, t; 
    for (int cnum = 1; cnum <= T; cnum++) {
        cin >> r >> t; 
        cout << "Case #" << cnum << ": ";
        get_result(r, t);
        getline(cin, str);
    }
} 
