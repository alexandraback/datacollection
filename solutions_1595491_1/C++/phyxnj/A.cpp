#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[200];
int t,n,s,p,ca=0;
int ck(int v)
{
    if(v%3==0){
        if(v/3>=p) return 2;
        if(v>=3&&(v+3)/3>=p) return 1;
    }
    else if(v%3==1){
        if((v+2)/3>=p) return 2;
        if(v>=4&&(v+2)/3>=p) return 1;
    }
    else {
        if((v+1)/3>=p) return 2;
        if(v>=2&&(v+4)/3>=p) return 1;
    }
    return 0;
}
int main()
{
    freopen("3.in","r",stdin);
    freopen("1.out","w",stdout);
   scanf("%d",&t);
   while(t--){
       scanf("%d%d%d",&n,&s,&p);
       int ans=0,c2=0;
       for(int i=0;i<n;i++){
           int k;
           scanf("%d",&k);
           int m=ck(k);
           if(m==2) ans++;
           else if(m==1) c2++;
       }
       ans+=min(c2,s);
       printf("Case #%d: %d\n",++ca,ans);
   }


}
