#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

#define FOR(i,a,n) for(int i = (int)a; i < (int)n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define ALL(c) c.begin(), c.end()
#define CLEAR(c,v) memset(c,v,sizeof(c))

typedef long long int lli;
typedef pair<int,int> ii;

const int N = 1000010;
int C[N];
bool good[N];

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    FOR(tcase, 1, T + 1) {
        string s;
        cin >> s;
        int n = s.length();
        int k;
        cin >> k;

        CLEAR(C, 0);
        REP(i, n) C[i] = !(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u');
        
        CLEAR(good, 0);

        for(int i = 0, j = 0, nc = 0; i < n; i++){
            while(j < n and j < i + k) {
                nc += C[j];
                j++;
            }
            if(nc == k) good[i] = 1;
            nc -= C[i];
        }

        lli ans = 0;
        int prev = -1;
        REP(i, n) {
            if(good[i]) {
                ans += (i - prev) * (lli)(n - i - k + 1);
                prev = i;
            }
        }
        cout << "Case #" << tcase << ": " << ans << endl;
    }
    return 0;
}

