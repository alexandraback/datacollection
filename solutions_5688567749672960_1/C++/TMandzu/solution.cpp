/*===============*\
|  ID: TMANDZU    |
|    LANG: C++    |
\*===============*/
//Tornike Mandzulashvili
//std::ios_base::sync_with_stdio (false);

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <assert.h>
#include <queue>
#include <iostream>
#include <set>
#include <cstring>
#include <deque>
#include <fstream>
#include <bitset>

#define endl '\n'
#define deb(x) cout << "> " << #x << " : " << (x) << endl;
#define EPS (1e-9)
#define Pi 3.1415926535897932384626433832795028841971
#define hash1 1000003
#define hash2 1000033
#define INF 1000000500
#define pb push_back
#define mp make_pair
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < int , int >
#define REP(i,a,n) for(i=a;i<n;i++)
#define big long long
#define VI vector < int >
#define DID (long long)
#define ll long long
#define AL(a) (a).begin(),(a).end()
#define INFF DID INF*INF
#define debug 1

using namespace std;

int f[1000005],fix[1000005];
int l = 0;
int d[100];

bool isPalin(ll x){
    int l = 0;
    while (x){
        d[l++]=x%10;
        x/=10;
    }
    for (int i=0;i<l/2;i++)
        if (d[i]!=d[l-i-1])
        return false;
    return true;
}
ll flip(ll x){
    int l = 0;
    while (x){
        d[l++]=x%10;
        x/=10;
    }
    ll ans = 0;
    for (int i=0;i<l;i++)
        ans = ans * 10 + d[i];
    return ans;
}

ll solve(ll n){
    ll N = n;
    l = 0;
    while (N){
        d[l++]=N%10;
        N/=10;
    }
    if (l == 1)
        return n;
    int pos = 0;

    ll ans = 0;

    while (d[pos] == d[l-pos-1] && pos+1 < l-pos-2)
        pos++;
    bool ok = true;
    int num = (l - 2)/2;
    for (int i =1;i<=num;i++)
    if (d[i])
        ok = false;
    if (d[pos] < d[l - pos - 1] && d[0] == 1 && ok){
        ans =  solve(flip(n)) + 1;
    }else
    if (l<=4 || isPalin(n) || d[0]!=1)
    ans = solve(n-1)+1;else
    {
   //     cout<<n<<endl;
        ans = 0;
        ll cur = 0;
        for (int i = num;i>=1;i--)
            cur = cur * 10 + d[i];
        ans += cur;
   //     cout<<cur<<endl;
        ans += solve(n - cur);
    }

    return ans;
}

bool good(int x){
    return x%10 == 1 && flip(x)%10==1;
}

int main(){
    freopen("text.in","r",stdin);   freopen("text.out","w",stdout);

   f[1]=1;
   fix[1]=1;

   queue <int> q;
   q.push(1);
   while (!q.empty()){
        int x = q.front();
        q.pop();
        if (x == 1000000)
            break;
        int to = x + 1;
        if (!fix[to]){
            fix[to]=1;
            f[to]=f[x]+1;
            q.push(to);
        }
        to = flip(x);
        if (!fix[to]){
            fix[to]=1;
            if (0 && good(to)){
                cout<<to<<endl;
            }
            f[to]=f[x]+1;
            q.push(to);
        }
   }

    cout<<solve(999999999999)<<endl;

   int t;
   cin>>t;
   for (int tests = 1; tests <= t; tests++) {
        int n;
        cin>>n;
        cout<<"Case #"<<tests<<": "<<solve(n)<<endl;
   }

}







