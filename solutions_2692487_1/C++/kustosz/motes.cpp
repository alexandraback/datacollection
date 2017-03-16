#include<cstdio>
#include<algorithm>
using namespace std;

long long motes[1000];

int main() {
    int T; scanf("%d", &T);
    for (int Case = 1; Case <= T; Case++) {
        long long a;
        int n;
        scanf("%lld%d", &a, &n);
        for (int i=0; i<n; i++) {
            scanf("%lld", motes+i);
        }
        sort(motes, motes+n);
        if (a==1) {
            printf("Case #%d: %d\n", Case, n);
            continue;
        }
        int ans = 1000000;
        int movessofar = 0;
        bool niepyklo = false;
        for (int i=0; i<n; i++) {
            if (motes[i] < a) {
                a += motes[i];
            } else {
                niepyklo = true;
                ans = min(ans, movessofar+n-i);
                a = 2*a - 1;
                i--;
                movessofar++;
            }
        }
        if (!niepyklo) {
            printf("Case #%d: 0\n", Case);
        } else {
            printf("Case #%d: %d\n", Case, min(ans, movessofar));
        }
    }
}

