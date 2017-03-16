#include<bits/stdc++.h>
using namespace std;
char x[100],y[100];
vector<int>A,B;
char w[100],r[100];
int abs(int a){return a>0?a:-a;}
int main(){
    int T,n;
    FILE *in = fopen("in.txt","r");
    FILE *out = fopen("output1.txt","w");
    fscanf(in,"%d",&T);
    for(int t=1;t<=T;t++){
        fscanf(in,"%s%s",x,y);
        int k=strlen(x);
        int q=1;
        A.clear();
        B.clear();
        for(int i=0;i<k;i++) q*=10;
        for(int a=0;a<q;a++){
            int c=a;
            w[0]=w[1]=w[2]='0';
            int l=0;
            while(c!=0){
                w[k-1-l]=c%10+48;
                l++;
                c/=10;
            }
            bool ok=true;
            for(int i=0;i<k;i++){
                if(w[i]!=x[i]&&x[i]!='?') ok=false;
            }
            if(ok) {
                A.push_back(a);
            }
            ok=true;
            for(int i=0;i<k;i++){
                if(w[i]!=y[i]&&y[i]!='?') ok=false;
            }
            if(ok) {
                B.push_back(a);
            }
        }
        int min=2147483;
        int a,b;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                int diff=abs(A[i]-B[j]);
                if(diff<min){
                    min = diff;
                    a=A[i];
                    b=B[j];
                }
                else if(diff==min){
                    if(a>A[i]){
                        a=A[i];
                        b=B[j];
                    }
                    else if(a==A[i]&&b>B[j]){
                        a=A[i];
                        b=B[j];
                    }
                }
            }
        }
        printf("%d %d %d\n",a,b,k);
        w[0]=w[1]=w[2]='0';
        int l=0;
        while(a!=0){
            w[k-1-l]=a%10+48;
            l++;
            a/=10;
        }
        w[k]='\0';
        r[0]=r[1]=r[2]='0';
        l=0;
        while(b!=0){
            r[k-1-l]=b%10+48;
            l++;
            b/=10;
        }
        r[k]='\0';
        fprintf(out,"Case #%d: %s %s\n",t,w,r);
    }
}
