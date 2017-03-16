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
#define ii pair<int,int>
#define iii pair<ii,int>
#define ff first 
#define ss second
#define mod 1000000007
#define MAXN 100005 


int main()
{
     freopen ("C-small-attempt2.in","r",stdin); 
     freopen ("C-small-attempt2.out","w",stdout); 
     int i,j,n,q,J,P,S,k,K;
     si(q);
     for(int qw=1;qw<=q;qw++){
          printf("Case #%d: ",qw);
          siii(J,P,S);
          si(K);
          map<iii,int> ans;
          map<iii,int> used_outfit;
          map<ii,int> JP;
          map<ii,int> PS;
          map<ii,int> SJ;

          if(S!=3 || P!=3){
               rep(i,J)
                    rep(j,P)
                         rep(k,S){
                              if(used_outfit[iii(ii(i,j),k)]==0 && JP[ii(i,j)]<K && PS[ii(j,k)]<K && SJ[ii(k,i)]<K){
                                   ans[iii(ii(i+1,j+1),k+1)]=1;
                                   used_outfit[iii(ii(i,j),k)]=1;
                                   JP[ii(i,j)]++;
                                   PS[ii(j,k)]++;
                                   SJ[ii(k,i)]++;
                              }
                         }
               cout<<ans.size()<<endl;
               for(map<iii,int>::iterator it=ans.begin(); it!=ans.end(); ++it){
                    printf("%d %d %d\n",it->ff.ff.ff,it->ff.ff.ss,it->ff.ss);
               }
          }
          else {
               rep(i,J)
                    for(j=i;;){
                         for(k=j;;){
                              if(used_outfit[iii(ii(i,j),k)]==0 && JP[ii(i,j)]<K && PS[ii(j,k)]<K && SJ[ii(k,i)]<K){
                                   ans[iii(ii(i+1,j+1),k+1)]=1;
                                   used_outfit[iii(ii(i,j),k)]=1;
                                   JP[ii(i,j)]++;
                                   PS[ii(j,k)]++;
                                   SJ[ii(k,i)]++;
                              }
                              k++;
                              k%=3;
                              if(k==j)
                                   break;
                         }
                         j++;
                         j%=3;
                         if(j==i)
                              break;
                    }
               cout<<ans.size()<<endl;
               for(map<iii,int>::iterator it=ans.begin(); it!=ans.end(); ++it){
                    printf("%d %d %d\n",it->ff.ff.ff,it->ff.ff.ss,it->ff.ss);
               }
          }
     }


     return 0;
}      