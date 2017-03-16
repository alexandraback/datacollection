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
        else if(k==2){
            int ans=j*p*2;
            fprintf(out,"%d\n",ans);
            int tmp[100]={1,2,2,3,3,1,2,3,3,1,1,2,3,1,1,2,2,3};
            int c=0;
            for(int _j=1;_j<=j;_j++)
                for(int _p=1;_p<=p;_p++)
                    for(int cc=1;cc<=2;cc++){
                        int _s;
                        if(s==3) _s=tmp[c];
                        else _s=cc;
                        fprintf(out,"%d %d %d\n",_j,_p,_s);
                        c++;
                    }
        }
        else if(k==1){
            int ans=j*p;
            fprintf(out,"%d\n",ans);
            s=p;
            int tmp[10];
            for(int i=1;i<=s;i++) tmp[i]=i;
            for(int _j=1;_j<=j;_j++)
                for(int _p=1;_p<=p;_p++){
                    int _s=(_j+_p)%s+1;
                    fprintf(out,"%d %d %d\n",_j,_p,_s);
                }
        }
    }
}
