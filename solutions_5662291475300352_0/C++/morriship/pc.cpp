#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define mod 1000000007
typedef long long ll;
using namespace std;

struct P {
    ll speed, pos;
};

vector<P> in;

int main() {
    int i, j, n;
    int t, tt;
    cin >> tt;
    xrep(t, 1, tt+1) {
        in.clear();
        cin >> n;
        rep(i, n) {
            ll a, b, c;
            cin >> a >> b >> c;
            rep(j, b) {
                P p;
                p.speed = c + j;
                p.pos = a;
                in.push_back(p);
            }
        }
        if (in.size() == 1) {
            cout << "Case #" << t << ": " << 0 << endl;
            continue;
        }
        if (in[0].speed < in[1].speed) {
            swap(in[0], in[1]);
        }
        double tt = (double)(360 - in[1].pos) / in[1].speed;
        if (tt * in[0].speed + in[0].pos + EPS >= 720) {
            cout << "Case #" << t << ": " << 1 << endl;
        }
        else {
            cout << "Case #" << t << ": " << 0 << endl;
        }
    }
}
