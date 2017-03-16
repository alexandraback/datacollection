#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define ll long long
ll reverse(ll a){
    ll ret = 0;
    while(a) ret*=10,ret+=a%10,a/=10;
    return ret;
}

#define SZ 10000000
int ans[SZ];
void dpf(){
    ans[1] = 1;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int cur = q.front();q.pop();
        int a = cur + 1;
        int b = reverse(cur);

        if(a < SZ && !ans[a]){
            ans[a] = ans[cur] + 1;
            q.push(a);
        }

        if(b < SZ && !ans[b]){
            ans[b] = ans[cur] + 1;
            q.push(b);
        }
    }
    /*
    for(int i = 1 ; i < 2000; i++) {
        int x = i+1;
        while(x < SZ && (ans[x]-1 == ans[x-1])) x++;
        x--;
        cout<<"( "<<i<<' '<<x<<") {"<<ans[i]<<"} len = "<<x-i+1<<endl;
        i=x;
    }*/
}


ll fastans(ll ans){
    if(ans <=20) return 20;
}
#include<cstdio>
int main(){
    freopen("C:\\a.txt","r",stdin);
    freopen("C:\\w.txt","w",stdout);

    dpf();

    int t;cin>>t;
    for(int i = 1; i <= t; i++){
        int x;cin>>x;
        cout<<"Case #"<<i<<": "<<ans[x]<<endl;
    }



    return 0;
}
