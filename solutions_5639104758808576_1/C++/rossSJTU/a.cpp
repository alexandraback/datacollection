#include<stdio.h>
char str[1005];
int main ()
{
    int T,n,sum,ans;
    scanf("%d",&T);
    for(int _=1;_<=T;_++){
        scanf("%d",&n);
        scanf("%s",str);
        sum = ans = 0;
        for(int i = 0;i<=n;i++){
            if(sum<i){
                ans+=i-sum;
                sum =i;
            }
            sum+=str[i]-'0';
        }
        printf("Case #%d: %d\n",_,ans);
    }
    return 0;
}