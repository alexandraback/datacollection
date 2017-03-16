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

int solve(int n, const string& s)
{
    int ans = 0;
    int cnt = 0;
    for(int i=0; i<=n; ++i){
        if(cnt < i){
            ans += i - cnt;
            cnt = i;
        }
        cnt += s[i] - '0';
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int n;
        string s;
        cin >> n >> s;
        cout << "Case #" << t << ": " << solve(n, s) << endl;
    }
}