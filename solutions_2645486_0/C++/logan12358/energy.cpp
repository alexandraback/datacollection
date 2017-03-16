#include <cstdio>
#include <algorithm>
using namespace std;

int v[15];
int e, r, n;

int doo(int x, int ee) { // do thing x, with up to ee energy
    if(x==n) return 0;
    int best=0;
    for(int i=0; i<=ee; i++) {
        int temp=i*v[x]+doo(x+1, min(e, ee-i+r));
        if(temp>best) best=temp;
    }
    return best;
}

int main() {
int _t; scanf("%d", &_t);
for(int _i=1; _i<=_t; _i++) {
printf("Case #%d: ", _i);
    scanf("%d %d %d", &e, &r, &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    printf("%d\n", doo(0, e));
}}
    
