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


int main(){
    freopen("text.in","r",stdin);   freopen("text.out","w",stdout);

    int t;
    cin>>t;
    for (int test = 1; test <= t; test++){
        int n,st,num,tst;
        cin>>n;
        vector <PI> v;
        for (int i = 1; i<=n;i++){
            cin>>st>>num>>tst;
            for (int j=1;j<=num;j++)
                v.pb(mp(st, tst + j - 1));
        }
        int ans = 0;
        if (v.S == 2){
            double V0 = 360.0/v[0].se;
            double V1 = 360.0/v[1].se;
            if (v[0].se != v[1].se){
                if ( (360.0 - v[0].fi)/V0 > (360.0 - v[1].fi)/V1)
                    swap(v[0],v[1]), swap(V0,V1);
                double timee1 = ( 360 + 360 - v[0].fi )/V0;
                double timee2 =  (360 - v[1].fi) / V1;
                if (timee1 - EPS < timee2)
                    ans = 1;
            }
        }

        cout<<"Case #"<<test<<": "<<ans<<endl;
    }
}







