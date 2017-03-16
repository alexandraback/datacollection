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

vector<long long> solve(int k, int c, int s)
{
    if(c * s < k)
        return vector<long long>();

    vector<long long> ans;
    for(int i=0; i<s; ++i){
        long long a = 0;
        for(int j=0; j<c; ++j)
            a = a * k + (i * c + j) % k;
        ans.push_back(a + 1);

        if((i + 1) * c >= k)
            break;
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int k, c, s;
        cin >> k >> c >> s;
        vector<long long> ans = solve(k, c, s);

        if(ans.empty()){
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        }
        else{
            cout << "Case #" << t << ":";
            for(long long a : ans)
                cout << ' ' << a;
            cout << endl;
        }
    }

    return 0;
}