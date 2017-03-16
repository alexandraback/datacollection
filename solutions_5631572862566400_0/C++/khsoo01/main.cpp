#include<cstdio>
#include<algorithm>
using namespace std;
int tc,n,a[15],ans;
int per[12] = {0,1,2,3,4,5,6,7,8,9};

int solve() {
    int i,j,ret=0;
    for(i=2;i<=n;i++) {
        bool flag = true;
        for(j=1;j<i-1;j++) {
            if(a[per[j]]!=per[j-1] && a[per[j]]!=per[j+1]) {
                flag = false;
                break;
            }
        }
        if(a[per[0]]!=per[1] && a[per[0]]!=per[i-1]) flag = false;
        if(a[per[i-1]]!=per[0] && a[per[i-1]]!=per[i-2]) flag = false;
        if(flag) ret = max(ret,i);
    }
    return ret;
}

int main()
{
    int i,j,q;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&tc);
    for(q=1;q<=tc;q++) {
        scanf("%d",&n);
        for(i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++) per[i] = i+1;
        ans = 0;
        do {
            ans = max(solve(),ans);
        }while(next_permutation(per,per+n));
        printf("Case #%d: %d\n",q,ans);
    }
}
