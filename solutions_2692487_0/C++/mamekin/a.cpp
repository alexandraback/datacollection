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
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int tc=1; tc<=t; ++tc){
        long long a;
        int n;
        cin >> a >> n;

        vector<int> x(n);
        for(int i=0; i<n; ++i)
            cin >> x[i];
        sort(x.begin(), x.end());

        if(a == 1){
            cout << "Case #" << tc << ": " << n << endl;
            continue;
        }

        int ret = INT_MAX;
        int cost = 0;
        for(int i=0; i<n; ++i){
            ret = min(ret, cost + n - i);

            while(a <= x[i]){
                a += a - 1;
                ++ cost;
            }
            a += x[i];
        }
        ret = min(ret, cost);

        cout << "Case #" << tc << ": " << ret << endl;
    }

    return 0;
}