#include<cstdio>
#include<algorithm>
using namespace std;

int vals[200];
char S[20000];
int mx;
int C, D, V;


void add(int reps, int val) {
    for(int c = 0; c < reps; ++c)
        for(int i = mx; i >=0; --i)
            if(i + val <= V && S[i] != false) {
                S[i+val] = true;
                mx = max(mx, i+val);
            }
}


int main () {
    int Z;
    scanf("%d", &Z);
    for(int zz = 1; zz <= Z; ++zz) {
        scanf("%d %d %d", &C, &D, &V);
        for(int i = 0; i < D; ++i) scanf("%d", &vals[i]);

        mx = 0;
        S[0] = true;
        int res = 0;
        for(int i = 1; i <= V; ++i) S[i] = false;

        for(int i = 0; i < D; ++i) 
            add(C, vals[i]);

        for(int j = 0; j <= V; ++j) {
            if(S[j] == false) {
                add(C, j);
                res++;
            }
        }

        printf("Case #%d: %d\n", zz, res);
    }
    return 0;
}
