#include<stdio.h>
int main() {
    int fair[]={1,4,9,121,484};
    int t,a,b,i,c=0,ans;
    scanf("%d",&t);
    while(t--) {
               scanf("%d%d",&a,&b);
               ans=0;
               for(i=0;i<5;i++)
                               if(a<=fair[i] && fair[i]<=b) ans++;
               printf("Case #%d: %d\n",++c,ans);
    }
    return 0;
}
