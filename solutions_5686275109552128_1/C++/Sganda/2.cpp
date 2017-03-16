
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

int a[1010];

int dod(int v, int d){
    int bv = 0;
    if(v % d) bv = 1;
    return (v / d + bv - 1);
}

int get(int x, int n){
    int ans = 0, i;
    for(i = 1; i <= n; i++){
        if(a[i] > x){
            ans += dod(a[i], x);
        }
    }
    return ans;
}

int solve(){
    int n, i;
    cin>>n;
    for(i = 1; i <= n; i++){
        cin>>a[i];
    }
    int ans = 1010, tmp;
    for(i = 1; i <= 1010; i++){
        tmp = i;
        tmp += get(i, n);
        ans = min(ans, tmp);
    }
    return ans;
}

int main(){
    freopen("2lin.txt", "r", stdin);
    freopen("2lout.txt", "w", stdout);
    int t = 1, o = 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<o++<<": ";
        cout<<solve()<<endl;
    }
    return 0;
}
