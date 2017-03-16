#include <cstdio>
#include <cstring>

int pali(long long a){
    char s[20];
    sprintf(s,"%lld",a);
    int len=strlen(s);
    for(int i=0;i+i<len;i++)if(s[i]!=s[len-i-1])return 0;
    return 1;
}

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    long long p[50];
    int count=0;
    for(long long i=1;i<10000000;i++){
        long long s=i*i;
        if(pali(i) && pali(s)){
            p[count++]=s;
        }
    }

    int ncase;
    scanf("%d",&ncase);
    for(int C=1;C<=ncase;C++){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        int ans=0;
        for(int i=0;i<count;i++)if(p[i]>=a && p[i]<=b)ans++;
        printf("Case #%d: %d\n",C,ans);
    }
    return 0;
}