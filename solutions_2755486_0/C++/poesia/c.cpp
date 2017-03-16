#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

struct attack {
    int l, r, s, d;

    attack(int l, int r, int s, int d) : l(l), r(r), s(s), d(d) { }

    bool operator<(const attack& rhs) const {
        return d < rhs.d;
    }
};

struct update {
    int l, r, h;  
};

const int M = 100000;

int w[200000];

bool successful(attack& a) {
    for(int i = a.l; i <= a.r; i++) if(w[i] < a.s) return true;
    return false;
}

void updatew(update u) {
    for(int i = u.l; i <= u.r; i++)
        w[i] = max(w[i], u.h);
}

void update_all(vector<update>& us) {
    for_each(us.begin(), us.end(), updatew);
}

int main() {

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        fill(w, w + 200000, 0);

        vector<attack> att;

        for(int i = 0; i < n; i++) {
            int di, ni, wi, ei, si, deltadi, deltapi, deltasi;
            cin >> di >> ni >> wi >> ei >> si >> deltadi >> deltapi >> deltasi;

            for(int j = 0; j < ni; j++) {
                att.push_back(attack(2*(wi + j*deltapi) + M, 2*(ei + j*deltapi) + M, si + j*deltasi, di + j*deltadi));
            }
        }

        sort(att.begin(), att.end());

        int d = 0, ans = 0;
        vector<update> uv;
        
        for(int i = 0; i < att.size(); i++) {
            if(att[i].d > d) {
                update_all(uv);
                uv.clear();
            }
            
            d = att[i].d;

            if(successful(att[i])) {
                ans++;
                update u;
                u.l = att[i].l;
                u.r = att[i].r;
                u.h = att[i].s;
                uv.push_back(u);
            }
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }     

    return 0;
}
