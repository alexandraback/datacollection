#include<vector>
#include<iostream>
#include<stdio.h>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<climits>
#include<sstream>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>
#define ll long long

#define FL(i,a,b) for(ll i=a;i<b;i++)
#define FOR(i,n) for(ll i=0;i<n;i++)
#define SORTF(x) sort(x.begin(),x.end(),func);
#define SORT(x) sort(x.begin(),x.end())
#define pb(x) push_back(x)
#define ll long long
#define SET(v, val) memset(v, val, sizeof(v)) ;
#define RSORT(v) { SORT(v) ; REVERSE(v) ; }
#define ALL(v) v.begin(),v.end()
#define REVERSE(v) { reverse(ALL(v)) ; }
#define UNIQUE(v) unique((v).begin(), (v).end())
#define RUNIQUE(v) { SORT(v) ; (v).resize(UNIQUE(v) - (v).begin()) ; }
#define fill(x,n) memset(x,n,sizeof(x))
#define si(x) scanf("%d",&x)
#define si2(x,y) scanf("%d %d",&x,&y)
#define si3(x,y,z) scanf("%d %d %d",&x,&y,&z)
 
#define ss(x) scanf("%s",x)
 
#define sc(x) scanf("%c",&x)
 
#define sf(x) scanf("%f",&x)
 
#define sl(x) scanf("%lld",&x)
#define sl2(x,y) scanf("%lld %lld",&x,&y)
#define sl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
 
#define str string
#define lli long long int
#define ch char
#define fl float
 
#define out(x) cout << x << endl
#define out2(x,y) cout << x << " " << y << endl
#define out3(x,y,z) cout << x << " " << y << " " << z << endl
 
#define printi(x) printf("%lld\n",x)
#define printi2(x,y) printf("%lld %lld\n",x,y)
#define printi3(x,y,z) printf("%lld %lld %lld\n",x,y,z)
#define prints(x) printf("%s\n",x)
#define mod 1000000007
using namespace std;


ll visited['z'+1],fre['z'+1],a['z'+1]['z'+1],f[120],x['z'+1];

ll dfs(ll x)
{
    visited[x]=1;
 
    ll a1=f[fre[x]];

    FL(j,'a','z'+1)
    {
        if(a[x][j]&&!visited[x])
            a1=(a1*dfs(j))%mod;
    }
    return a1;
}
int main() 
{  
	f[0]=1;
	FL(i,1,101){
		f[i] = (f[i-1]*i)%mod;
	}  
   	ll t;
   	cin >> t;
   	ll ca=1;
   	while(t!=0) {
   		ll p,q,n;
   		fill(visited,0);
   		fill(fre,0);
   		fill(a,0);
   		fill(x,0);
   		cin >> n;
   		string s[n];
   		ll f1=1,f2=0;
   		FOR(i,n){
   			cin >> s[i];
   			ll be = s[i][0];
   			ll f2 = 0;
   			FL(j,1,s[i].length()){
   				ll en=s[i][j];
                if(be==en)
                    continue;
                f2=1;
                
                a[be][en]++;
                
                x[en]++;

                if(a[be][en]>1)
                    f1=0;
                be=en;
   			}
   			if(f2==0) fre[be]++;
   		}
   		FL(i,'a','z'+1){
   			ll ans = 0;
   			FL(j,'a','z'+1)
            {
                if(i==j)
                    continue;
                if(a[i][j]) ans++;
            }
            if(ans>1)
                f1=0;
   		}
   		if(f1==0){
   			cout<<"Case #"<<ca<<": 0" << endl;
   		}
   		else{
   			ll res=1;
            ll ans=0;
            FL(i,'a','z'+1)
            {
                if(visited[i]||x[i])
                   continue;
                
                ll z=0;


                
                if(fre[i])
                    z=1;
                FL(j,'a','z'+1)
                {
                    if(a[i][j])
                    z=1;
                }


                if(!z)
                    continue;

                ll z1=dfs(i);
                
                res=(res*z1)%mod;
                ans++;
            }




            res=(res*f[ans])%mod;
            cout<<"Case #"<<ca<<": "<< res<<"\n";
        }
   		

   		ca++;
   		t--;
   	}
    return 0;
}