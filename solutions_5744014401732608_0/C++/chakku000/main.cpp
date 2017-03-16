#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF INT_MAX/3
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(v) (v).begin(),(v).end()
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<","<<#y":"<<x<<","<<y<<endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(){
    ll B,M;cin>>B>>M;

    ll mx=1;
    rep(i,B-2) mx *= 2;
    if(M>mx){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;

    vector<vector<int>> ans(B,vi(B,0));
    for(int i=1;i<B;i++){
        for(int j=i+1;j<B;j++) ans[i][j]=1;
    }

    if(M==mx){
        rep(i,B) ans[0][i]=1;
        ans[0][0]=0;
    }else{
        rep(i,B){
            //ans[0][B-2-i]を埋める
            if((M>>i)&1) ans[0][B-2-i]=1;
        }
    }
    rep(i,B){
        rep(j,B) cout << ans[i][j];
        cout << endl;
    }
}

int main(){
    int t;cin>>t;
    rep(i,t){
        printf("Case #%d: ",i+1);
        solve();
    }
}
