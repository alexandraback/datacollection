#include<stdio.h>
#include<string.h>
int main()
{
    int t,test,i,ans=0;
    char s[1000]={0};
    int len, x=0;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&test);
    for(t=1;t<=test;t++){
        scanf("%s",s);
        len = strlen(s), ans=0, x=0;
        for(i=len-1;i>=0;i--){
            ans += (( (s[i]=='+')?0:1 ) ^ x);
            x = ( (s[i]=='+')?0:1 );
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
