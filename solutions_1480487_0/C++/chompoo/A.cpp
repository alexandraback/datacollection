#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

double ans[11],temp[11],data[11];

main(){
    FILE *in,*out;
    int T,t;
    int n;
    in=fopen("inA.in","r");
    out=fopen("outA.txt","w");
    fscanf(in,"%d",&T);
    //scanf("%d",&T);
    t=1;
    while(t<=T){
        fscanf(in,"%d",&n);
        //scanf("%d",&n);
        double sum0=0,sum1=0;
        for(int i=0;i<n;i++){
            fscanf(in,"%lf",&data[i]);
            //scanf("%lf",&data[i]);
            sum0+=data[i];
        }
        sum1=sum0;
        sum0=sum0*2.0/n;
        for(int i=0;i<n;i++){
            temp[i]=sum0-data[i];   
        }
        printf("Case #%d: ",t);
        fprintf(out,"Case #%d: ",t);
        for(int i=0;i<n;i++){
            printf("%lf ",temp[i]/sum1*100);
            fprintf(out,"%lf ",temp[i]/sum1*100);  
        }
        printf("\n");
        fprintf(out,"\n");
        t++;
    }
    getch();     
}
