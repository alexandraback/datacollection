#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int L;
long long X;
char S[160013];

int c2i(char c) {
    if (c=='i') return 2;
    if (c=='j') return 4;
    if (c=='k') return 6;
}

int prod(int a, int b) {
    if (a&1) return 1^prod(a^1,b);
    if (b&1) return 1^prod(a,b^1);
    if (a==0) return b;
    if (b==0) return a;
    if (a==2) {
        if (b==2) return 1;
        if (b==4) return 6;
        if (b==6) return 5;
    }
    if (a==4) {
        if (b==2) return 7;
        if (b==4) return 1;
        if (b==6) return 2;
    }
    if (a==6) {
        if (b==2) return 4;
        if (b==4) return 3;
        if (b==6) return 1;
    }
}

int binpow(int x, long long p) {
    int cur = x;
    int ans = 0;
    for (int i=0;i<60;i++) {
        if (p&(1LL<<i)) ans = prod(ans,cur);
        cur = prod(cur,cur);
    }
    return ans;
}

int main() {
    FILE* fin = fopen("C-large.in","r");
    FILE* fout = fopen("C-large.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for (int t=1;t<=T;t++) {
        fscanf(fin,"%d%lld %s",&L,&X,&S);
        int limit = 16;
        if (X<16) limit = X;
        for (int i=1;i<limit;i++) for (int j=0;j<L;j++) S[i*L+j] = S[j];
        int cur = 0;
        for (int i=0;i<L;i++) cur = prod(cur,c2i(S[i]));
        int tot = binpow(cur,X);
        int ok = 1;
        if (tot!=1) ok = 0;
        if (ok) {
            cur = 0;
            int where = 0;
            for (;where<=limit*L;where++) {
                if (where==limit*L) {
                    ok = 0;
                    break;
                }
                cur = prod(cur,c2i(S[where]));
                if (cur==2) break;
            }
            where+=1;
            cur = 0;
            for (;where<=limit*L;where++) {
                if (where==limit*L) {
                    ok = 0;
                    break;
                }
                cur = prod(cur,c2i(S[where]));
                if (cur==4) break;
            }
        }
        fprintf(fout,"Case #%d: ",t);
        if (ok) fprintf(fout,"YES\n");
        else fprintf(fout,"NO\n");
    }

    return 0;
}
