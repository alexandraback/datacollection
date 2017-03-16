#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
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

int solve(int n, const vector<int>& a)
{
    int x = *max_element(a.begin(), a.end());
    int ans = INT_MAX;
    for(int i=1; i<=x; ++i){
        int cnt = i;
        for(int j=0; j<n; ++j)
            cnt += ((a[j] + i - 1) / i - 1);
        ans = min(ans, cnt);
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; ++i)
            cin >> a[i];

        cout << "Case #" << t << ": " << solve(n, a) << endl;
    }
}