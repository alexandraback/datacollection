#include <stdio.h>

//int n4[10]={0,5,8,10,12,14,16};

int min(int a,int b){
    if (a<b) return a;
    return b;
}

int count(int n,int m,int k){
    int i;
    if (n==1) return 0;
    if (n==2) return 0;
    if (n==3) return min(m-2,(k-2)/3);
    if (m==4){
       if (k>=12) return 4;
       if (k>=10) return 3;
       if (k>=8) return 2;
       if (k>=4) return 1;
    }
    else {
         //i=0;
         //while ((k>=n4[i+1])&&(i<6)) i++;  
         //return i;
         if (k>=16) return 6;
         if (k>=14) return 5;
         if (k>=12) return 4;
       if (k>=10) return 3;
       if (k>=8) return 2;
       if (k>=4) return 1;
    }
}

int main(){
    int T,ti,tmpp,n,m,k,sum;
	FILE * inf, * outf;
	inf=fopen("C-small-attempt0.in","r");
	outf=fopen("C-small-attempt0.out","w");
	fscanf(inf,"%d",&T);
    for (ti=1;ti<=T;ti++){
        fscanf(inf,"%d %d %d",&n,&m,&k);
        if (n>m){
           tmpp=m;
           m=n;
           n=tmpp;
        }
        sum=count(n,m,k);
        fprintf(outf,"Case #%d: %d\n",ti,k-sum);
    }
    fclose(inf);
    fclose(outf);
    return 0;
}
