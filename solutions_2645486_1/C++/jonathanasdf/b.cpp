#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
int main() {
    int T; cin >> T;
    for (int zz=1; zz <= T; zz++) {
        ll E, R, N; cin >> E >> R >> N; ll v[N], res = 0;
        int bigger[N]; for (int i=0; i < N; i++) bigger[i] = N+E/R+2;
        stack<int> s;
        for (int i=0; i < N; i++) { 
            cin >> v[i];
            while(s.size() && v[i] >= v[s.top()]) {
                bigger[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        ll cur = E;
        for (int i=0; i < N; i++) {
            ll r = max(0LL, cur - max(0LL, E-R*(bigger[i]-i)));
            res += v[i]*r;
            cur = min(E, cur - r + R);
        }
        cout << "Case #" << zz << ": " << res << endl;
    }
    return 0;
}
