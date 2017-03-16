#include<bits/stdc++.h>
using namespace std;

int b;
long long m;
char x[100];
int main(){
    int T,n;
    FILE *in = fopen("in.txt","r");
    FILE *out = fopen("output.txt","w");
    fscanf(in,"%d",&T);
    for(int t=1;t<=T;t++){
        fscanf(in,"%d%lld",&b,&m);
        fprintf(out,"Case #%d: ",t);
        long long r=1;
        for(int qq=0;qq<b-2;qq++){
            r=r*2ll;
            if(r>=1e18) break;
        }
        printf("%lld %lld\n",r,m);
        if(r<m) fprintf(out,"IMPOSSIBLE\n");
        else if(r==m){
            fprintf(out,"POSSIBLE\n");
            for(int i=1;i<=b;i++){
                for(int j=0;j<i;j++) fprintf(out,"0");
                for(int j=0;j<b-i;j++) fprintf(out,"1");
                fprintf(out,"\n");
            }
        }
        else {
            fprintf(out,"POSSIBLE\n");
            x[b]='\0';
            x[b-1]='0';
            x[0]='0';
            for(int i=0;i<b-2;i++){
                long long mm = (1ll<<i);
                printf("%d %lld %lld %lld\n",i,mm,m,m&mm);
                if((m&mm)!=0) x[b-i-2]='1';
                else x[b-i-2]='0';
            }
            fprintf(out,"%s\n",x);
            for(int i=2;i<=b;i++){
                for(int j=0;j<i;j++) fprintf(out,"0");
                for(int j=0;j<b-i;j++) fprintf(out,"1");
                fprintf(out,"\n");
            }
        }
    }
}
