#include <stdio>
#include <stdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;
int main() {
    int tc,tci,i,j,N;
    int k,d[10000],l[10000],D,possible,cur,maxval,thisval,max_rope;
    FILE *fp = fopen("C:/ikj/input.txt","r");
    FILE *fp2 = fopen("C:/ikj/output.txt","w");
    fscanf(fp,"%d",&tc);
    for(tci=0;tci<tc;tci++) {
        cur=0;possible=1;
        fscanf(fp,"%d",&N);
        for(i=0;i<N;i++) {
            fscanf(fp,"%ld %ld",&d[i],&l[i]);
        }
        fscanf(fp,"%ld",&D);
        if(l[0]>d[0]) l[0]=d[0];
        d[i]=D;l[i]=1000000001;
        i=0;
        do {
            maxval = -1;
            for(j=i+1;j<N+1;j++) {
                if(d[j]-d[i] <= l[i]) {
                    if(l[j]>(d[j]-d[i])) {
                        thisval = (d[j]-d[i]) ;
                        l[j]=thisval;
                    } else {
                        thisval = l[j];
                    }
                    if(thisval>maxval) {
                        maxval=thisval; max_rope = j;
                    }                                           
                } else {break;}
            }
            if(maxval == -1) {
                possible=0;break;
            }
            if(max_rope>=N) {
                possible=1;break;
            }
            i=max_rope;
        } while(1);
        if(possible) fprintf(fp2,"Case #%d: Yes\n",tci+1);
        else         fprintf(fp2,"Case #%d: No\n",tci+1);
    }
}
