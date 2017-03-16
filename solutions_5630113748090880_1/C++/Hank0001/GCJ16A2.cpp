#include<bits/stdc++.h>
using namespace std;
int cnt[2505];

main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);


    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        printf("Case #%d:",kase);
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<n;j++){
                int x;
                scanf("%d",&x);
                cnt[x]++;
            }
        }
        for(int i=0;i<=2505;i++) if(cnt[i]%2==1) printf(" %d",i);
        printf("\n");
    }
}
