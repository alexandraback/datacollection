#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%I64",&x);
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz size()
#define ln length()
#define all(a) a.begin(),a.end()
#define ESP (1e-9)
#define INF 1000000009LL
#define mod 1000000007
#define vi vector<int>
#define pii pair<int,int>

int chk(int c,int w){
    return c/w;
}
int func(int c,int w){
    int ret =  c/w + w-1;
    if(c%w>0)ret++;
    return ret;
}
void solve(){

int r,c,w;

    cin>>r>>c>>w;
    cout<< (r-1)*chk(c,w) + func(c,w)<<endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    sd(t);
    for(int i = 1; i <= t; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
