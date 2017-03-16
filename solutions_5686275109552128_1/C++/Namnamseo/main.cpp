#include <cstdio>
#include <set>

using namespace std;

int data[1010];

int max(int a,int b) { return a>b?a:b; }
int min(int a,int b) { return a<b?a:b; }

int main()
{
    freopen("D:\\input","r",stdin);
    freopen("D:\\output","w",stdout);
    int t;
    scanf("%d",&t);
    int n,i,j,tmp,ans;
    for(int _=1;_<=t;++_){
        scanf("%d",&n);
        for(i=0;i<n;++i) scanf("%d",data+i);
        ans=2e9;
        for(j=1;j<=1000;++j){
            tmp=0;
            for(i=0;i<n;++i) tmp+=(data[i]-1)/j;
            ans=min(ans,tmp+j);
        }
        printf("Case #%d: %d\n",_,ans);
    }
    return 0;
}
