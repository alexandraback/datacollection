#include<stdio.h>
int srch(int * a, int tmp, int * vis, int n){
    int cnt=0,k;
    for(k=1;k<=n;k++){
        if(vis[k]==1)
            continue;
        if(a[k-1]==tmp){
            vis[k]=1;
            cnt=1+srch(a,k,vis,n);
            vis[k]=0;
        }
    }
    return cnt;
}
int main()
{
    int t,n,i,j,a[11],tmp,k,cnt,vis[11],l,l2,prev;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        cnt=0;
        for(j=1;j<=n;j++){
            for(k=0;k<11;k++)
                vis[k]=0;
            prev=j;
            tmp=a[j-1];
            vis[j]=1;
            l=1;
            while(vis[tmp]==0){
                l++;
                vis[tmp]=1;
                prev=tmp;
                tmp=a[tmp-1];
            }
            if(tmp==j){
                if(l>cnt)
                    cnt=l;
            }
            if(prev==a[tmp-1]){
                l2=srch(a,prev,vis,n);
                l=l+l2;
                if(l>cnt)
                    cnt=l;
            }
            //printf("%d\n",l);
        }
        if(cnt==2)
            cnt=n;
        printf("Case #%d: %d\n",i,cnt);
    }
    return 0;
}


