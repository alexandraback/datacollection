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

int solve(int n)
{
    if(n == 0)
        return -1;

    bitset<10> bs;
    for(int a=n; ; a+=n){
        string s = to_string(a);
        for(char c : s)
            bs[c-'0'] = true;

        if(bs.all())
            return a;
    }
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int n;
        cin >> n;
        int ans = solve(n);

        if(ans == -1)
            cout << "Case #" << t << ": INSOMNIA" << endl;
        else
            cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}