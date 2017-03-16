#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <limits>
#include <memory>
#include <numeric>
#include <utility>
#include <iomanip>

using namespace std;
typedef long long Int;


int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        int n; cin >> n;
        multimap<pair<int, int>,int> s1;
        multimap<int,int> s2;
        for(int i = 0; i < n; ++i) {
            int a, b; cin >> a >> b;
            s1.insert(make_pair(make_pair(a, b), i));
            s2.insert(make_pair(b, i));
        }
        
        int s = 0;
        int g = 0;
        vector<int> c(n);
        
        while(s < 2 * n) {
            for(auto i = s2.rbegin(); i != s2.rend(); ++i) {
                if(i->first <= s && c[i->second] < 2) {
                    s += 2 - c[i->second];
                    c[i->second] = 2;
                    ++g;
                    goto L;
                }
            }

            for(auto i = s1.rbegin(); i != s1.rend(); ++i) {
                if(i->first.first <= s && c[i->second] < 1) {
                    s += 1 - c[i->second];
                    c[i->second] = 1;
                    ++g;
                    goto L;
                }
            }

            break;
            
        L: ;
        }
        
        if(s < n * 2) {
            string y = "Too Bad";
            cout << "Case #" << x <<": " << y << endl;
        } else {
            int y = g;
            cout << "Case #" << x <<": " << y << endl;
        }
    }
}
