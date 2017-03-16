#include <bits/stdc++.h>
typedef __int128 INT;
typedef long long LL;
using namespace std;

istream& operator>>(istream& is,INT& x){
    LL _x;is>>_x;x=_x;return is;
}
ostream& operator<<(ostream& os,INT& x){
    os<<(LL)x;return os;
}
void solve(){
    string S;
    cin >> S;
    map<char,int> cnt;
    for(auto& it : S)
        cnt[it]++;
    map<int,int> res;
    if(cnt['Z']>0){
        string t="ZERO";
        int num= res[0] = cnt['Z'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['W']>0){
        string t="TWO";
        int num= res[2] = cnt['W'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['U']>0){
        string t="FOUR";
        int num= res[4] = cnt['U'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['X']>0){
        string t="SIX";
        int num= res[6] = cnt['X'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['G']>0){
        string t="EIGHT";
        int num= res[8] = cnt['G'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['S']>0){
        string t="SEVEN";
        int num= res[7] = cnt['S'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['V']>0){
        string t="FIVE";
        int num= res[5] = cnt['V'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['I']>0){
        string t="NINE";
        int num= res[9] = cnt['I'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['N']>0){
        string t="ONE";
        int num= res[1] = cnt['N'];
        for(auto& it : t)cnt[it]-=num;
    }
    if(cnt['H']>0){
        string t="THREE";
        int num= res[3] = cnt['H'];
        for(auto& it : t)cnt[it]-=num;
    }
    for(auto& it : res)
        for(int i = 0; i < it.second; i++)cout << it.first;
}

int main() {
    int T;cin>>T;
    for(int i = 1; i <= T; i++){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }

    return 0;
}
