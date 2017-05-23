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
int flip(int x){
    int l = 0;
    while (x){
        d[l++]=x%10;
        x/=10;
    }
    int ans = 0;
    for (int i=0;i<l;i++)
        ans = ans * 10 + d[i];
    return ans;
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
            f[to]=f[x]+1;
            q.push(to);
        }
   }

   int t;
   cin>>t;
   for (int tests = 1; tests <= t; tests++) {
        int n;
        cin>>n;
        cout<<"Case #"<<tests<<": "<<f[n]<<endl;
   }

}







