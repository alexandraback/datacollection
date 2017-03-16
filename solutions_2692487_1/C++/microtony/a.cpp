#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t,a,n;
    int motes[1000];
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int min = 999999999;
        scanf("%d %d", &a, &n);
        for (int j=0; j<n; j++) {
            scanf("%d", &motes[j]);
        }
        sort(motes,motes+n);
        
        if (a==1) {
            printf("Case #%d: %d\n", (i+1), n);
            continue;
        }
        for (int j=0; j<=n; j++) {
            int tmp = n-j;
            int size = a;
            for (int k=0; k<j; k++) {
                while (size <= motes[k]) {
                    tmp++;
                    size = size + size - 1;
                }
                size += motes[k];
            }
            if (tmp < min) min = tmp;
        }
        printf("Case #%d: %d\n", (i+1), min);
    }
    return 0;
}
