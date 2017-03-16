#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;
int cnt[9]; 
void solve(int left, vector<ll> vv) {
    ld best = 0; int bt=left, bth = 0, bf=0, be=0, bs=0;
    for (int t = 0; t <= left; t++) {
        for (int th = 0; t+th <= left; th++) {
            for (int f = 0; f+t+th <= left; f++) {
                for (int s = 0; s+f+t+th <= left; s++) {
                    int e = left-f-t-th-s;
                    if (t+2*f+s+e*8 < cnt[2]) continue;
                    if (th+s < cnt[3]) continue;
                    vector<ll> v;
                    for (int i=0; i < t; i++) v.push_back(2);
                    for (int i=0; i < th; i++) v.push_back(3);
                    for (int i=0; i < f; i++) v.push_back(4);
                    for (int i=0; i < s; i++) v.push_back(6);
                    for (int i=0; i < e; i++) v.push_back(8);
                    map<ll, int> m;
                    for (int i=0; i < (1<<left); i++) {
                        ll prod = 1;
                        for (int j=0; j < left; j++) if (i & (1<<j)) prod *= v[j];
                        m[prod]++;
                    }
                    ld cur = 1;
                    for (int i=0; i < vv.size(); i++) {
                        cur *= m[vv[i]];
                    }
                    if (cur > best) {
                        best = cur;
                        bt = t;
                        bth = th;
                        bf = f; 
                        bs = s;
                        be = e;
                    }
                }
            }
        }
    }
    for (int i=0; i < bt; i++) cout << 2;
    for (int i=0; i < bth; i++) cout << 3;
    for (int i=0; i < bf; i++) cout << 4;
    for (int i=0; i < bs; i++) cout << 6;
    for (int i=0; i < be; i++) cout << 8;
}
int main() {
    int T; cin >> T;
    for (int zz=1; zz <= T; zz++) {
        cout << "Case #" << zz << ": " << endl;
        ll R, N, M, K; cin >> R >> N >> M >> K;
        for (int i=0; i < R; i++) {
            memset(cnt, 0, sizeof cnt);
            vector<ll> vv;
            for (int j=0; j < K; j++) {
                ll v; cin >> v; 
                int c=0;
                while(v%5==0) { c++; v/=5; }
                cnt[5] = max(cnt[5], c);
                c=0;
                while(v%7==0) { c++; v/=7; }
                cnt[7] = max(cnt[7], c);
                vv.push_back(v);
                c=0;
                while(v%3==0) { c++; v/=3; }
                cnt[3] = max(cnt[3], c);
                c=0;
                while(v%2==0) { c++; v/=2; }
                cnt[2] = max(cnt[2], c);
            }
            int c=0;
            for (int j=0; j < cnt[5]; j++) {
                c++;
                cout << 5;
            }
            for (int j=0; j < cnt[7]; j++) {
                c++;
                cout << 7;
            }
            solve(12-c, vv);
            cout << endl;
        }
    }
    return 0;
}
