#include<stdio.h>
#include<assert.h>
#define sc(b,c) fscanf(in,b,c)
#define pr(b,c) fprintf(out,b,c)
FILE *in,*out;
int ar[21];
int S[1500000];
int map[2100000];
int main(){
    in = fopen("input.txt","r");
    out = fopen("output.txt","w");
    int T;
    int i,j,k,cases=1;
    sc("%d",&T);
    while(T--){
        int n;
        sc("%d",&n);
        for(i=0;i<20;i++) sc("%d",&ar[i]);
        S[0]=0;
        pr("Case #%d: \n",cases);
        for(i=0;i<=2000000;i++) map[i]=-1;
        for(i=1;i<(1<<20);i++){
            int x=__builtin_ctz(i);
            S[i]=S[i^(1<<x)]+ar[x];
            if(map[S[i]]!=-1){
                int sum=0;
                for(j=0;j<20;j++){
                    if(map[S[i]]&(1<<j)){
                        fprintf(out,"%d ",ar[j]);
                        sum+=ar[j];
                    }
                }
                fprintf(out,"\n");
                int sum2=0;
                for(j=0;j<20;j++){
                    if(i&(1<<j)){
                        fprintf(out,"%d ",ar[j]);
                        sum2+=ar[j];
                    }
                }
                assert(sum==sum2);
                break;
            }
            map[S[i]]=i;
        }
        if(i==(1<<20)) fprintf(out,"Impossible\n");
        else fprintf(out,"\n");
        cases++;
    }
    return 0;
}

