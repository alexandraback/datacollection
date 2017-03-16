#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

FILE *in,*out;

typedef struct node{
    int a[20];
    int ck;
}node;

int data[21],d,t;
node temp[2000001];
int tt[20];

int chk(int ss){
    if(temp[ss].ck==1){
        fprintf(out,"Case #%d:\n",t);
        printf("Case #%d:\n",t);
        for(int i=0;i<d;i++){
            if(tt[i]==1){
                printf("%d ",data[i]);
                fprintf(out,"%d ",data[i]);
            }   
        }   
        printf("\n");
        fprintf(out,"\n");
        for(int i=0;i<d;i++){
            if(temp[ss].a[i]==1){
                printf("%d ",data[i]);
                fprintf(out,"%d ",data[i]);
            }   
        }   
        printf("\n");
        fprintf(out,"\n");
        return 1;
    }
    temp[ss].ck=1;
    for(int i=0;i<d;i++){
            temp[ss].a[i]=tt[i];
    }   
    return 0;   
}

int sub(int sum,int m){
    if(m==d){
        if(chk(sum)==1) return 1;
        else return 0;   
    } 
    tt[m]=0;  
    if(sub(sum,m+1)==1) return 1;
    tt[m]=1;
    if(sub(sum+data[m],m+1)==1) return 1;
    return 0;
}

main(){
    
    int T;
    in=fopen("inC.in","r");
    out=fopen("outC.txt","w");
    fscanf(in,"%d",&T);
    //scanf("%d",&T);
    t=1;
    while(t<=T){
        fscanf(in,"%d",&d);
        //scanf("%d",&d);
        for(int i=0;i<d;i++){
            fscanf(in,"%d",&data[i]);
            //scanf("%d",&data[i]);
        }
        for(int i=0;i<2000001;i++){
            temp[i].ck=0;   
        }
        sub(0,0);
        t++;
    }
    fclose(in);
    fclose(out);
    getch();   
}
