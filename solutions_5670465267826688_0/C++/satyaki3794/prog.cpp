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


int n, arr[10005];
string s;
bool k[10005], jk[10005];


int getInt(char ch){

    if(ch == 'i')   return 2;
    if(ch == 'j')   return 3;
    return 4;
}

int mul[6][6];


int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);


    mul[1][1] = 1;
    mul[1][2] = 2;
    mul[1][3] = 3;
    mul[1][4] = 4;
    mul[2][1] = 2;
    mul[2][2] = -1;
    mul[2][3] = 4;
    mul[2][4] = -3;
    mul[3][1] = 3;
    mul[3][2] = -4;
    mul[3][3] = -1;
    mul[3][4] = 2;
    mul[4][1] = 4;
    mul[4][2] = 3;
    mul[4][3] = -2;
    mul[4][4] = -1;

    int t, x = 1;
    cin>>t;
    while(t--){

        cout<<"Case #"<<x++<<": ";

        int l, x;
        cin>>l>>x>>s;

        if(l*x <= 2){
            cout<<"NO\n";
            continue;
        }

        n = l*x;
        x = 0;
        for(int i=0;i<n;i++){

            arr[i] = getInt(s[x]);
            x++;
            x %= l;
        }


        memset(k, 0, sizeof(k));
        memset(jk, 0, sizeof(jk));

        bool k_seen = false;
        if(arr[n-1] == 4){
            k_seen = k[n-1] = true;
        }

        int temp = arr[n-1];
        for(int i=n-2;i>=0;i--){

            int sign = 1;
            if(temp < 0){
                sign *= -1;
                temp *= -1;
            }

            temp = sign * mul[arr[i]][temp];

// cout<<"at pos = "<<i<<" temp = "<<temp<<endl;

            if(temp == 4){
                k_seen = k[i] = true;
                continue;
            }

            if(temp == 2 && k_seen){
                jk[i] = true;
            }
        }


// for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;
// for(int i=0;i<n;i++)cout<<k[i]<<" ";cout<<endl;
// for(int i=0;i<n;i++)cout<<jk[i]<<" ";cout<<endl;

        temp = arr[0];
        bool possible = false;
        for(int i=1;i<n-1;i++){

            if(temp == 2 && jk[i]) possible = true;

            int sign = 1;
            if(temp < 0){
                sign *= -1;
                temp *= -1;
            }

            temp = sign * mul[temp][arr[i]];
        }

        if(possible)    cout<<"YES\n";
        else    cout<<"NO\n";
    }

    return 0;
}











