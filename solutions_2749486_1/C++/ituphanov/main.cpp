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

string solve(int x, int y)
{
    if (!x && !y) return "";
    int n = 1;
    string ans;
    while (1) {
        int Px = x, Py = y;
        ans += '.';
        for (int i = n; i >= 1; i--) {
            if (abs(Px) > abs(Py)) {
                if (Px > 0) {ans[i-1] = 'W'; Px -= i;}
                else {ans[i-1] = 'E'; Px += i;}
            } else {
                if (Py > 0) {ans[i-1] = 'S'; Py -= i;}
                else {ans[i-1] = 'N'; Py += i;}
            }
        }
        if (!Px && !Py) {
            for (int i = 0; i < n; i++) {
                if (ans[i] == 'N') ans[i] = 'S';
                else if (ans[i] == 'S') ans[i] = 'N';
                else if (ans[i] == 'E') ans[i] = 'W';
                else if (ans[i] == 'W') ans[i] = 'E';
            }
            return ans;
        }
        n++;
    }
    return "this sucks, man";
}

int main()
{
    int T;
    cin >> T;
    for (int sc = 0; sc < T; sc++) {
        int x, y;
        cin >> x >> y;
        string ans = solve(x, y);

        cout << "Case #" << sc+1 << ": ";
        cout << ans;
        /*cout << endl;
        cout << ans.length() << endl;*/
        cout << endl;
    }

    return 0;
}
