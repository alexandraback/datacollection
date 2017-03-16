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



int r, c, w;


bool valid(int mask){

	int cnt = 1;
	bool done = false;
	for(int i=1;i<c;i++){

		int curr = (mask>>i);
		int prev = (mask>>(i-1));

		curr %= 2;
		prev %= 2;
		if(curr == prev)	cnt++;
		else	cnt = 1;

		if(curr == 0 && cnt > w)	return false;
		if(curr == 1 && cnt >= w)	done = true;
	}

	return done;
}


int func(){

	if(w == 1)	return c;

	if(c == w || c == 2*w)	return (c/w - 1) + w;

	int cnt = c/w;
	// if(cnt == 1)	return c;

	return cnt-1 + w;

	// int ans = c;
	// for(int mask=0;mask<(1<<c);mask++){

	// 	if(!valid(mask))	continue;

	// 	ans = min(ans, __builtin_popcount(mask));
	// }

	// return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);


    freopen("A-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
    while(t--){

    	cout<<"Case #"<<x++<<": ";
    	cin>>r>>c>>w;

    	if(w == 1){
    		cout<<(r*c)<<endl;
    		continue;
    	}

    	if(w > c){
    		cout<<"0\n";
    		continue;
    	}

    	if(w == c){
    		cout<<(r-1+c)<<endl;
    		continue;
    	}

    	int cnt = r*(c/w);
    	int ans = cnt-1 + w;
    	if(c % w != 0)	ans++;
    	cout<<ans<<endl;
    }

    return 0;
}

















