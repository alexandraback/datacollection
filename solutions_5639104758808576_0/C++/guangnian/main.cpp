#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define inf (1<<30)
const int N = 105;

int main()
{
    freopen("/Users/junchen/topcoder/tc/tc/A-small-attempt0.in", "r", stdin);
    freopen("/Users/junchen/topcoder/tc/tc/x.out", "w", stdout);
    int T;
    cin >> T;
    //cout << T << endl;
    int s;
    string str;
    for (int ca = 1; ca <= T; ca++) {
        cin >> s >> str;
        int cnt = 0, res = 0;
        for (int i = 0; i <= s; i++) {
            int del = max(0, i - cnt);
            res += del;
            cnt += str[i] - '0' + del;
        }
        printf("Case #%d: %d\n", ca, res);
    }
    
}