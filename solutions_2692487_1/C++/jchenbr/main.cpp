#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100+5;
int a[N],now,n,cost,ans;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int total,tt;
    cin>>total;
    for (int tt=1;tt<=total;tt++){
        cin>>now>> n;
        //cout<<n<<","<<now<<endl;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        ans=n;
        cost=0;
        
        for (int i=1;now>1&&i<=n;i++){
            while (now<=a[i]){
                now+=now-1;
                cost+=1;
            }
            now+=a[i];
            if (n-i+cost<ans)
                ans=n-i+cost;
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}