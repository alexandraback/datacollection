#include <bits/stdc++.h>

using namespace std;

int d[100];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        int C, D, V;
        scanf("%d %d %d", &C, &D, &V);
        for(int i=0; i<D; i++) scanf("%d", &d[i]);
        int i=0, j=0, range=0;
        while(range < V) {
            while(range >= d[j]-1 && j < D) {range += C*d[j]; j++;} if(range >= V) break;
            range = 2*C*range + C; i++;
        }

        printf("Case #%d: %d\n", t, i);

    }
    return 0;
}
