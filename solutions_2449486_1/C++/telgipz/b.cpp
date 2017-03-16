#include <cstdio>
#include <algorithm>
using namespace std;

int nr, nc, b[1000][1000], r[1000], c[1000];


void pre() {
    for (int i=0; i<1000; i++) {
        r[i]=0; c[i]=0;
    }
}

void input() {
    scanf("%d %d", &nr, &nc);
    for (int i=0; i<nr; i++) {
        for (int j=0; j<nc; j++) {
            scanf("%d", &b[i][j]);
            r[i]=max(r[i], b[i][j]);
            c[j]=max(c[j], b[i][j]);
        }
    }
}

bool check() {
    for (int i=0; i<nr; i++) {
        for (int j=0; j<nc; j++) {
            if (!(r[i]<=b[i][j] || c[j]<=b[i][j])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int t;
    scanf("%d", &t);
    
    for (int ti=1; ti<=t; ti++) {
        pre();
        input();
        
        printf("Case #%d: ",ti);
        if(check()) printf("YES\n");
        else printf("NO\n");
        
    }
    
    return 0;
}