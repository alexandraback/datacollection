#include <stdio.h>
#include <deque>
using namespace std;

int inp[100010];
deque<int> pos;

inline int Min(int a, int b) {
    return a<b ? a: b;
}
inline int Max(int a, int b) {
    return a>b ? a: b;
}

int main() {
    int casN;
    scanf("%d", &casN);

    int e, r, n;
    int curP, usd;
    long long ans;
    for (int casI = 0; casI < casN; casI++) {
        scanf("%d%d%d", &e, &r, &n);
        if (r > e) r = e;
        for (int i=0; i<n; i++) scanf("%d", &inp[i]);
        curP = n-1;
        pos.clear();
        pos.push_back(n-1);
        ans = 0;
        usd = 0;
        for (int i=n-1; i>=0; i--) {
            int ene = i > 0 ? r : e;
            while (ene > 0) {
                if (usd < e) {
                    int dif = Min(e-usd, ene);
                    usd += dif;
                    ene -= dif;
                    ans += (long long) dif * inp[curP];
                }
                if (ene == 0) break;
                pos.pop_front();
                int newP = pos.front();
                usd -= r * (curP - newP);
                curP = newP;
            }
            if (i==0) break;
            while (pos.size() > 0 && inp[i-1] >= inp[pos.back()]) pos.pop_back();
            pos.push_back(i-1);
            if (pos.front() == i-1) {
                curP = i-1;
                usd = 0;
            }
        }
        printf("Case #%d: %lld\n", casI+1, ans);
    }
    return 0;
}
