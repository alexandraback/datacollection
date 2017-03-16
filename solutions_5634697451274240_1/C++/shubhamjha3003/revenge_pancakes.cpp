#include<cstdio>
int main()
{
    int t,i,ans,j,n;
    char str[200],prev;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%s",str);
        ans=0;
        n=0;
        for(j=0;str[j]!='\0';j++)
            n++;
        prev=str[0];
        for(j=1;j<n;j++){
            if(prev!=str[j]){
                prev=str[j];
                ans++;
            }
        }
        if(prev=='-')
            ans++;
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
