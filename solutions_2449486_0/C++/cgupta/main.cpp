#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int a[105][105],row[105],col[105];

int main()
{
    int t,i,j,k,ans,n,m;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&t);
    for(k=1;k<=t;++k){

        scanf("%d %d",&n,&m);
        ans=0;

        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                scanf("%d",&a[i][j]);
            }
        }

        for(i=0;i<n;++i){
            row[i]=INT_MIN;
            for(j=0;j<m;++j){
                row[i]=max(row[i],a[i][j]);
            }
        }

        for(i=0;i<m;++i){
            col[i]=INT_MIN;
            for(j=0;j<n;++j){
                col[i]=max(col[i],a[j][i]);
            }
        }

        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                if(a[i][j]<row[i] && a[i][j]<col[j]){
                    ans=1;
                    break;
                }
            }
        }

        if(ans==0){
            printf("Case #%d: YES\n",k);
        }else{
            printf("Case #%d: NO\n",k);
        }

    }
    return 0;
}
