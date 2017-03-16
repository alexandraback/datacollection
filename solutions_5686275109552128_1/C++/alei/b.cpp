#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;

int d[1234];
int main(){
    freopen("bl.in","r",stdin);
    freopen("bl.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",d+i);

        int ans=1e3,bet;
        for(int s=1;s<1234;s++){
            bet=s;
            for(int i=0;i<n;i++){
                int q=d[i]/s;
                if(d[i]%s!=0)q++;
                bet+=q-1;
            }
            if(bet<ans)ans=bet;
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
