//Mitesh Agrawal
#include <bits/stdc++.h>
using namespace std;
 
#define gc getchar
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define pis(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
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

int l;
ii best;

bool cmp(ii a, ii b){
     return abs(a.ff - a.ss) < abs(b.ff - b.ss);
}

int len(int n){
     int i,it=0;
     while(n){
          it++;
          n/=10;
     }
     return it;
}

ii make(string s, string t){
     int i;
     ii best1=ii(0,0);
     rep(i,l)
          best1.ff=best1.ff*10+s[i]-'0';
     rep(i,l)
          best1.ss=best1.ss*10+t[i]-'0';
     return best1;
}

ii solve(int i, int flag, string s, string t){
     // cout<<i<<" "<<flag<<endl;
     if(i==l){
          ii it=make(s,t);
          if(best==ii(-1,-1) || cmp(it,best)){
               best=it;
          }
          return it;
     }
     if(s[i]=='?' && t[i]=='?' && flag==0){
          s[i]='0';
          t[i]='0';
          ii it=solve(i+1,0,s,t);
          s[i]='1';
          t[i]='0';
          ii it1=solve(i+1,1,s,t);
          s[i]='0';
          t[i]='1';
          ii it2=solve(i+1,2,s,t);
          if(cmp(it1,it))
               it=it1;
          if(cmp(it2,it))
               it=it2;
          return it;
     }
     else if(s[i]=='?' && t[i]=='?' && flag==1){
          s[i]='0';
          t[i]='9';
          return solve(i+1,1,s,t);
     }
     else if(s[i]=='?' && t[i]=='?' && flag==2){
          s[i]='9';
          t[i]='0';
          return solve(i+1,2,s,t);
     }
     else if(s[i]=='?' && flag==0){
          ii it=ii(-1,-1);
          ii it1=ii(-1,-1);
          ii it2=ii(-1,-1);

          s[i]=t[i];
          it=solve(i+1,0,s,t);
          if(t[i]!='0'){
               s[i]=t[i]-1;
               it1=solve(i+1,2,s,t);
          }

          if(t[i]!='9'){
               s[i]=t[i]+1;
               it1=solve(i+1,1,s,t);
          }
          
          if(it1!=ii(-1,-1) && cmp(it1,it))
               it=it1;
          if(it1!=ii(-1,-1) && cmp(it2,it))
               it=it2;
          return it;
     }
     else if(t[i]=='?' && flag==0){
          ii it=ii(-1,-1);
          ii it1=ii(-1,-1);
          ii it2=ii(-1,-1);

          t[i]=s[i];
          it=solve(i+1,0,s,t);
          if(s[i]!='0'){
               t[i]=s[i]-1;
               it1=solve(i+1,1,s,t);
          }

          if(s[i]!='9'){
               t[i]=s[i]+1;
               it1=solve(i+1,2,s,t);
          }
          
          if(it1!=ii(-1,-1) && cmp(it1,it))
               it=it1;
          if(it1!=ii(-1,-1) && cmp(it2,it))
               it=it2;
          return it;
     }
     else if(s[i]=='?' && flag==1){
          s[i]='0';
          return solve(i+1,1,s,t);
     }
     else if(t[i]=='?' && flag==1){
          t[i]='9';
          return solve(i+1,1,s,t);
     }
     else if(s[i]=='?' && flag==2){
          s[i]='9';
          return solve(i+1,2,s,t);
     }
     else if(t[i]=='?' && flag==2){
          t[i]='0';
          return solve(i+1,2,s,t);
     }
     else {
          if(flag!=0)
               return solve(i+1,flag,s,t);
          else if(s[i]>t[i])
               return solve(i+1,1,s,t);
          else if(s[i]<t[i])
               return solve(i+1,2,s,t);
          else 
               return solve(i+1,flag,s,t);
          
     }
}

int main()
{
     freopen ("B-large (1).in","r",stdin); 
     freopen ("B-large (1).out","w",stdout);  
     int i,qw,j,n,t1,flag;
     string s,t;
     si(t1);
     fu(qw,1,t1){
          best=ii(-1,-1);
          cin>>s>>t;
          l=s.size();

          solve(0,0,s,t);
          printf("Case #%d: ",qw);
          // cout<<best.ff<<" "<<best.ss<<endl;
          rep(i,l-len(best.ff))
               pll(0ll);
          if(best.ff!=0)
               pll(best.ff);
          ps;
          rep(i,l-len(best.ss))
               pll(0ll);
          if(best.ss!=0)
               pll(best.ss);
          pn;
     }


     return 0;
}      