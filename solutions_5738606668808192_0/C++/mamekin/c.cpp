#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

int convert(const string& s, int base)
{
    int n = s.size();
    int ans = 0;
    for(int i=0; i<n; ++i){
        ans *= base;
        ans += s[i] - '0';
    }
    return ans;
}

void solve(int n, int j)
{
    string s(n, '1');

    while(--j >= 0){
        int k = j;
        for(int i=1; i<n/2-1; ++i){
            s[i] = k % 2 + '0';
            s[n/2+i] = k % 2 + '0';
            k /= 2;
        }
        cout << s;

        string t = s.substr(0, n / 2);
        for(int i=2; i<=10; ++i)
            cout << ' ' << convert(t, i);
        cout << endl;
    }
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int n, j;
        cin >> n >> j;
        cout << "Case #" << t << ": " << endl;
        solve(n, j);
    }

    return 0;
}