#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxx = 1000000 + 5;
char ans[maxx];

const char* solve() {
    int x, y;
    scanf("%d%d", &x, &y);

    char C[] = {'N', 'S', 'W', 'E'};

    int sum = abs(x) + abs(y);
    int mod = sum % 2;
    int n = 0, s= 0;
    for (s = 0; s < sum || s % 2 != mod; ++n, s+=n) {
    }

    ans[n] = 0;

    for (int i = n; i >0; --i) {
        if (x < 0) {
            x = -x;
            swap(C[2], C[3]);
        }
        
        if (y < 0) {
            y = -y;
            swap(C[0], C[1]);
        }

        if (x > y) {
            x -= i;
            ans[i-1] = C[3];
        } else {
            y -= i;
            ans[i-1] = C[0];
        }
    }

    if (x != 0 || y!=0) {
        cerr << "x=" << x << endl << "y="<<y << endl;
    }
    return ans;
}

int main() {
    freopen("B-large.in", "r", stdin);
    
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
