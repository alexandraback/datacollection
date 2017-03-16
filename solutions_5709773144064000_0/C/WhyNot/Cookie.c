
#include<stdio.h>

long double solve(long double C,long double F,long double X);

int main(){
    int i,T;
    long double C,F,X;
    FILE *f=fopen("input","r");
    FILE *g=fopen("output","w");
    fscanf(f,"%d",&T);
    for(i=0;i<T;i++){
        fscanf(f,"%Lf %Lf %Lf",&C,&F,&X);
        fprintf(g,"Case #%d: %.7Lf\n",i+1,solve(C,F,X));
    }
    fclose(f);
    fclose(g);
}

long double solve(long double C,long double F,long double X){
    long double time = 0, S = 2;
    while(1){
        time += C / S ;
        if(F * X <= C * (F+S))
            return time+(X-C)/S;
        S += F;
    }
}
