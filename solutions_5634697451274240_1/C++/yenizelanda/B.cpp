#include <stdio.h>

main() {
    int t,z;
    FILE *in=fopen("B.in","r");
    FILE *out=fopen("B.out","w");
    fscanf(in,"%d",&t);
    for (z=1;z<=t;z++) {
        char S[105];
        fscanf(in,"%s",S);
        int ans=0;
        for (int i=0;S[i];i++)
            if ((!S[i+1] && S[i]=='-') || (S[i+1] && S[i]!=S[i+1]))
                ans++;
        fprintf(out,"Case #%d: %d\n",z,ans);
    }
}
