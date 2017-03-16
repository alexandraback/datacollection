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

string solve(const string& s)
{
    int n = s.size();

    string ans;
    for(int i=0; i<n; ++i){
        string a = ans + s[i];
        string b = s[i] + ans;
        ans = max(a, b);
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
        string ans = solve(s);
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}