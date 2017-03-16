// MS Visual Studio
#include<cstdio>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

#define REP(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int i=(s); i<(n); ++i)

typedef long long lint;

const unsigned int MAGIC = 9243;

int n;
lint a[512];
int b[512];

void out(){
    REP(j, n) {
        if(b[j]) {
            printf("%d ", a[j]);
        }

    }
    printf("\n");

}

lint gen() {
    lint s = 0;
    REP(j, n) {
        if(rand() % 2) {
            b[j] = 1;
            s += a[j];
        } else {
            b[j] = 0;
        }
    }
    return s;
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    FOR(t, 1, tc+1) {
        printf("Case #%d:\n", t);
        cin >> n;
        REP(i, n) cin >> a[i];
        map<lint, int> was;
        int k = (n == 20) ? 3160 : 1000000;
        srand(MAGIC);
        FOR(i, 1, k + 1) {
            lint s = 0;
            REP(j, n) {
                if(rand() % 2) {
                    s += a[j];
                }
            }
            if(s > 0) {
                was[s] = i;
            }
        }
        while(true) {
            lint s = gen();
            if(was[s]) {
                out();
                srand(MAGIC);
                REP(i, was[s]-1) REP(j, n) rand();
                gen();
                out();
                break;
            }
        }
    }
}