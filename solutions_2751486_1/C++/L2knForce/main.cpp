#include <cstdio>

bool isconsonant(char in){
    if(in=='a' || in=='e' || in=='i' || in=='o' || in=='u')
        return false;
    return true;
}

    char string[1000000];

int mainrun(){
    long long strlen,n,ans=0;
    long long lastcon,concount;
    scanf("%s",string);
    scanf("%lld",&n);
    for(strlen=0;string[strlen];strlen++);
    lastcon=-1;
    concount=0;
    for(long long c=0;c<strlen;c++){
        if(isconsonant(string[c]))
            concount++;
        else concount=0;
        if(concount>=n){
            ans+=(c-n+1-lastcon)*(strlen-c);
            lastcon=c-n+1;
        }
        //printf("%c lc%d c%d cc%d a%d\n",string[c],lastcon,c,concount,ans);
    }
    printf("%lld\n",ans);
    return 0;
}

int main(){
    freopen("tt.in","r",stdin);
    freopen("tt.out","w",stdout);
    int total;
    scanf("%d",&total);
    for(int c=1;c<=total;c++){
        printf("Case #%d: ",c);
        mainrun();
    }
    return 0;
}
