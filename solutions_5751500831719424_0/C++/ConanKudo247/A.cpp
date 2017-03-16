#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i = (a); i <= (b);i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
#define maxn 1000
int n;
string s[maxn];
vector<int> a[maxn];
vector<char> kt[maxn];
bool invalid() {
    FOR(i,1,n)
    FOR(j,i+1,n) {
        if (a[i].size() != a[j].size()) return false;
        FR(k,a[i].size())
        if (kt[i][k] != kt[j][k]) return false;
    }
    return true;
}
void solve() {
    FOR(i,1,n) {
        a[i].clear();
        kt[i].clear();
        
        char now = '\0';
        FR(j,s[i].size()) {
            if (s[i][j] != now) {
                now = s[i][j];
                a[i].push_back(1);
                kt[i].push_back(now);
            } else a[i][a[i].size()-1]++;
        }
    }
    //check length
    if (!invalid()) {
        cout << "Fegla Won" << endl;
        return;
    }
    int res = 0;
    FR(id,a[1].size()) {
        vector<int> b(0);
        FOR(i,1,n) b.push_back(a[i][id]);
        sort(b.begin(),b.end());
        int pivot = b[b.size()/2];
        FR(i,b.size()) res += abs(pivot - b[i]);
    }
    cout << res << endl;
}
int main() 
{
    freopen("Asmall.in","r",stdin);
    freopen("A.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i,1,n) cin >> s[i];
        solve();
    }
    return 0;
}
