#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <cstdio>
#define FOR(i,a,b) for(int i=(a);i<=(b); i++)
#define FR(i,b) for(int i=0; i<(b);i++)
#define DOWN(i,a,b) for(int i=(a); i >=(b); i--)
#define X first
#define Y second
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second
using namespace std;

int n;
string s;
void solve() {
    int currentUp = 0, res = 0;
    FOR(i,0,n)
    if (s[i] > '0') {
        if (currentUp < i) {
            res += i - currentUp;
            currentUp = i;
        }
        currentUp += s[i] - '0';
    }
    cout << res << endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n >> s;
        solve();
    }
    return 0;
}

