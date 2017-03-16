#include <iostream>
using namespace std;

int n;
int a[1111][111];
bool c[1111][1111];
int d[1111],p[1111];
bool ans;

void dfs(int x) {
    if (p[x]) return;
    for(int j=1;j<=d[x];j++) {
        dfs(a[x][j]);
        for(int k=1;k<=n;k++) if (c[a[x][j]][k]) {
            if (c[x][k]) ans=true;
            c[x][k]=true;
        }
        if (c[x][a[x][j]]) ans=true;
        c[x][a[x][j]]=true;
    }
    p[x]=1;
}

int main() {
    int TT;
    cin>>TT;
    for(int T=1;T<=TT;T++) {
        ans=false;
        cin>>n;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)  c[i][j]=false;
        for(int i=1;i<=n;i++) d[i]=p[i]=0;
        for(int i=1;i<=n;i++) {
            int j,k;
            cin>>j;
            d[i]=a[i][0]=j;
            while(j--) {
                cin>>k;
                a[i][j+1]=k;
            }
        }
        for(int i=1;i<=n;i++) if (p[i]==0) dfs(i);
        
        cout<<"Case #"<<T<<": "<<(ans?"Yes":"No")<<endl;
    }
    return 0;
}