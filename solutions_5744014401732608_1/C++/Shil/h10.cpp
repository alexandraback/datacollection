// There is nothing in a caterpillar that tells you its going to be a butterfly!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
int P[50];
char G[100][100];
ll pw[100];
int main(){
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    int cur=1;
    cin >> T;
    while(T--){
        ll B,M;
        cin >> B >> M;
        ll maxp=1;
        ll curp=1;
        for(int i=2;i<B;i++){
            maxp+=curp;
            curp*=2;
        }
        if(maxp<M){
           cout<<"Case #"<<cur<<": IMPOSSIBLE\n";
           cur++;
           continue;
        }
        cout<<"Case #"<<cur<<": POSSIBLE\n";
        rep(i,B+2){
            rep(j,B+2){
                G[i][j]='0';
            }
        }
        curp=1;
        pw[1]=1;
        for(int i=2;i<B;i++){
            for(int j=1;j<i;j++){
                G[j][i]='1';
            }
            pw[i]=curp;
            curp*=2;
        }
        for(int i=B-1;i>=1;i--){
            if(M>=pw[i]){
                M-=pw[i];
                G[i][B]='1';
            }
        }
        rep(i,B){
            rep(j,B){
                cout<<G[i+1][j+1];
            }
            cout<<"\n";
        }
        cur++;
    }
}
