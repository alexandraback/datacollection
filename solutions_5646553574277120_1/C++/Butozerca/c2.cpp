#include<cstdio>
#include<algorithm>
using namespace std;

long long vals[200];
int C, D, V;


int main () {
    int Z;
    scanf("%d", &Z);
    for(int zz = 1; zz <= Z; ++zz) {
        scanf("%d %d %d", &C, &D, &V);
        for(int i = 0; i < D; ++i) scanf("%lld", &vals[i]);
        int res = 0;
        long long got = 0;
        sort(vals, vals + D);       
        
        for(int i = 0; i < D; ++i) {
            while(got < vals[i] - 1) {
                res ++;
                got += (got + 1)*C;
            }
            got += C*vals[i];
        }
        while(got < V) {
            got += C*(got+1);
            res ++;
        }


        printf("Case #%d: %d\n", zz, res);
    }
    return 0;
}
