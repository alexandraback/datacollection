#include<iostream>
#include<vector>
using namespace std;

int mat[1005][1005];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("data.out","w",stdout);
    
    int t;
    cin>>t;
    int ca;
    for(ca=1;ca<=t;ca++){
        int n;
        cin>>n;
        int i,j;
        int m,c;
        memset(mat,0,sizeof(mat));
        for(i=1;i<=n;i++){
           cin>>m;
           for(j=0;j<m;j++){
              cin>>c;
              mat[i][c]=1;
           }
        }
        int k;
        for(k=1;k<=n;k++)
          for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
               if(mat[i][k]&&mat[k][j])
                  mat[i][j]+=1;
        int res=0;
        for(i=1;i<=n&&res==0;i++)
          for(j=1;j<=n&&res==0;j++)
             if(mat[i][j]>=2){res=1;}
        if(res) printf("Case #%d: Yes\n",ca);
        else printf("Case #%d: No\n",ca);
    }
}
