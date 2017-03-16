#include <cstdio>

using namespace std;

FILE *in, *out;

int Q,n;
char a[19],b[19];

unsigned long long mmin[2][19];
unsigned long long mmax[2][19];

unsigned long long va,vb;
unsigned long long diff;

inline unsigned long long absdiff(unsigned long long x, unsigned long long y) {
    return (x<y) ? (y-x) : (x-y);
}

void refresh(unsigned long long x, unsigned long long y) {
    unsigned long long d = absdiff(x,y);
    if((d<diff) || ((d==diff) && ((x < va) || ((x==va) && (y < vb))))) {
        va = x;
        vb = y;
        diff = d;
    }
}

int main()
{
    in = fopen("B-large.in","r");
    out = fopen("B-large.out","w");

    fscanf(in,"%d",&Q);
    for(int q=1; q<=Q; q++) {
        fscanf(in,"%s",a);
        fscanf(in,"%s",b);
        for(n=0; a[n]!='\0'; n++);

        mmin[0][n] = mmin[1][n] = mmax[0][n] = mmax[1][n] = 0ull;
        unsigned long long pot(1ull);
        for(int i=n-1; i>=0; i--) {
            if(a[i] == '?') {
                mmin[0][i] = pot*0ull + mmin[0][i+1];
                mmax[0][i] = pot*9ull + mmax[0][i+1];
            } else {
                mmin[0][i] = pot*((unsigned long long)(a[i]-'0')) + mmin[0][i+1];
                mmax[0][i] = pot*((unsigned long long)(a[i]-'0')) + mmax[0][i+1];
            }
            if(b[i] == '?') {
                mmin[1][i] = pot*0ull + mmin[1][i+1];
                mmax[1][i] = pot*9ull + mmax[1][i+1];
            } else {
                mmin[1][i] = pot*((unsigned long long)(b[i]-'0')) + mmin[1][i+1];
                mmax[1][i] = pot*((unsigned long long)(b[i]-'0')) + mmax[1][i+1];
            }
            pot *= 10ull;
        }
        va = mmin[0][0];
        vb = mmax[1][0];
        diff = absdiff(va,vb);

        refresh(mmax[0][0],mmin[1][0]);

        unsigned long long ppot(pot/10ull);
        unsigned long long ssf(0ull);
        for(int i=0; i<n; i++) {
            pot /= 10ull;
            if(a[i]=='?') {
                if(b[i]=='?') {
                    refresh(ssf+mmin[0][i+1],ssf+mmax[1][i+1]);
                    refresh(ssf+mmax[0][i+1],ssf+mmin[1][i+1]);
                    refresh(ssf+pot+mmin[0][i+1],ssf+mmax[1][i+1]);
                    refresh(ssf+mmax[0][i+1],ssf+pot+mmin[1][i+1]);
                } else {
                    ssf += pot*((unsigned long long)(b[i]-'0'));
                    refresh(ssf+mmin[0][i+1],ssf+mmax[1][i+1]);
                    refresh(ssf+mmax[0][i+1],ssf+mmin[1][i+1]);
                    if(b[i]>'0') refresh(ssf+mmax[0][i+1]-pot,ssf+mmin[1][i+1]);
                    if(b[i]<'9') refresh(ssf+mmin[0][i+1]+pot,ssf+mmax[1][i+1]);
                }
            } else {
                if(b[i]=='?') {
                    ssf += pot*((unsigned long long)(a[i]-'0'));
                    refresh(ssf+mmin[0][i+1],ssf+mmax[1][i+1]);
                    refresh(ssf+mmax[0][i+1],ssf+mmin[1][i+1]);
                    if(a[i]<'9') refresh(ssf+mmax[0][i+1],ssf+mmin[1][i+1]+pot);
                    if(a[i]>'0') refresh(ssf+mmin[0][i+1],ssf+mmax[1][i+1]-pot);
                } else if(a[i]!=b[i]) {
                    break;
                } else ssf += pot*((unsigned long long)(a[i]-'0'));
            }
        }

        fprintf(out,"Case #%d: ",q);
        for(unsigned long long p=ppot; p>=1ull; p/=10ull) fprintf(out,"%llu",((va/p)%10ull));
        fprintf(out," ");
        for(unsigned long long p=ppot; p>=1ull; p/=10ull) fprintf(out,"%llu",((vb/p)%10ull));
        fprintf(out,"\n");

    }

    fclose(in);
    fclose(out);

    return 0;
}
