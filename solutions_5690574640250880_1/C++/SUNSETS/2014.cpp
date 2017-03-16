#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool vis[55][55];
int n, m, num;
bool work(int x1, int y1, int x2, int y2) {
    if(x1==1||y1==1||x2==1||y2==1) return false;
    int sum = x1*m+(x2-x1)*y2+(n-x2)*y1;
    return sum==num;
}
bool work2(int x1, int y1, int x2, int y2) {
    if(x1==1||y1==1||x2==1||y2==1) return false;
    int sum = x1*y2+(x2-x1)*y1;
    return sum==num;
}
int main() {
    //freopen("in.txt", "r", stdin);
    freopen("C-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin>>T;
    for(int cas=1; cas<=T; ++cas) {
        memset(vis, false, sizeof(vis));
        cin>>n>>m>>num;
        num = n*m-num;

        cout<<"Case #"<<cas<<":"<<endl;
        if(num == 1) {
            for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                    if(i==0&&j==0) cout<<'c';
                    else cout<<'*';
                }
                cout<<endl;
            }
            continue;
        }
        bool ok = false;
        for(int x1=0; x1<=n&&ok==false; ++x1)
        for(int x2=x1; x2<=n&&ok==false; ++x2)
        for(int y1=0; y1<=m&&ok==false; ++y1)
        for(int y2=y1; y2<=m&&ok==false; ++y2) {
            int s = 0;
            ok |= work(x1, y1, x2, y2);
            if(ok) {
                for(int i=0; i<n; ++i) {
                    int r;
                    if(i<x1) r=m;
                    else if(i<x2) r=y2;
                    else r=y1;
                    for(int j=0; j<r; ++j) vis[i][j] = true;
                }
                 //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
                break;
            }
            ok |= work2(x1, y1, x2, y2);
            if(ok) {
                for(int i=0; i<n; ++i) {
                    int r;
                    if(i<x1) r=y2;
                    else if(i<x2) r=y1;
                    else r=0;
                    for(int j=0; j<r; ++j) vis[i][j] = true;
                }
                // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
                break;
            }
        }
        if(m>1&&num!=1)
        for(int i=0; i<n; ++i)
            if(vis[i][0]==true&&vis[i][1]==false) ok=false;
        if(n>1&&num!=1)
        for(int i=0; i<m; ++i)
            if(vis[0][i]==true&&vis[1][i]==false) ok=false;
        if(ok){
            for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                    if(i==0&&j==0) cout<<'c';
                    else if(vis[i][j]) cout<<'.';
                    else cout<<'*';
                }
                cout<<endl;
            }
        }
        else cout<<"Impossible"<<endl;
    }
    return 0;
}

