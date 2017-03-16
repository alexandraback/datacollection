//satyaki3794
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cctype>
#include <cassert>
#include <bitset>
#include <iomanip>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define PI (3.14159265)
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define INF (100000005)
#define SIZE (2)
#define TREESIZE (302144)
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define epsilon 1e-8 //add to double before casting to integer

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> pli;


#define matrix vector< vector<ll> >

matrix matmul(matrix &a, matrix &b){
    int i, j, k, n = a.size();
    matrix ans (n, vector<ll>(n));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            ll temp = 0;
            for(k=0;k<n;k++)    temp = (temp + a[i][k] * b[k][j]) % MOD;
            ans[i][j] = temp;
        }
    return ans;
}

matrix matpwr(matrix &a, ll p){
    int n = a.size();
    matrix ans(n, vector<ll> (n));
    for(int i=0;i<n;i++)    ans[i][i] = 1;

    while(p){
        if(p&1) ans = matmul(ans, a);

        a = matmul(a, a);
        p >>= 1;
    }
    return ans;
}


ll pwr(ll base, ll p, ll mod = MOD){
    ll ans = 1;
    while(p){
        if(p & 1)   ans = (ans * base) % mod;
        base = (base * base) % mod;
        p /= 2;
    }
    return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


ll lcm(ll a, ll b){
    return (a*b) / gcd(a, b);
}


ll invMod(ll n, ll mod = MOD){
    return pwr(n, mod-2, mod);
}



int J, P, S, K;
int cnt_JP[12][12], cnt_JS[12][12], cnt_PS[12][12];
bool done[12][12][12];
vector<iii> ans, storage;


void backtrack(){
    bool no_change = true;
    for(int j=1;j<=J;j++)
        for(int p=1;p<=P;p++)
            for(int s=1;s<=S;s++){
                if(done[j][p][s])   continue;
                if(cnt_PS[p][s]==0 || cnt_JS[j][s]==0 || cnt_JP[j][p]==0)   continue;
                cnt_JP[j][p]--;
                cnt_JS[j][s]--;
                cnt_PS[p][s]--;
                done[j][p][s] = true;
                storage.pb(iii (j, ii (p, s)));
                no_change = false;
                backtrack();
                cnt_JP[j][p]++;
                cnt_JS[j][s]++;
                cnt_PS[p][s]++;
                storage.pop_back();
            }
    if(no_change){
        if(storage.size() > ans.size()){
            ans = storage;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);

    freopen("C-small-attempt5.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
// t=1;
    while(t--){

        cout<<"Case #"<<x++<<": ";
        cin>>J>>P>>S>>K;

        if(K >= S){
            cout<<J*P*S<<endl;
            for(int j=1;j<=J;j++)
                for(int p=1;p<=P;p++)
                    for(int s=1;s<=S;s++)
                        cout<<j<<" "<<p<<" "<<s<<endl;
            continue;
        }

        memset(done, 0, sizeof(done));
        for(int j=1;j<=J;j++)
            for(int p=1;p<=P;p++)
                for(int s=1;s<=S;s++)
                    cnt_JS[j][s] = cnt_PS[p][s] = cnt_JP[j][p] = K;

        ans.clear();
        storage.clear();
        backtrack();

        cout<<ans.size()<<endl;
        for(int i=0;i<(int)ans.size();i++)
            cout<<ans[i].ff<<" "<<ans[i].ss.ff<<" "<<ans[i].ss.ss<<endl;
    }

    return 0;
}










