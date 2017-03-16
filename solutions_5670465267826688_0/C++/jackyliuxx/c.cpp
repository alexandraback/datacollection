#include<bits/stdc++.h>
using namespace std;

int cc(int a,int b){
    if(a==1)
        return b;
    if(b==1)
        return a;
    if(a<0)
        return -cc(-a,b);
    if(b<0)
        return -cc(a,-b);
    if(a==b)
        return -1;
    if(a==2 && b==3)
        return 4;
    if(a==3 && b==2)
        return -4;
    if(a==3 && b==4)
        return 2;
    if(a==4 && b==3)
        return -2;
    if(a==4 && b==2)
        return 3;
    if(a==2 && b==4)
        return -3;
    return 0;
}

int ccpow(int a,long long b){
    int r=1;
    while(b){
        if(b&1)
            r=cc(r,a);
        a=cc(a,a);
        b/=2;
    }
    return r;
}

int main(){
    int t,tk=1;
    scanf("%d",&t);
    while(t--){
        int l;
        long long x;
        char s[11000];
        int a[11000];
        scanf("%d%lld",&l,&x);
        scanf("%s",s);
        for(int i=0;i<l;i++){
            if(s[i]=='i')
                a[i]=2;
            if(s[i]=='j')
                a[i]=3;
            if(s[i]=='k')
                a[i]=4;
        }
        int a1=1;
        for(int i=0;i<l;i++){
            a1=cc(a1,a[i]);
        }
        if(ccpow(a1,x)!=-1){
            printf("Case #%d: NO\n",tk++);
            continue;
        }
        long long ct=0;
        int ac=0;
        for(int need=2;need<5;need++){
            int nw=1;
            while(ct<x*l){
                nw = cc(nw,a[ct%l]);
                ct++;
                if(nw==need){
                    if(need==4){
                        if(ct%l==0)
                            ac=1;
                    }
                    else
                        break;
                }
            }
        }
        if(ac && pow(a1,x-ct/l)==1)
            printf("Case #%d: YES\n",tk++);
        else
            printf("Case #%d: NO\n",tk++);
    }
}
