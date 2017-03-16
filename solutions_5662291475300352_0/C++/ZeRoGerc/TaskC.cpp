#include <iostream>
#include <vector>

using namespace std;

struct hiker {
    long long speed;
    long long start;
    hiker(long long speed = 0, long long start = 0) : speed(speed), start(start) {}
};

int T, n;
vector<hiker> hk;

int main() {
    freopen("C-small-1-attempt2.in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    for (int I = 0; I < T; I++) {
        cin >> n;
        hk.clear();
        cout << "Case #" << I + 1 << ": ";
        long long d, h, m;
        for (int i = 0; i < n; i++) {
            cin >> d >> h >> m;
            for (int i = 0; i < h; i++) {
                hk.push_back(hiker(m, d));
                m++;
            }
        }
        
        if (hk.size() < 2) {
            cout << 0 << '\n';
            continue;
        }
        if (hk[0].speed > hk[1].speed) {
            swap(hk[0], hk[1]);
        }
        
        long long time0 = (360 - hk[0].start ) * hk[0].speed;
        long long time1 = (360 - hk[1].start) * hk[1].speed;
        
        if (time0 < time1) {
            if (time1 >= time0 + 360 * hk[0].speed) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else {
            if (time0 >= time1 + 360 * hk[1].speed) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}