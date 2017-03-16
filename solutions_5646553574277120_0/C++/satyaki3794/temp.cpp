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
typedef pair<ll, ll> ii;
typedef pair<ii, int> iii;
 
 
// #define matrix vector<vector<ll> >
// matrix identityMatrix;
// matrix matmul(const matrix &a,const matrix &b)
// {
//   int n=a.size();
//   matrix ans(n,vector<ll> (n, 0) );
//   for (int i = 0; i < n; ++i)
//   {
//     for (int j = 0; j < n; ++j)
//     {
//       for (int k = 0; k < n; ++k)
//       {
//         ans[i][j]+= ((long long)a[i][k]*b[k][j])%MOD;
//         ans[i][j]%=MOD;
//       }
//     }
//   }
//   return ans;
// }
 
 
// matrix matpwr(const matrix &a,long long n)
// {
//     if(n==0)
//     {
//       /*define identity */
//       assert(false);
//       return identityMatrix;
//     }
//     if(n==1)
//      return a;
//     matrix tmp=matpwr(a,n/2);
//     tmp=matmul(tmp,tmp);
//     if(n&1)
//       tmp=matmul(a,tmp);
//     return tmp;
// }
 
 
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
 
 
ll invMod(ll n){
    return pwr(n, MOD-2);
}



int c, d, v, arr[6];
bool already[35], DP[35];


int func(){

// cout<<v<<" "<<fixed<<endl;

    memset(DP, 0, sizeof(DP));
    DP[0] = true;
    for(int j=1;j<=v;j++){

        if(!already[j]) continue;
        for(int i=v;i>=1;i--)
            if(i-j >= 0 && DP[i-j]) DP[i] = true;
    }

    int ans = 0;
    while(1){

        int lo = -1;
        for(int j=1;j<=v;j++)
            if(!DP[j]){
                lo = j; break;
            }

// for(int i=1;i<=v;i++)cout<<DP[i]<<" ";cout<<" so "<<lo<<endl;

        if(lo == -1)    break;

        ans++;
        for(int i=v;i>=1;i--)
            if(i-lo >= 0 && DP[i-lo])   DP[i] = true;
    }

    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);


    freopen("C-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
    while(t--){

        cout<<"Case #"<<x++<<": ";

        cin>>c>>d>>v;

        memset(already, 0, sizeof(already));
        for(int i=0;i<d;i++){
            cin>>arr[i];
            already[arr[i]] = true;
        }
        sort(arr, arr+d);

// cout<<func(3)<<endl;

        int ans = func();
        cout<<ans<<endl;
    }

    return 0;
}

















