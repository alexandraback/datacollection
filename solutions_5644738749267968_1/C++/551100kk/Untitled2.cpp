#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<double> A,B,a,b;
int main(){
    freopen("D-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,m,i,j,c=0;
    double x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        A.clear(),B.clear();
        for(i=0;i<n;i++){
            scanf("%lf",&x);
            A.push_back(x);
        }
        for(i=0;i<n;i++){
            scanf("%lf",&x);
            B.push_back(x);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        printf("Case #%d: ",++c);
        int ans=0,id=0;
        a=A,b=B;
        for(i=0;i<n;i++){
            int flag=1;
            for(j=i;j<n;j++){
                if(a[j]<b[j-i])
                    flag=0;
            }
            if(flag){
                ans=n-i;
                break;
            }
        }
        printf("%d",ans);
        a=A,b=B;
        ans=0,id=0;
        for(i=0;i<n && id<n;i++,id++){
            while(id<n && b[id]<a[i]){
                id++;
                ans++;
            }
        }
        printf(" %d\n",ans);
    }
}
