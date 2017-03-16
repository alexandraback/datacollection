#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> Point;
typedef vector<Point> vp;
typedef vector<vp> vvp;

bool DBG = false;

int id1 = -1;
map<string, int> id_map1;
int get_id1(string s) {
    if (id_map1.find(s) != id_map1.end()) {
        return id_map1[s];
    } else {
        ++id1;
        id_map1.insert(mp(s, id1));
        return id1;
    }
}

int id2 = -1;
map<string, int> id_map2;
int get_id2(string s) {
    if (id_map2.find(s) != id_map2.end()) {
        return id_map2[s];
    } else {
        ++id2;
        id_map2.insert(mp(s, id2));
        return id2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int nt;
    cin >> nt;
    forn(t, nt) {
        int n;
        cin >> n;
        vp v(n);
        vvi xv(n);
        vvi yv(n);
        forn(i, n) {
            string s1, s2;
            cin >> s1 >> s2;
            int x = get_id1(s1);
            int y = get_id2(s2);
            v[i] = mp(x, y);
        }
        int res = 0;
        forn(mask, (1 << n)) {
            vp v1, v2;
            forn(i, n) {
                if (mask & (1 << i)) {
                    v1.push_back(v[i]);
                } else {
                    v2.push_back(v[i]);
                }
            }
            int cnt = 0;
            forn(i, v2.size()) {
                Point p = v2[i];
                bool xfound = false, yfound = false;
                forn(i, v1.size()) {
                    if (p.X == v1[i].X) {
                        xfound = true;
                    }
                    if (p.Y == v1[i].Y) {
                        yfound = true;
                    }
                }
                if (xfound && yfound) {
                    ++cnt;
                }
            }
            res = max(res, cnt);
        }
        cout << "Case #" << t + 1 << ": " << res << endl;
    }
    return 0;
}
