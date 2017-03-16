#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int a[21000];
int idx[21000];
int st[21000],top;
int main()
{
    freopen("2.in","r",stdin);
    freopen("21.out","w",stdout);
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        int e,r,n;
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        LL ans=0;
        top=0;
        for(int i=n-1;i>=0;i--){
            while(top&&a[i]>=a[st[top-1]]) top--;
            if(top==0) idx[i]=-1;
            else idx[i]=st[top-1];
            st[top++]=i;
        }
//        for(int i=0;i<n;i++) printf("%d ",idx[i]);
//        puts("");
        LL cur=e;
        for(int i=0;i<n;i++){
            if(idx[i]==-1) {
                ans+=cur*a[i];
                cur=min(r,e);
            }
            else {
                LL add=(idx[i]-i)*r;
                LL v=min(cur,max(cur+add-e,0LL));
                ans+=v*a[i];
                cur=min((LL)e,cur-v+r);
            }
        }
        cout << "Case #" << ++ca << ": " << ans << endl;

    }
}
