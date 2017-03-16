#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long ans[500],k;

bool palin(char str[20]){
    long long i,n;
    n=strlen(str);
    for(i=0;i<n;++i){
        if(str[i]!=str[n-i-1]) return false;
    }
    return true;
}

void store()
{
    long long i,j;
    k=0;
    char str[20],str2[20];
    for(i=1;i<=10000000;++i){
        sprintf(str,"%lld",i);
        j=i*i;
        sprintf(str2,"%lld",j);
        if(palin(str) && palin(str2)){
            ans[k++]=j;
        }
    }
}
int main()
{
    long long t,i,j,c;
    long long a,b,cnt;
    freopen("C-large-1.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    store();

    for(c=1;c<=t;++c){
        cnt=0;
        scanf("%lld %lld",&a,&b);
        for(i=0;i<k;++i){
            if(ans[i]>=a && ans[i]<=b) cnt++;
        }
        printf("Case #%lld: %lld\n",c,cnt);
    }
    return 0;
}
