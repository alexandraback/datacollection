#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

const int maxn = 100005;

bool vis[10];

int main(){
    freopen("A-small.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,n;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        scanf("%d",&n);
        printf("Case #%d: ",kase);
        if (!n){
            puts("INSOMNIA");
            continue;
        }
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for (int i=n;;i+=n){
            int j=i;
            while(j){
                if (!vis[j%10]){
                    vis[j%10]=true;
                    cnt++;
                }
                j/=10;
            }
            if (cnt==10){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
