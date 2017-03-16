#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#define DEBUG 0
using namespace std;
int main() {
    int tc,tci,i,j,needed,N,x,y;
    unsigned long long int prod;
    float sum;
    FILE *fp = fopen("C:/ikj/input.txt","r");
    FILE *fp2 = fopen("C:/ikj/output.txt","w");
    fscanf(fp,"%d",&tc);
    for(tci=0;tci<tc;tci++) {
        fscanf(fp,"%d %d %d",&N,&x,&y);
        if(x<0) x=x*(-1);
        if((x+y)==0) {
            if(N>0) fprintf(fp2,"Case #%d: 1.0\n",tci+1);
            else fprintf(fp2,"Case #%d: 0.0\n",tci+1);
            continue;
        }
        N-=(x+y)*(x+y-1)/2;
        if(N<0) {
            fprintf(fp2,"Case #%d: 0.0\n",tci+1);
            continue;
        }
        if(N>(x+2*y)) {
            fprintf(fp2,"Case #%d: 1.0\n",tci+1);
            continue;
        }
        if(x==0) {
            if(N>2*(x+y)) fprintf(fp2,"Case #%d: 1.0\n",tci+1);
            else fprintf(fp2,"Case #%d: 0.0\n",tci+1);
            continue;
        }
        sum=0;
        for(i=y+1;i<=N;i++) {
            prod=1;
            for(j=i+1;j<=N;j++) prod*=j;
            for(j=2;j<=N-i;j++) prod/=j;
            sum+=prod;
            if(DEBUG) fprintf(fp2,"%d %f\n",needed,sum);
        }
        sum/=float(pow(2,N));
        fprintf(fp2,"Case #%d: %f\n",tci+1,sum);   
        }
}
