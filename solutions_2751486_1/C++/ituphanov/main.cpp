#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>

using namespace std;

typedef double real;
typedef long long TT;

#define PB push_back
#define SQR(x) ((x)*(x))
#define PII pair<int, int>
#define VI vector<int>
#define VVI vector<VI >
#define VS vector<string>
#define VTT vector<TT>
#define VR vector<real>
#define A first
#define B second

bool vv(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    int T;
    cin >> T;
    for (int sc = 0; sc < T; sc++) {
        long long ans = 0;

        int i, j, k, n, m;
        string s;
        cin >> s >> n;
        m = s.length();

        k = 0;
        for (j = 0; j < m; j++) {
            if (vv(s[j]))
                k = 0;
            else k++;
            if (k == n) break;
        }
        //cout << s << endl;
        //cout << "n = " << n << endl;
        //cout << "j = " << j << endl;
        if (k == n) {
            ans = (m-1) - j + 1;
            //cout << "ans = " << ans << endl;
            for (i = 1; i < m; i++) {
                if (i > j-n+1) {
                    k = n-1;
                    while (j < m && k < n) {
                        j++;
                        if (vv(s[j]))
                            k = 0;
                        else k++;
                    }
                }
                if (j != m) {
                    ans += (m-1) - j + 1;
                }
                //cout << "i = " << i << ", j=" << j << ", k=" << k << ", ans=" << ans << endl;
            }
        }

        cout << "Case #" << sc+1 << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
