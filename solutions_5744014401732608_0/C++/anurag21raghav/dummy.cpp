#include<bits/stdc++.h>
using namespace std;
#define test int t;scanf("%d", &t);while(t--)
#define sd(n) scanf("%d", &n)
#define pd(n) printf("%d", n)
#define fl(i, n) for(int i=0;i<n;i++)
#define MOD 1000000007
int fact[5001];
int invfact[5001];
int inv(int a, int b){
    if(b==0)
        return 1;
    if(b&1)
        return (long long)a*inv(a, b-1)%MOD;
    else{
        int res = inv(a, b>>1);
        return (long long)res*res%MOD;
    }
}
void init(){
    fact[0] = 1;
    for(int i=1;i<5001;i++){
        fact[i] = (long long)fact[i-1]*i%MOD;
    }
    invfact[5000] = inv(fact[5000], MOD-2);
    for(int i=5000;i>0;i--){
        invfact[i-1] = (long long)invfact[i]*i%MOD;
    }
}
int C(int n, int r){
    if(r>n || r<0)
        return 0;
    return (long long)((long long)fact[n]*invfact[r]%MOD)*invfact[n-r]%MOD;
}
void solve(){
    int T;
    sd(T);
    for(int t=1;t<=T;t++){
            int b;
        long long m;
    cin>>b>>m;
        long long ways = pow(2, b-2);
        if(m>ways){
            cout<<"Case #"<<t<<": IMPOSSIBLE"<<"\n";
            continue;
        }
        cout<<"Case #"<<t<<": POSSIBLE"<<"\n";
        int cnt=0;
        int arr[55][55];
        for(int i=0;i<55;i++){
            for(int j=0;j<55;j++){
                arr[i][j] = 0;
            }
        }
        int flag = 0;
        for(int i=0;i<b;i++){
            for(int j=0;j<b;j++){
                if(j>i){
                    if(cnt<m && cnt<b-1){
                        arr[i][j] = 1;
                        arr[b-j-1][b-i-1] = 1;
                        cnt++;
                    }
                    else if(cnt<m){
                        arr[i][j] = 1;
                        cnt++;
                    }
                    else    flag = 1;
                }
            }
            if(flag)    break;
        }
        for(int i=0;i<b;i++){
            arr[b-1][i] = 0;
        }
        if(m==ways-1){
            arr[0][b] = 0;
        }
        for(int i=0;i<b;i++){
            for(int j=0;j<b;j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
    }
}
int main(){
    FILE *fin = freopen("B-small-attempt1.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("B-small.out", "w", stdout);
    solve();
    return 0;
}
