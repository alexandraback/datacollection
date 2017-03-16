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
        int n;
        cin>>n;
        int arr[1005];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int first = i;
            int curr = i;
            int mp[1005];
            memset(mp, 0, sizeof(mp));
            int temp = 0;
            vector<int> v;
            int index[1005];
            int inc = 0;
            while(true){
                if(mp[curr]==0){
                    v.push_back(curr);
                    index[curr] = inc++;
                }
                mp[curr]++;
                if(mp[curr]>1){
                        int a = arr[curr];
                    if(curr==first)temp = v.size();

                    else if(arr[a]!=curr){
                        if(v.size()<=3) temp = v.size();
                        else    temp = v.size() - 1;
                    }
                    else{
                        temp = v.size();
                        for(int q=1;q<=n;q++){
                            if(arr[q]==a && mp[q]==0){
                                temp++;
                                break;
                            }
                        }
                    }
                    break;
                }
                curr = arr[curr];
            }
            ans=max(ans, temp);
        }
        cout<<"Case #"<<t<<": "<<ans;
        cout<<"\n";
    }
}
int main(){
    FILE *fin = freopen("C-small-attempt1.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("C-small.out", "w", stdout);
    solve();
    return 0;
}
