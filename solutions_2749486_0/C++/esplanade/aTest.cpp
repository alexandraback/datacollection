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
        int x, y;
        cin >> x >> y;
        int count = 0;
        char s[500];
        if (x > 0) {
            for (int i = 0; i < x; ++i) {
                s[count++] = 'W';
                s[count++] = 'E';
            }
        }
        else {
            for (int i = 0; i < -x; ++i) {
                s[count++] = 'E';
                s[count++] = 'W';
            }
        }
        if (y > 0) {
            for (int i = 0; i < y; ++i) {
                s[count++] = 'S';
                s[count++] = 'N';
            }
        }
        else {
            for (int i = 0; i < -y; ++i) {
                s[count++] = 'N';
                s[count++] = 'S';
            }
        }
        s[count] = '\0';
        assert(count <= 500);
        cout<<"Case #"<<index<<": "<<s<<endl;
    }
    
    return 0;
}

#endif