#include <cstdio>
#include <algorithm>

using namespace std;

int T;
long long k,c,s;

FILE *in, *out;

int main()
{
    in = fopen("D-small-attempt0.in","r");
    out = fopen("D-small-attempt0.out","w");
    fscanf(in,"%d",&T);
    for(int t=1; t<=T; t++) {
        fscanf(in,"%lld %lld %lld",&k,&c,&s);
        fprintf(out,"Case #%d:",t);
        if((c*s)<k) {
            fprintf(out," IMPOSSIBLE\n");
            continue;
        }

        for(int i=0; i<k; i+=c) {
            long long kpow(1ll);
            long long poz(1ll);
            for(long long j=i; j<i+c; j++) {
                poz += min(j,k-1ll)*kpow;
                kpow *= k;
            }

            fprintf(out," %lld",poz);
        }
        fprintf(out,"\n");
    }

    fclose(in); fclose(out);

    return 0;
}
