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

const long long MAX = 100000000000000;

bool check(long long x)
{
    ostringstream oss;
    oss << x;
    string s = oss.str();
    reverse(s.begin(), s.end());
    return s == oss.str();
}

int main()
{
    vector<long long> x;
    for(long long i=1; i*i<=MAX; ++i){
        if(check(i) && check(i*i))
            x.push_back(i*i);
    }

    int n;
    cin >> n;

    for(int i=1; i<=n; ++i){
        long long a, b;
        cin >> a >> b;
        int ret = 0;
        for(unsigned j=0; j<x.size(); ++j){
            if(a <= x[j] && x[j] <= b)
                ++ ret;
        }

        cout << "Case #" << i << ": " << ret << endl;
    }

    return 0;
}