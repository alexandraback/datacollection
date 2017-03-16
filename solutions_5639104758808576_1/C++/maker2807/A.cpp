#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <utility>
#include <set>
#include <map>
#include <cctype>

#define FOR(i,n) for(long long int i=0; i<n; i++)
#define MP(a,b) make_pair(a,b)
#define PB(x) push_back(x)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())

#define COND(p,t,f) ((p)?(t):(f))

#define PI 3.14159265

using namespace std;
typedef long long int lint;
typedef unsigned long long int ulint;



int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        int smax=0;
        cin >> smax;
        string s;
        cin >> s;
        int res = 0;
        int standing = 0;
        FOR(i,smax+1) {
            int p = s[i]-'0';
            if (i>standing) {
                res+=i-standing;
                standing = i;
            }
            standing+=p;
        }

        cout << "Case #" << t+1 << ": ";
        cout << res << endl;
    }

}
