#include<bits/stdc++.h>
using namespace std;

int j,p,s,k;
int main(){
    int T,n;
    FILE *in = fopen("in.txt","r");
    FILE *out = fopen("output.txt","w");
    fscanf(in,"%d",&T);
    for(int t=1;t<=T;t++){
        fscanf(in,"%d%d%d%d",&j,&p,&s,&k);
        fprintf(out,"Case #%d: ",t);
        if(k>=s){
            int ans=j*p*s;
            fprintf(out,"%d\n",ans);
            for(int _j=1;_j<=j;_j++)
                for(int _p=1;_p<=p;_p++)
                    for(int _s=1;_s<=s;_s++)
                        fprintf(out,"%d %d %d\n",_j,_p,_s);
        }
        else{
            int ans=j*p*k;
            fprintf(out,"%d\n",ans);
            int tmp[1000]={1,2,2,3,3,1,2,3,3,1,1,2,3,1,1,2,2,3};
            int tmp2[1000]={1,2,2,3,3,1,2,3,3,1,1,2,3,1,1,2,2,3};
            int tmp3[1000]={1,2,2,3,3,1,2,3,3,1,1,2,3,1,1,2,2,3};
            for(int i=1;i<=k;i++) tmp[i-1]=i;
            for(int i=0;i<p;i++){
                for(int ii=0;ii<=k-1;ii++){
                    tmp2[ii+i*k]=(tmp[ii]+i);
                    if(tmp2[ii+i*k]>s) tmp2[ii+i*k]-=s;
                }
            }
            for(int i=0;i<j;i++){
                for(int ii=0;ii<=k*p-1;ii++){
                    tmp3[ii+i*k*p]=(tmp2[ii]+i);
                    if(tmp3[ii+i*k*p]>s) tmp3[ii+i*k*p]-=s;
                }
            }
            int c=0;
            for(int _j=1;_j<=j;_j++)
                for(int _p=1;_p<=p;_p++)
                    for(int cc=1;cc<=k;cc++){
                        int _s=tmp3[c];
                        fprintf(out,"%d %d %d\n",_j,_p,_s);
                        c++;
                    }
        }
    }
}
