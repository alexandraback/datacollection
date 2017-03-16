#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <stack>
#include <list>
using namespace std;

int T;
string s;

int main() {
    int cases = 1;
    cin >> T;
    while(T-- ) {
        cin >> s;
        string ans("");
        ans = s[0];
        for(int i = 1; i < s.size() ; i++ ){
            if( ans[0] > s[i]) {
                ans = ans+s[i];
            } else {
                ans = s[i] + ans;
            }
        }
        cout << "Case #"<<cases++ << ": " << ans << endl;
    }
}