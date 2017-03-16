#include <stdio.h>
using namespace std;

typedef long long int big;
main() {
    int t,z;
    FILE *in=fopen("D.in","r");
    FILE *out=fopen("D.out","w");

    fscanf(in,"%d",&t);
    for (z=1;z<=t;z++) {
        int k,c,s;
        fscanf(in,"%d%d%d",&k,&c,&s);
        fprintf(out,"Case #%d:",z);
        if ((k-1)/c+1>s)
            fprintf(out," IMPOSSIBLE");
        else {
            int j,l,i,a,b;
            big old=-1;
            for (a=1,j=0;a<=s;a++) {
                big num=0;
                for (i=0;i<c;i++) {
                    num=num*k+j;
                    if (j<k-1)
                        j++;
                }
                if (num==old)
                    break;
                fprintf(out," %lld",num+1);
                old=num;
            }
        }
        fprintf(out,"\n");
    }

}
