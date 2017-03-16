#include <iostream>
#include <cstdio>
#define MAXN 22

using namespace std;

int n, a[MAXN], s[MAXN], s1, s2, n1, n2, a1[MAXN], a2[MAXN];
bool ok;

void writeout(){
    for (int i = 1; i <= n1; i++) printf("%d ", a1[i]);
    printf("\n");
    for (int i = 1; i <= n2; i++) printf("%d ", a2[i]);    
    printf("\n");
}

void duyet(int i){
    if (ok) return;
    if (s1 + s[n] - s[i - 1] < s2 || s2 + s[n] - s[i - 1] < s1) return;
    if (i > n){
        if (s1 == s2 && n1){
            writeout();
            ok = true;
        }
        return;
    }
    duyet(i + 1);
    s1 += a[i];
    a1[++n1] = a[i];
    duyet(i + 1);
    s1 -= a[i];
    n1--;
    s2 += a[i];
    a2[++n2] = a[i];
    duyet(i + 1);
    s2 -= a[i];
    n2--;
}

int main(){//
    freopen("C-small-attempt1.in", "rt", stdin);
    freopen("C-small-attempt1.out", "wt", stdout);
    int test;
    double res[MAXN];
    scanf("%d", &test);
    for (int t = 1; t <= test; t++){
        scanf("%d", &n);
        s[0] = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
        }
        printf("Case #%d:\n", t);
        ok = false;
        s1 = 0; s2 = 0;
        n1 = 0; n2 = 0;
        duyet(1);
        if (!ok) printf("Impossible\n");
    }
        
//    system("pause");    
    return 0;
}
