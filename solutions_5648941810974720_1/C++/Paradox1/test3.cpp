//Mitesh Agrawal
#include <bits/stdc++.h>
using namespace std;
 
#define gc getchar
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define pis(n) printf("%d ",n)
#define pll(n) printf("%d",n)
#define plls(n) printf("%lld ",n)
#define plln(n) printf("%lld\n",n)
#define ps printf(" ")
#define pn printf("\n")
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define siii(k,n,m) scanf("%d %d %d",&k,&n,&m)
#define rep(i,n) for(i=0;i<n;i++)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define ff first 
#define ss second
#define mod 1000000007
#define MAXN 100005 

int main()
{
     freopen ("A-large.in","r",stdin); 
     freopen ("A-large.out","w",stdout); 
     int i,j,n,t,l,qw,mini;
     string s;
     si(t);
     fu(qw,1,t){
          cin>>s;
          map<char,int> m;
          vector<int> v(10);
          l=s.size();
          rep(i,l)
               m[s[i]]++;

          v[0]=m['Z'];
          v[2]=m['W'];     
          v[4]=m['U'];     
          v[6]=m['X'];     
          v[8]=m['G'];

          v[1]=m['O']-v[2]-v[4]-v[0];
          v[3]=m['H']-v[8];
          v[5]=m['F']-v[4];
          v[7]=m['S']-v[6];
          v[9]=m['I']-v[5]-v[6]-v[8];     

          printf("Case #%d: ",qw);
          rep(i,10){
               rep(j,v[i])
                    pi(i);
          }pn;
     }

     return 0;
}      