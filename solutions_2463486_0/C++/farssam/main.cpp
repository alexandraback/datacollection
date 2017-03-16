#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#define N 20000000
using namespace std;
int t,dap,t_cnt;
long long pal[N];
long long n;
FILE *in,*out;
void input();
void solve(long long s,long long  e);
void output();
void pre_processing(void);
int ff(long long x);

int main(){
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    pre_processing();
    input();

}

void pre_processing(void){
    long long i,x;

    for(i=1;i<10000000;i++){
        x=i*i;
        if(ff(i)==1 && ff(x)==1) pal[n++]=x;
    }

//    for(i=0;i<n;i++){
//        fprintf(out,"%10lld ",pal[i]);
//        if((i+1)%10==0)
//            fprintf(out,"\n");
//    }
//
//fprintf(out,"\n");


}

int ff(long long x){
    int i,j;
    long long a[50]={0,};
    int n=0;

    if(x%10==0) return 0;

    while(x){
        a[n++]=x%10;
        x/=10;
    }

    for(i=0,j=n-1;i<j;i++,j--){
        if(a[i]!=a[j]) return 0;
    }

    return 1;
}
void input(){
    int i,j;
    long long s,e;
    fscanf(in,"%d",&t);
    for(t_cnt=1;t_cnt<=t;t_cnt++){
        fscanf(in,"%lld %lld",&s,&e);
        solve(s,e);
        output();
    }
}
void solve(long long s,long long  e){
    long long i,ss,ee;

    for(i=0;i<n;i++){
        if(s<=pal[i]){
            ss=i;
            break;
        }
    }
    if(i==n){
        dap=0;
        return;
    }

    for(i=0;i<n;i++){
        if(e==pal[i]){
            ee=i;
            break;
        }else if(e<pal[i]){
            ee=i-1;
            break;
        }
    }
    if(i==n){
        ee=n-1;
    }

    dap=ee-ss+1;

}

void output(){
    fprintf(out,"Case #%d: %d\n",t_cnt,dap);
}
