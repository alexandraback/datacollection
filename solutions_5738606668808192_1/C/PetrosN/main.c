#include <stdio.h>
#include <stdlib.h>
int qwerty(int d){
    if(d==0) return 1;
    else return 10*qwerty(d-1);
}
int haze(long long int bin,int q){
long long int k=bin/qwerty(q);
return k%10;
}


int main()
{
    FILE *fp;
    fp=fopen("output.txt","w");
    long long int s,t,i,j,bin=100000000000000;
    fprintf(fp,"Case #1: \n");
    for(i=1 ; i<=500 ; i++){
        t=0;
        fprintf(fp,"1");
        for(j=0 ; j<15 ; j++){
            if(haze(bin,j)) fprintf(fp,"11");
            else fprintf(fp,"00");
        }
        fprintf(fp,"1 3 4 5 6 7 8 9 10 11 \n");
        if(haze(bin,0)==0) bin++;
        else{
        while(haze(bin,t)==1){t++;}
        bin+=9;
        for(s=1 ; s<t ; s++) bin+=(8*qwerty(s));
        }

    }


    return 0;
}


