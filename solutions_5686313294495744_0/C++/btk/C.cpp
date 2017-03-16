#include <bits/stdc++.h>
typedef __int128 INT;
typedef INT Int;

typedef long long LL;
using namespace std;


#define pos(b,k) (1&(b>>k))
void solve(){
    int N;
    cin >> N;
    vector<string> A(N),B(N);
    int res=0;
    for(int i = 0; i < N; i++)cin >> A[i] >> B[i];
    for(int bit = 0; bit < (1<<N); bit++){
        [&](){
        set<string> a,b;
        for(int i = 0; i < N; i++)if(pos(bit,i)==0)a.insert(A[i]);
        for(int i = 0; i < N; i++)if(pos(bit,i)==0)b.insert(B[i]);
        for(int i = 0; i < N; i++)if(pos(bit,i)==1)if(a.count(A[i])==0||b.count(B[i])==0)return;
        res=max(res,(int)__builtin_popcount(bit));
    }();
    }
    cout << res;
}

int main() {
    int T;cin>>T;
    for(int i = 1; i <= T; i++){
        cout<<"Case #"<<i<<": ";
        solve();
        cout << endl;
    }

    return 0;
}
