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

int multiply(int a, int b)
{
    static const bool x[][4] =
    {
        {false, false, false, false},
        {false, true , false, true },
        {false, true , true , false},
        {false, false, true , true }
    };
    static const int y[][4] =
    {
        {0, 1, 2, 3},
        {1, 0, 3, 2},
        {2, 3, 0, 1},
        {3, 2, 1, 0}
    };

    int ans = 0;
    if((a / 4 == 1) ^ (b / 4 == 1) ^ x[a%4][b%4])
        ans = 4;
    ans += y[a%4][b%4];
    return ans;
}

int power(int a, long long b)
{
    int ret = 0;
    int tmp = a;
    while(b > 0){
        if(b & 1)
            ret = multiply(ret, tmp);
        tmp = multiply(tmp, tmp);
        b >>= 1;
    }
    return ret;
}

string solve(const string& s, long long x)
{
    int n = s.size();

    int a = 0;
    int b = 0;
    int state = 0;
    int i;
    for(i=0; i<min(24LL, x)*n; ++i){
        int j = i % n;

        int k = 0;
        if(s[j] == 'i')
            k = 1;
        else if(s[j] == 'j')
            k = 2;
        else if(s[j] == 'k')
            k = 3;
        a = multiply(a, k);
        if(i < n)
            b = multiply(b, k);

        if(state < 3 && a == state + 1){
            ++ state;
            a = 0;
        }
    }

    if(state >= 3 && multiply(a, power(b, x - min(24LL, x))) == 0)
        return "YES";
    else
        return "NO";
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int l;
        long long x;
        string s;
        cin >> l >> x >> s;

        cout << "Case #" << t << ": " << solve(s, x) << endl;
    }
}