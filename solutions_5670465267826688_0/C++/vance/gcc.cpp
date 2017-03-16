#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
int mul(int a, int b){
    if(a<0)
        return -mul(-a,b);
    if(b<0)
        return -mul(a,-b);
    if(a == 1)
        return b;
    if(b == 1)
        return a;
    if(a == b)
        return -1;
    if(a == 'i' && b == 'j')
        return 'k';
    else if(a == 'i' && b == 'k')
        return -1*'j';
    else if(a == 'j' && b == 'k')
        return 'i';
    return -mul(b,a);
}
int qm(int a, LL n){
    int ret = 1;
    while(n){
        if(n&1){
            ret = mul(ret,a);
        }
        n>>=1;
        a= mul(a,a);
    }
    return ret;
}
int main()
{
    int t,n,i,j,k;
    LL x;
    string in;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    for(int cnt=1;cnt<=t;cnt++)
    {
        scanf("%d%lld",&n,&x);
        cin>>in;
        int ret = 1;
        for(i=0;i<n;i++)
            ret = mul(ret, in[i]);
        //printf("%d\n",qm(ret,x));
        //cout<<in<<endl;
        if(n*x < 3ll || qm(ret, x)!= -1){
            printf("Case #%d: NO\n",cnt);
            continue;
        }
        x = x%20;
        string y = "";
        for(i=0;i<x;i++)
            y+=in;
        int iret = 1;
        for(i=0;i<y.size();i++){
            iret = mul(iret, y[i]);
            if(iret == 'i'){
                break;
            }
        }
        int kret = 1;
        for(j=y.size()-1;j>=0;j--){
            kret = mul(y[j], kret);
            if(kret == 'k'){
                break;
            }
        }
        if(j > i+1){
            printf("Case #%d: YES\n",cnt);
        }else{
            printf("Case #%d: NO\n",cnt);
        }
    }
    return 0;
}
