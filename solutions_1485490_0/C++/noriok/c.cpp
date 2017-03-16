#include <iostream>
#include <list>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef long long ll;

struct D {
    ll n;
    int type;
};

ll ans_ = 0;

ll calc_1(list<D> as, list<D> bs) {
    if (as.empty() || bs.empty()) return 0;

    if (as.front().type == bs.front().type) {
        list<D> as1(as.begin(), as.end());
        list<D> bs1(bs.begin(), bs.end());

        ll send = min(as1.front().n, bs1.front().n);
        as1.front().n -= send;
        bs1.front().n -= send;
        if (as1.front().n == 0)
            as1.pop_front();
        else
            bs1.pop_front();

        return send + calc_1(as1, bs1);
    }
    else {
        list<D> as1(as.begin(), as.end());
        list<D> bs1(bs.begin(), bs.end());

        D d = as1.front();
        as1.pop_front();
        // throw out as
        ll ret1 = calc_1(as1, bs1);
        
        as1.push_front(d);
        bs1.pop_front();

        // throw out bs
        ll ret2 = calc_1(as1, bs1);

        return max(ret1, ret2);
    }
    return 0;

}

ll calc(vector<D>& as, vector<D>& bs) {
    list<D> as1(as.begin(), as.end());
    list<D> bs1(bs.begin(), bs.end());

    return calc_1(as1, bs1);


}

int main() {
    int ncases;
    cin >> ncases;

    For(cc, ncases) {
        int n, m;
        cin >> n >> m;

        vector<D> as, bs;
        For(i, n) {
            D d;
            cin >> d.n >> d.type;
            as.push_back(d);
        }

        For(i, m) {
            D d;
            cin >> d.n >> d.type;
            bs.push_back(d);
        }

        cout << "Case #" << (cc+1) << ": " << calc(as, bs) << '\n';
    }
}
