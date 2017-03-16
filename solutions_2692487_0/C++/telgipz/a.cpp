#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 200
using namespace std;

long long t, optoreach[MAX], a, n, mote[MAX];

void clear() {
    for (long long i=0; i<MAX; i++) optoreach[i] = -1;
}
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.output", "w", stdout);
    cin >> t;
    for (long long test = 1; test <= t; test++) {
        clear();
        cin >> a >> n;
        long long ret = n;
        for (long long i=0; i<n; i++) cin >> mote[i];
        sort(mote, mote+n);
        if (a > 1) {
            long long i=0, op=0;
            while (i < n) {
                if (a > mote[i]) {
                    a += mote[i];
                    optoreach[i] = op;
                    i++;
                }else {
                    a = 2*a - 1;
                    op++;
                }
            }
        }
        for (long long i=0; i<n; i++) {
            //cout << optoreach[i] << " ";
            if (optoreach[i] != -1) {
                ret = min(ret, n-i-1 + optoreach[i]);
            }
        }
        cout << "Case #" << test << ": " << ret << endl;
    }
    return 0;
}