#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>

using namespace std;

const int D = 32;

int la[D], ra[D], lb[D], rb[D], lk[D], rk[D];

int fill(int x, int f, int* l, int* r)
{
    if (!(x & (1 << f))) return 0;

    for (int i = 0; i < f; i++) {
        l[i] = 0; r[i] = 1;
    }
    l[f] = r[f] = 0; 
    for (int i = f+1; i < D; i++) {
        l[i] = r[i] = ((x & (1 << i)) ? 1 : 0);
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    for (int sc = 0; sc < T; sc++) {
        int A, B, K;
        int i, j;
        cin >> A >> B >> K;

        long long ans = 0;
        for (int fa = 0; fa < D; fa++) {
            if (!fill(A, fa, la, ra)) continue;
            for (int fb = 0; fb < D; fb++) {
                if (!fill(B, fb, lb, rb)) continue;
                for (int fk = 0; fk < D; fk++) {
                    if (!fill(K, fk, lk, rk)) continue;
                    long long cur = 1;
                    for (i = 0; i < D; i++) {
                        int w = 0;
                        for (int a = la[i]; a <= ra[i]; a++)
                            for (int b = lb[i]; b <= rb[i]; b++)
                                if (lk[i] <= (a&b) && (a&b) <= rk[i])
                                    w++;
                        cur *= w;
                    }
                    ans += cur;
                }
            }
        }
         
        cout << "Case #" << sc+1 << ": ";
        cout << ans;
        cout << endl;
    }
    
    return 0;
}
