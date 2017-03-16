#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int i,j,can,r,r1,c1,c,m,t,cases;
    cin>>t;
    for(cases=1;cases<=t;cases++){
        cout<<"Case #"<<cases<<":"<<endl;
        cin>>r>>c>>m;
        bool b[r][c],a[r][c];
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                b[i][j]=0;
                a[i][j]=0;
            }
        }
        can=m;
        r1=r;
        c1=c;
        while(can>=c1||can>=r1){
            if(r1>c1){
                for(i=0;i<c1;i++){
                    b[r1-1][i]=1;
                }
                can-=c1;
                r1--;
            }
            else{
                for(i=0;i<r1;i++){
                    b[i][c1-1]=1;
                }
                can-=r1;
                c1--;
            }
        }
        if(can>0){
            if(c1>r1){
                for(i=c1-1 ; i>1 && can>0 ; i--, can--){
                    b[r1-1][i]=1;
                }
                r1--;
            }
            else{
                for(i=r1-1 ; i>1 && can>0 ; i--, can--){
                    b[i][c1-1]=1;
                }
                c1--;
            }
            if(can>0){
                b[r1-1][c1-1]=1;
            }
        }
        queue< pair<int, int> > q;
        q.push(make_pair(0,0));
        a[0][0]=1;
        while(!q.empty()){
            pair <int, int> p = q.front();
            q.pop();
            if(!b[p.first][p.second]&&!(p.first==r-1&&p.second==c-1)){
                if(p.second==c-1&&!b[p.first+1][p.second]&&!a[p.first+1][p.second]){
                    q.push(make_pair(p.first+1, p.second));
                    a[p.first+1][p.second]=1;
                }
                if(p.first==r-1&&!b[p.first][p.second+1]&&!a[p.first][p.second+1]){
                    q.push(make_pair(p.first, p.second+1));
                    a[p.first][p.second+1]=1;
                }
                if(p.second<c-1&&p.first<r-1&&!b[p.first+1][p.second+1]&&!b[p.first+1][p.second]&&!b[p.first][p.second+1]){
                    if(!a[p.first+1][p.second]){
                        q.push(make_pair(p.first+1, p.second));
                        a[p.first+1][p.second]=1;
                    }
                    if(!a[p.first][p.second+1]){
                        q.push(make_pair(p.first, p.second+1));
                        a[p.first][p.second+1]=1;
                    }
                    if(!a[p.first+1][p.second+1]){
                        q.push(make_pair(p.first+1, p.second+1));
                        a[p.first+1][p.second+1]=1;
                    }
                }
            }
        }
        bool cosito=true;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cosito=cosito&&((a[i][j]&&!b[i][j])||(!a[i][j]&&b[i][j]));
            }
        }
        if(!cosito){
            cout<<"Impossible"<<endl;
            continue;
        }
        cout<<"c";
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(i==0&&j==0)continue;
                if(b[i][j])
                    cout<<"*";
                else
                    cout<<".";
            }
            cout<<endl;
        }
    }
}
