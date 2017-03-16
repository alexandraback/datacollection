
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LL long long
#define sd(x) scanf("%d", &x)
#define sld(x) scanf("%lld", &x)
#define MOD 1000000007
#define SQ 112345
#define N 1123456
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = A; I <= B; ++I)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>

int solve(){
    int n, i, j, tmp, ans;
    cin>>n;
    string s;
    cin>>s;
    for(i = 0; i < 1010; i++){
        tmp = i + s[0] - '0';
        for(j = 1; j <= n; j++){
            if(tmp >= j){
                tmp += s[j] - '0';
            }
            else break;
        }
        if(j == n + 1){
            return i;
        }
    }
    return 0;
}

int main(){
    freopen("1sin.txt", "r", stdin);
    freopen("1sout.txt", "w", stdout);
    int t = 1, o = 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<o++<<": ";
        cout<<solve()<<endl;
    }
    return 0;
}
