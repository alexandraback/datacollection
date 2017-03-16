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
    ifstream cin("A-large.in");
#endif
    ofstream cout("out.txt");
    int T = 0;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int A,B;
        cin >> A >> B;
        vector<double> p(A);
        for (int i = 0; i < A; i++)
            cin >> p[i];

        double cur = 0;
        double res = 1e10;
        cout.precision(15);
        for (int i = 0; i < A; i++) {
            cur = 1-(1-cur)*p[i];
            //cout << cur << endl;
            double next = (A-i-1)*2+(B-A+1)+cur*(B+1);
            if(next < res)
                res = next;
        }
        double next = B+2;
        if (next < res)
            res = next;
        cout << "Case #" << t << ": ";
        cout << res;
        cout << endl;
    }
}
