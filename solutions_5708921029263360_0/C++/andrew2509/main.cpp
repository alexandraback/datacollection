#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <ctime>
#include <fstream>
#include <cmath>



using namespace std;

#ifndef LOCAL
#define cerr if(0)cerr
#endif
#define pb push_back
#define mp make_pair

#define F first
#define S second
#define RT fprintf(stderr, "\nTIME = %lf\n", 1.0 * clock()/CLOCKS_PER_SEC);

typedef long long ll;
typedef long double ld;

const int INFint = 2147483547;
const ll INF = 9223372036854775807ll;
const ll MOD = 1000000007ll;

#define FILE "horizon"

set<pair<int, pair<int, int> > > in;
multiset<pair<int, int> > pr[3][3];

vector<pair<int, pair<int, int> > > ans;
vector<pair<int, pair<int, int> > > cur;
int bst;



int J, p, s, k;

map<int, int> cnt;

void go(int a, int b, int c) {
//    cerr << a << ' ' << b << ' ' << c <<  ' ' << ans.size()<< endl;
    if (pr[0][1].count(mp(a, b)) > k) return;
    if (pr[0][2].count(mp(a, c)) > k) return;
    if (pr[1][2].count(mp(b, c)) > k) return;
    if (ans.size() == J * p * s) return;
    if (cur.size() == bst) {
        cnt[bst]++;
    }
    if (cnt[bst] > 5000000) return;
    if (cur.size() > bst) {
        ans = cur;
        bst = cur.size();
    }
    for (int i = 1; i <= J; i++) {
        for (int j = 1; j <= p; j++) {
            for (int it = 1; it <= s; it++) {
                pair<int, pair<int, int> > cc = mp(i, mp(j, it));
                if (in.count(cc)) continue;
                if (pr[1][2].count(mp(j, it)) >= k) continue;
                
                if (pr[0][1].count(mp(i, j)) >= k) continue;
                if (pr[0][2].count(mp(i, it)) >= k) continue;
                in.insert(cc);
                cur.pb(cc);

                pr[0][1].insert(mp(i, j));
                pr[0][2].insert(mp(i, it));
                pr[1][2].insert(mp(j, it));

                go(i, j, it);
                pr[0][1].erase(pr[0][1].find(mp(i, j)));
                pr[0][2].erase(pr[0][2].find(mp(i, it)));
                pr[1][2].erase(pr[1][2].find(mp(j, it)));
                cur.pop_back();
                in.erase(in.find(cc));
            }
        }
    }

    
}


int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
//    freopen(FILE".in", "r", stdin); freopen(FILE".out", "w", stdout);
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> J >> p >> s >> k;
        cur.clear();
        cnt.clear();
        ans.clear();
        bst = 0;
//        go(1, 1, 1);
        pr[0][1].clear();
        pr[0][2].clear();
        pr[1][2].clear();
        in.clear();
        pair<int, pair<int, int> > cc = mp(1, mp(1, 1));
        in.insert(cc);
        cur.pb(cc);
        pr[0][1].insert(mp(1, 1));
        pr[0][2].insert(mp(1, 1));
        pr[1][2].insert(mp(1, 1));
        go(1, 1, 1);
//        for (int i = 1; i <= J; i++) {
//            for (int j = 1; j <= p; j++) {
//                for (int it = 1; it <= s; it++) {
//                    pair<int, pair<int, int> > cc = mp(i, mp(j, it));
//                    if (in.count(cc)) continue;
//                    in.insert(cc);
//                    cur.pb(cc);
//                    pr[0][1].insert(mp(i, j));
//                    pr[0][2].insert(mp(i, it));
//                    pr[1][2].insert(mp(j, it));
//                    go(i, j, it);
//                    pr[0][1].erase(pr[0][1].find(mp(i, j)));
//                    pr[0][2].erase(pr[0][2].find(mp(i, it)));
//                    pr[1][2].erase(pr[1][2].find(mp(j, it)));
//                    cur.pop_back();
//                    in.erase(in.find(cc));
//                }
//            }
//        }
        cerr << TC << endl;
        printf("Case #%d: %d\n", TC, (int)ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %d %d\n", ans[i].F, ans[i].S.F, ans[i].S.S);
        }
    }
    RT;
    return 0;
}