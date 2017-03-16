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
#define ii pair<string,string>
#define iii pair<ii,ll>
#define ff first 
#define ss second
#define mod 1000000007
#define MAXN 100005 

ii v[20];

int main()
{
     freopen ("C-small-attempt0.in","r",stdin); 
     freopen ("C-small-attempt0.out","w",stdout); 
     int i,j,n,t,qw,maxi,flag,it;
     si(t);
     fu(qw,1,t){
          maxi=-1;
          si(n);
          rep(i,n){
               cin>>v[i].ff>>v[i].ss;
          }
          rep(i,(1<<n)){
               map<string,int> m1;
               map<string,int> m2;
               rep(j,n){
                    // pis(((i>>j)&1));
                    if(((i>>j)&1)==1){
                         m1[v[j].ff]=1;
                         m2[v[j].ss]=1;
                    }
               }
               // pn;
               flag=true;
               it=0;
               rep(j,n){
                    if(((i>>j)&1)==0 && (m1[v[j].ff]!=1 || m2[v[j].ss]!=1)){
                         // cout<<"        "<<j<<" "<<m1[v[j].ff]<<" "<<m1[v[j].ss]<<endl;
                         flag=false;
                         break;
                    }
                    if(((i>>j)&1)==0)
                         it++;
               }
               if(flag){
                    // cout<<" yeah "<<i<<endl;
                    maxi=max(maxi,it);
               }
          }
          printf("Case #%d: ",qw);
          pin(maxi);
     }


     return 0;
} 