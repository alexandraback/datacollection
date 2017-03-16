#include<stdio.h>
int a[10000];
int n;
double sum;
bool ok(double x,double score){
    int i;
    double s=0;
    for (i=0;i<n;i++)
        if (score>a[i])
            s+=(score-a[i])/sum;

    if (s-1>1e-10) return true; else return false;
}

int main(){
    FILE *inf, *outf;
    outf = fopen("a.out","w");
    inf = fopen("a.in","r");
    int nn,ii,i;
    fscanf(inf,"%d",&nn);
    for (ii=0;ii<nn;ii++){
        fscanf(inf,"%d",&n);
        sum=0;
        for (i=0;i<n;i++){
            fscanf(inf,"%d",&a[i]);
            sum+=a[i];
        }
        fprintf(outf,"Case #%d:",ii+1);
        for (i=0;i<n;i++){
            double l=0, r=1, mid;
            while (r-l>1e-10){
                mid =(l+r)/2;
                if (ok(mid,(double)a[i]+mid*sum))
                    r=mid;
                else
                    l=mid;
            }
            fprintf(outf," %.6lf", mid*100);
        }
        fprintf(outf,"\n");
    }
    fclose(outf);
    fclose(inf);
}
