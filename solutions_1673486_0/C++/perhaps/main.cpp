#include<stdio.h>

int main(){
    FILE *inf, *outf;
    inf = fopen("a.in","r");
    outf = fopen("a.out","w");

    int nn;
    fscanf(inf,"%d",&nn);
    int ii,i,j,a,b;
    double f[10001];
    double ans;

    for (ii=0;ii<nn;ii++){
        fscanf(inf,"%d %d", &a,&b);
        for (i=0;i<a;i++)
            fscanf(inf,"%lf", &f[i]);

        ans = b+2;
        for (i=0;i<a;i++){
            double p=1;
            for (j=0;j<=i;j++)
                p*=f[j];
            double tmp = p*((a-i-1)+(b-i))+(1-p)*((a-i-1)+(b-i+b+1));
            printf("%.6f\t%.6f\n",p,tmp);
            if (tmp<ans)ans =tmp;
        }
        fprintf(outf,"Case #%d: %.6f\n",ii+1, ans);
    }
    fclose(inf);
    fclose(outf);
}

