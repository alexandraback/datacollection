#include <cstdio>

using namespace std;

long long sol[1000001];

bool dig[10];
void markdig(long long x) {
    while(x>0) {
        dig[x%10] = 1;
        x /= 10;
    }
}

bool alldig() {
    for(int i=0; i<10; i++) if(!dig[i]) return 0;
    return 1;
}

int T;
int n;

FILE *in,*out;

int main()
{
    sol[0] = -1;
    for(int i=1; i<=1000000; i++) {
        for(int i=0; i<10; i++) dig[i] = 0;
        long long j;
        for(j=i; !alldig(); j+=i) markdig(j);
        sol[i] = j-i;
    }

    in = fopen("A-large.in","r");
    out = fopen("A-large.out","w");

    fscanf(in,"%d",&T);
    for(int t=1; t<=T; t++) {
        fscanf(in,"%d",&n);
        fprintf(out,"Case #%d: ",t);
        if(!n) {
            fprintf(out,"INSOMNIA\n");
        } else fprintf(out,"%lld\n",sol[n]);
    }

    return 0;
}
