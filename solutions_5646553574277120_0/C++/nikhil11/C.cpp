#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    // freopen("C.txt","r",stdin);
    freopen("Input.txt","r",stdin);
    freopen("Output2.txt","w",stdout);
    int T,C,D,V,i,a,b,c,d,e,count,K;
    scanf("%d",&T);
    for(K=1;K<=T;K++) {
        scanf("%d%d%d",&C,&D,&V);
        int A[D];
        count=0;
        for(i=0;i<D;i++) {
            scanf("%d",&A[i]);
        }
        int hash[200];
        for(i=0;i<200;i++) {
            hash[i]=0;
        }
        if(D==1) {
            hash[A[0]]=1;
        } else if(D==2) {
            a=A[0];
            b=A[1];
            hash[a]=1;
            hash[b]=1;
            hash[a+b]=1;
        } else if(D==3) {
            a=A[0];
            b=A[1];
            c=A[2];
            hash[a]=1;
            hash[b]=1;
            hash[c]=1;
            hash[a+b]=1;
            hash[a+c]=1;
            hash[c+b]=1;
            hash[a+b+c]=1;
        } else if(D==4) {
            a=A[0];
            b=A[1];
            c=A[2];
            d=A[3];
            hash[a]=1;
            hash[b]=1;
            hash[c]=1;
            hash[d]=1;
            hash[a+b]=1;
            hash[a+c]=1;
            hash[c+b]=1;
            hash[a+d]=1;
            hash[b+d]=1;
            hash[c+d]=1;
            hash[a+b+c]=1;
            hash[a+b+d]=1;
            hash[a+c+d]=1;
            hash[b+c+d]=1;
            hash[a+b+c+d]=1;
        } else {
            a=A[0];
            b=A[1];
            c=A[2];
            d=A[3];
            e=A[4];
            hash[a]=1;
            hash[b]=1;
            hash[c]=1;
            hash[d]=1;
            hash[e]=1;
            hash[a+b]=1;
            hash[a+c]=1;
            hash[c+b]=1;
            hash[a+d]=1;
            hash[b+d]=1;
            hash[c+d]=1;
            hash[a+e]=1;
            hash[b+e]=1;
            hash[c+e]=1;
            hash[d+e]=1;
            hash[a+b+c]=1;
            hash[a+b+d]=1;
            hash[a+c+d]=1;
            hash[b+c+d]=1;
            hash[a+b+e]=1;
            hash[a+c+e]=1;
            hash[a+d+e]=1;
            hash[b+c+e]=1;
            hash[b+d+e]=1;
            hash[c+d+e]=1;
            hash[a+b+c+d]=1;
            hash[e+b+c+d]=1;
            hash[a+b+e+d]=1;
            hash[a+b+c+e]=1;
            hash[a+b+c+d+e]=1;
        }
        for(i=1;i<=V;i++) {
            if(hash[i]==1) {
                count++;
            }
        }
        printf("Case #%d: %d\n",K,V-count);
    }
    return 0;
}
