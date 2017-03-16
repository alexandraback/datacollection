#include<stdio.h>
#include<stdlib.h>
int main (){
	FILE *in,*out;
	in=fopen("in.in","r");
	out=fopen("out.out","w");
    int T,A,B,i,j;
    double p[100000],product,expected,min;
    fscanf(in,"%d",&T);
    for (i=1;i<=T;i++){
        fscanf(in,"%d %d",&A,&B);
        for (j=0;j<A;j++){
            fscanf(in,"%lf",&p[j]);
        }
        min=(B+2)*1.0;
        product=1;
        for (j=0;j<A;j++){
            product*=p[j];
            expected=product*(A+B-2*j-1)+(1-product)*(A+2*B-2*j);
            if (expected<min){
                              min=expected;
            }
        }
        fprintf(out,"Case #%d: %.6lf\n",i,min);
    }
    return 0;
}
