#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int a[110][110],b[110][110];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1;tt<=T;tt++){
        printf("Case #%d: ",tt);
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%d",&a[i][j]);
        memset(b,0,sizeof(b));
        for (int k=1; k<=100; k++){
            for (int i=0; i<n; i++){
                int ff=1;
                for (int j=0; j<m; j++)
                if (a[i][j]==k||(b[i][j]&&a[i][j]<=k)){} else {
                    ff=0; break;
                }
                if (ff) for (int j=0; j<m; j++)
                b[i][j]=1;
            }
            for (int i=0; i<m; i++){
                int ff=1;
                for (int j=0; j<n; j++)
                if (a[j][i]==k||(b[j][i]&&a[j][i]<=k)){} else {
                    ff=0; break;
                }
                if (ff) for (int j=0; j<n; j++)
                b[j][i]=1;
            }
            int ff=1;
            for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            if (a[i][j]==k&&!b[i][j]) ff=0;
            if (!ff) break;
        }
        int ff=1;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            if (!b[i][j]) ff=0;
        if (ff) puts("YES"); else puts("NO");
    }
}
