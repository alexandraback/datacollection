#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
using namespace std;

void smain();
int main(){
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/A-large.in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#ifndef M_PI
#define M_PI 3.14159265358979311599796346854418516
#endif
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-9
#define N 2002
/* --------- END TEMPLATE CODE --------- */
char s[N];
string w[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void smain() {
    int n;
    cin >> n;
    for (int cas = 1; cin >> s; ++cas) {
        vector<int> cnt(26), res(10);
        vector<bool> used(10);
        n = strlen(s);
        forn(i, n) cnt[s[i] - 'A'] += 1;
        for(int k = 0; k < n;) {
            forn(i, 10) if (!used[i]) {
                char d = 0;
                for (char c : w[i]) {
                    bool ok = true;
                    forn(j, 10) if (i != j && !used[j]) {
                        if (w[j].find(c) != string::npos) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        d = c;
                        break;
                    }
                }
                if (d) {
                    used[i] = true;
                    res[i] = cnt[d - 'A'];
                    for (char c : w[i]) cnt[c - 'A'] -= res[i], k += res[i];
                }
            }
        }
        string rs;
        forn(i, 10) forn(j, res[i]) rs.push_back(i + '0');
        cout << "Case #" << cas << ": " << rs << '\n';
        cerr << "Case #" << cas << ": " << rs << '\n';
    }
}
