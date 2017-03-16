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
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)


int T, L, N;
string S;

bool yes(char c) {
    return !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main () {
    cin >> T;
    FOR(cas, 1, T+1) {
        cin >> S >> N;
        L = S.length();
        int p = 0, q = -1, cnt = 0;
        long long ans = 0;
        while(p < L) {
            if(yes(S[p])) cnt++;
            else cnt = 0;
            p++;
            if(cnt >= N) q = p-N;
            ans += q+1;
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}

