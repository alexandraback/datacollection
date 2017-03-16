#include <bits/stdc++.h>

using namespace std;

long int d[100];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        long int C, D, V;
        scanf("%ld %ld %ld", &C, &D, &V);
        for(int i=0; i<D; i++) scanf("%ld", &d[i]);
        long int i=0, j=0, range=0;
        while(range < V) {
            while(range >= d[j]-1 && j < D) {range += C*d[j]; j++;} if(range >= V) break;
            range = 2*C*range + C; i++;
        }

        printf("Case #%d: %ld\n", t, i);

    }
    return 0;
}
