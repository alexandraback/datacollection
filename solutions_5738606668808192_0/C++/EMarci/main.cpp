#include <cstdio>
#include <iostream>
#include <vector>

#define lim 10000ll

using namespace std;

int n,j;

int sole;
long long sol[500];
long long sold[500][11];

FILE *in, *out;

long long xInBaseB(long long x, int B) {
    long long res(0ll);
    long long bpow(1ll);
    for(int i=0; i<n; i++) {
        if(x&(1ll<<i)) res += bpow;
        bpow *= B;
    }
    /*long long y(x);


    long long ret(0ll);
    while(x>0) {
        ret = (ret*B) + (x&1);
        x >>= 1;
    }
    if(res != ret) {
        cerr << "!!!! " << y << ' ' << B << endl;
        cerr << res << ' ' << ret << endl;
    }*/
    return res;
}

long long div(long long x) {
    for(long long i=3; i<min(x,lim); i+=2) if(!(x%i)) return i;
    return -1ll;
}

int main()
{
    cin >> n;
    cin >> n >> j;

    for(long long i=0; i<(1<<(n-2)); i++) {
        //if(!(i%100000)) cerr << i << ': ' << sole << endl;
        long long x((i<<1) | (1ll) | (1ll<<(n-1)));
        bool ok(1);
        for(int b=2; b<=10; b++) {
            sold[sole][b] = div(xInBaseB(x,b));
            if(sold[sole][b]<0) {
                ok = 0;
                break;
            }
        }

        if(ok) sol[sole++] = x;
        if(sole == j) break;
    }

    if(sole < j) return 101;

    out = fopen("C-small.out","w");
    fprintf(out,"Case #1:\n");
    for(int i=0; i<sole; i++) {
        for(int j=n-1; j>=0; j--) fprintf(out,"%lld",((sol[i]>>j)&1));
        for(int j=2; j<=10; j++) fprintf(out," %lld",sold[i][j]);
        fprintf(out,"\n");
    }

    return 0;
}
