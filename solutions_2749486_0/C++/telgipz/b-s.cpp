#include <cstdio>
using namespace std;

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    
    int t, a, b;
    scanf("%d", &t);
    for (int test=1; test<=t; test++) {
        scanf("%d%d", &b, &a);
        printf("Case #%d: ", test);
        if(a >= 0) for(int i=0; i<a; i++) printf("SN");
        else for(int i=0; i>a; i--) printf("NS");
        if(b >= 0) for(int i=0; i<b; i++) printf("WE");
        else for(int i=0; i>b; i--) printf("EW");
        printf("\n");
    }
    return 0;
}
