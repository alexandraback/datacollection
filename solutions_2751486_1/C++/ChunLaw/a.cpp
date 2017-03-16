#include <cstdio>
#include <cstring>

char s[1000005];
int pre_con[1000005];
int T,n;
long long ans=0,lt=0;

int consonants(char c){
    return (c!='a') && (c!='e') && (c!='i') && (c!='o') && (c!='u');
}
    

int main(){
    scanf("%d",&T);
    for (int t=1;t<=T;++t){
        scanf(" %s %d",s,&n);
        ans=0;
        lt=0;
        int l=strlen(s);
        memset(pre_con,0,sizeof pre_con);
        pre_con[0]=0;
        int pre=0;
        for (int i=0;i<l;++i){
            pre_con[i+1] = (consonants(s[i])?pre_con[i]+1:0);
//            printf("%d %d\n",i,pre_con[i+1]);
            if (pre_con[i+1]>=n){
               ans += (i+2-n)*(l-i)-(pre*(l-i));
               pre = (i+2-n);
            }
        }
        printf("Case #%d: %lld\n",t,ans);
    }
}
