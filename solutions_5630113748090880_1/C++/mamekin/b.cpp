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

vector<int> solve(const vector<vector<int> >& h)
{
    int n = h[0].size();
    vector<int> cnt(2501, 0);
    for(int i=0; i<2*n-1; ++i){
        for(int j=0; j<n; ++j){
            ++ cnt[h[i][j]];
        }
    }

    vector<int> ans;
    for(int i=1; i<=2500; ++i){
        if(cnt[i] % 2 != 0)
            ans.push_back(i);
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
        vector<vector<int> > h(2*n-1, vector<int>(n));
        for(int i=0; i<2*n-1; ++i){
            for(int j=0; j<n; ++j){
                cin >> h[i][j];
            }
        }

        vector<int> ans = solve(h);
        cout << "Case #" << t << ':';
        for(unsigned i=0; i<ans.size(); ++i)
            cout << ' ' << ans[i];
        cout << endl;
    }

    return 0;
}