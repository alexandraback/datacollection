#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    int T;
    cin>>T;
    REP(x, T) {
        int A, B;
        cin>>A>>B;
        int L = 10, L2 = 1;
        while (L < A) {
            L *= 10; L2 *= 10;
        }
        int res = 0;
        for (int i = A; i <= B; i++) {
            if (i == L) {
                L *= 10;
                L2 *= 10;
                continue;
            }
            int r = i;
            if (r < 10) continue;
            while (1) {
                r = r / 10 + (r % 10) * L2;
                if (r == i) {
                    break;
                }
                if (r >= A && r >= L2 && r <= i) {
                    res++;
                }
                //cout<<i<<' '<<r<<' '<<L<<' '<<L2<<endl;
            }
        }
        printf("Case #%d: %d\n", x + 1, res);
    }
}
