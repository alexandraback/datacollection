#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int solve(){
    int n;
    string s;
    cin>>n>>s;
    int cnt = 0;
    int toAdd = 0;
    for(int i = 0; i < s.size(); ++i){
        if(cnt < i){
            toAdd += i - cnt;
            cnt = i;
        }
        if(cnt >= i){
            cnt += s[i] - '0';
        }
    }
    return toAdd;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        int t = solve();
        cout<<"Case #"<<i<<": "<<t<<"\n";
    }

    return 0;
}
