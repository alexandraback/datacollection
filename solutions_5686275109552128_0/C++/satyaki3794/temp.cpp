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
typedef pair<ii, int> iii;
 
 
// #define matrix vector<vector<ll> >
// matrix identityMatrix;
// matrix mul(const matrix &a,const matrix &b)
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
//     tmp=mul(tmp,tmp);
//     if(n&1)
//       tmp=mul(a,tmp);
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


int n, arr[1005];


int func(int ops){

    //fix number of eating seconds

    int ans = ops;
    for(int i=0;i<n;i++){

        if(arr[i] <= ops)   continue;

        int temp = arr[i] - ops;
        ans += ceil((double)temp / ops);
    }

    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);

    freopen("B-small-attempt2.in", "r", stdin);
    // freopen("sub-4.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test, x = 1;
    cin>>test;
    while(test--){

        cout<<"Case #"<<x++<<": ";

        cin>>n;
        for(int i=0;i<n;i++)    cin>>arr[i];

        int maxi = *max_element(arr, arr+n);

        int ans = maxi+10;
        for(int i=1;i<=maxi;i++)
            ans = min(ans, func(i));

        cout<<ans<<endl;
    }

    return 0;
}




