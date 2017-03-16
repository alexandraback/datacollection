//#define __test__aTest__
#ifndef __test__aTest__

#include <vector>
#include <list>
#include <map.h>
#include <set.h>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <assert.h>

using namespace std;

#define ll long long

int main() {
    
    freopen("/Users/zishirs/Documents/workspace/test/test/test.txt", "r", stdin);
    freopen("/Users/zishirs/Documents/workspace/test/test/output.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int index = 1; index <= T; ++index) {
        string s;
        ll L, n;
        cin >> s >> n;
        L = s.length();
        vector<ll> count(L, 0);
        ll c = 0;
        for (int i = (int)(L - 1); i >= 0; --i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||s[i] == 'u') {
                c = 0;
                continue;
            }
            ++c;
            count[i] = c;
        }
        queue<int> q;
        c = 0;
        for (int i = 0; i < L; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||s[i] == 'u') {
                c = 0;
                continue;
            }
            ++c;
            if (c >= n)
                q.push(i);
        }
        ll ret = 0;
        for (int i = 0; i <= L - n; ++i) {
            while (!q.empty() && q.front() - i + 1 < n) {
                q.pop();
            }
            if (q.empty())
                break;
            ret += L - q.front();
        }
        cout<<"Case #"<<index<<": "<<ret<<endl;
    }
    
    return 0;
}

#endif