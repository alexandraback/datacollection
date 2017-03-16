#include <stdio.h>
#include "stdlib.h"

int a[1100],n,w[1100];

int findcircle(int k,int c){
    w[k]=c;
    if (w[a[k]])
        return c+1-w[a[k]];
    else
        return findcircle(a[k],c+1);
}

int findep(int k){
    int dep=0;
    w[k]=1;
    for (int i=0;i<n;i++){
        if (w[i]==0&&a[i]==k){
            int tmp=findep(i);
            if (tmp>dep)
                dep=tmp;
        }
    }
    return dep+1;
}

int main() {
    freopen("C-small-attempt1.in-2.txt", "r", stdin);
    freopen("C-small-attempt1.out.txt", "w", stdout);

    int t,tt;
    scanf("%d",&tt);
    int ans;
    for (t=1;t<=tt;t++){
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d",a+i);
            a[i]--;
            w[i]=0;
        }
        ans=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
                w[j]=0;
            int j=findcircle(i,1);
            if (j>ans)
                ans=j;
        }
        for (int i=0;i<n;i++)
            w[i]=0;
        int cou=0;
        for (int i=0;i<n;i++){
            if (a[a[i]]==i&&a[i]>i){
                w[i]=1;
                w[a[i]]=1;
                cou+=findep(i)+findep(a[i]);
            }
        }
        if (cou>ans)
            ans=cou;
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
