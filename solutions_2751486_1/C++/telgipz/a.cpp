#include <cstdio>
#include <iostream>
#include <cstring>
#define NMAX 1000010
using namespace std;

char txt[NMAX];
int qs[NMAX];
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    long long t, n, out;
    scanf("%lld", &t);
    
    for(int test=1; test<=t; test++) {
        scanf("%s", txt);
        scanf("%lld", &n);
        printf("Case #%d: ", test);
        out = 0;
        int last = 0;
        long long len=strlen(txt);
        if (txt[0]!='a' && txt[0]!='e' && txt[0]!='i' && txt[0]!='o' && txt[0]!='u') qs[0] = 1;
        else qs[0] = 0;
        
        for(int i=1; i<len; i++) {
            if (txt[i]!='a' && txt[i]!='e' && txt[i]!='i' && txt[i]!='o' && txt[i]!='u') {
                qs[i]=qs[i-1]+1;
            }else qs[i]=qs[i-1];
        }
        
        long long p = len - n + 1;
        for(int i=0; i<p; i++) {
            //printf("%d ", qs[i]);
            //printf("%d %lld\n", i, i+n-1);
            if(qs[i-1] + n == qs[i+n-1]) {
                out += ((long long)(i-last+1)) * ((long long)(len-i-n+1));
                //printf("(%d, %d, %lld: %lld) ", i,i-last+1, len-i-n+1, out);
                last = i+1;
            }
        }
        
        printf("%lld\n", out);
        
    }
    
    return 0;
}