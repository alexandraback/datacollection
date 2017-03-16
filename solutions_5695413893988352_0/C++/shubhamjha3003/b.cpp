#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
char a[20],b[20];
int main()
{
    int t,i,j,n,c,power,diff,mindiff,ans[2],k,temp;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%s%s",a,b);
        n=strlen(a);
        power=1;
        mindiff=INT_MAX;
        for(j=0;j<n;j++){
            power*=10;
        }
        for(c=0;c<power;c++){
            temp=c;
            for(k=n-1;k>=0;k--){
                if(a[k]!='?'&&a[k]-'0'!=temp%10)
                    break;
                temp/=10;
            }
            if(k!=-1)
                continue;
            for(j=0;j<power;j++){
                temp=j;
                for(k=n-1;k>=0;k--){
                    if(b[k]!='?'&&b[k]-'0'!=temp%10)
                        break;
                    temp/=10;
                }
                if(k!=-1)
                    continue;
                diff=max(c-j,j-c);
                if(diff<mindiff){
                    mindiff=diff;
                    ans[0]=c;
                    ans[1]=j;
                }
                else if(diff==mindiff){
                    if(ans[0]>c){
                        ans[0]=c;
                        ans[1]=j;
                    }
                    else if(ans[0]==c&&ans[1]>j){
                        ans[1]=j;
                    }
                }
            }
        }
        for(k=n-1;k>=0;k--){
            a[k]='0'+ans[0]%10;
            ans[0]/=10;
        }
        for(k=n-1;k>=0;k--){
            b[k]='0'+ans[1]%10;
            ans[1]/=10;
        }
        printf("Case #%d: %s %s\n",i,a,b);
    }
    return 0;
}
