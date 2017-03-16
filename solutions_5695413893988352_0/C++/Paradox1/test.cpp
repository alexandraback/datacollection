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
#define ii pair<int,int>
#define iii pair<ii,ll>
#define ff first 
#define ss second
#define mod 1000000007
#define MAXN 100005 


bool valid(int n, string s){
     int i,l;
     l=s.size();
     fd(i,l-1,0){
          if(s[i]=='?' || (s[i]!='?' && n%10==s[i]-'0')){
               n/=10;
          }
          else 
               return false;
     }
     if(n==0)
          return true;
     else 
          return false;
}

int len(int n){
     int i,it=0;
     while(n){
          it++;
          n/=10;
     }
     return it;
}

int main()
{
     freopen ("B-small-attempt2.in","r",stdin); 
     freopen ("B-small-attempt2.out","w",stdout);  
     
     int i,j,n,t1,qw;
     si(t1);
     string s,t;
     fu(qw,1,t1){
          ii best=ii(0,999);
          cin>>s>>t;
          int l=s.size();
          rep(i,1000)
               rep(j,1000){
                    if(valid(i,s) && valid(j,t) && abs(i-j)<abs(best.ff-best.ss)){
                         best=ii(i,j);
                    }
               }
          printf("Case #%d: ",qw);
          // cout<<best.ff<<" "<<best.ss<<endl;
          rep(i,l-len(best.ff))
               pi(0);
          if(best.ff!=0)
               pi(best.ff);
          ps;
          rep(i,l-len(best.ss))
               pi(0);
          if(best.ss!=0)
               pi(best.ss);
          pn;
     }

     return 0;
}      