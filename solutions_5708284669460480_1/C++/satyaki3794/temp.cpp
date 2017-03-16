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


int k, len, s, lps[105], transition[105][27], keys[28];
char str[105];
int maxNeeded;
bool done[106][105][104];
double DP[105][105][105];


double dp(int i, int currLen, int tot){

    if(i == s){

    // cout<<"yoyoy "<<tot<<endl;
        return maxNeeded-tot;
    }
    if(done[i][currLen][tot])  return DP[i][currLen][tot];

// cout<<"at "<<i<<" "<<currLen<<" "<<tot<<endl;

    double ans = 0.00;
    for(int j=0;j<26;j++){

        if(keys[j] == 0)    continue;

        double prob = ((double)keys[j]) / k;
        int nextLen = transition[currLen][j];

        if(nextLen != len)  ans += prob * dp(i+1, nextLen, tot);
        else    ans += prob * dp(i+1, lps[len-1], tot+1);
    }

    done[i][currLen][tot] = true;
    return DP[i][currLen][tot] = ans;
}


int main()
{
    // ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);


    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    scanf("%d", &t);
    while(t--){

        printf("Case #%d: ", x++);
        memset(keys, 0, sizeof(keys));

        scanf("%d%d%d", &k, &len, &s);
        scanf("%s", str);
        for(int i=0;i<k;i++)
            keys[str[i]-'A']++;
        scanf("%s", str);

        lps[0] = 0;
        for(int i=1;i<len;i++){

            int j = lps[i-1];
            while(j > 0 && str[i] != str[j])    j = lps[j-1];
            if(str[i] == str[j])    j++;
            lps[i] = j;
        }


        for(int i=0;i<len;i++)
            for(int j=0;j<26;j++){

                int temp = i;
                while(temp > 0 && str[temp]-'A' != j) temp = lps[temp-1];
                if(str[temp]-'A' == j)    temp++;
                transition[i][j] = temp;
            }

// cout<<"transition\n";
// for(int i=0;i<len;i++){
//     cout<<i<<" : ";
//     for(int j=0;j<26;j++)    cout<<transition[i][j]<<" ";cout<<endl;
// }

        bool impossible = false;
        for(int i=0;i<len;i++)
            if(keys[str[i]-'A'] == 0)   impossible = true;


        if(s < len || impossible) maxNeeded = 0;
        else    maxNeeded = 1 + (s-len)/(len-lps[len-1]);

// cout<<maxNeeded<<" ";

        memset(done, 0, sizeof(done));
        double ans = dp(0, 0, 0);
        printf("%.6lf\n", ans);
    }


    return 0;
}

















