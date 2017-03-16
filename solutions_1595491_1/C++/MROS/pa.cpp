#include<stdio.h>
#include<algorithm>
bool cmp(int x,int y){
    return x>y;
    }
main(){
    freopen("pA.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int u;
    scanf("%d",&u);
    for(int k=0;k<u;k++){
        printf("Case #%d: ",k+1);
        int n,s,p;
        scanf("%d%d%d",&n,&s,&p);
        int a[105];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            }
        std::sort(a,a+n,cmp);
        int ans=0;
        int l1=3*p-2;
        int l2=3*p-4;
        if(p==1){
            l2=1;
            }
        if(p==0){
            l1=0;
            }
        for(int i=0;i<n;i++){
            if(a[i]>=l1){
                ans++;
                }
            else if(a[i]>=l2){
                if(s==0){break;}
                ans++;
                s--;
                }
            else{
                break;
                }
            }
        printf("%d\n",ans);
        }
    }














