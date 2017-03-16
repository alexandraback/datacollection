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

int solve(string s)
{
    s += '+';
    int n = s.size();

    int ans = 0;
    for(int i=0; i<n-1; ++i){
        if(s[i] != s[i+1])
            ++ ans;
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        string s;
        cin >> s;
        int ans = solve(s);
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}