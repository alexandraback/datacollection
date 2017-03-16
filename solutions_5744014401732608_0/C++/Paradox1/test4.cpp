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
#define iii pair<ii,int>
#define ff first 
#define ss second
#define mod 1000000007
#define MAXN 100005 

bool cmp(ii a, ii b){
     return a.ff>b.ff;
}

int main()
{
     freopen ("B-small-attempt0 (1).in","r",stdin); 
     freopen ("B-small-attempt0 (1).out","w",stdout); 
     int i,j,b,m,q;
     si(q);
     for(int qw=1;qw<=q;qw++){
          printf("Case #%d: ",qw);
          sii(b,m);
          if(b==2){
               if(m==1){
                    printf("POSSIBLE\n");
                    printf("01\n");
                    printf("00\n");
               }
               else 
                    printf("IMPOSSIBLE\n");
          }
          else if(b==3){
               if(m==1){
                    printf("POSSIBLE\n");
                    printf("001\n");
                    printf("000\n");
                    printf("000\n");
               }
               else if(m==2){
                    printf("POSSIBLE\n");
                    printf("011\n");
                    printf("001\n");
                    printf("000\n");
               }
               else 
                    printf("IMPOSSIBLE\n");
          }
          else if(b==4){
               if(m==1){
                    printf("POSSIBLE\n");
                    printf("0001\n");
                    printf("0000\n");
                    printf("0000\n");
                    printf("0000\n");
               }
               else if(m==2){
                    printf("POSSIBLE\n");
                    printf("0011\n");
                    printf("0000\n");
                    printf("0001\n");
                    printf("0000\n");
               }
               else if(m==3){
                    printf("POSSIBLE\n");
                    printf("0111\n");
                    printf("0001\n");
                    printf("0001\n");
                    printf("0000\n");
               }
               else if(m==4){
                    printf("POSSIBLE\n");
                    printf("0111\n");
                    printf("0011\n");
                    printf("0001\n");
                    printf("0000\n");
               }
               else 
                    printf("IMPOSSIBLE\n");
          }
          else if(b==5){
               if(m==1){
                    printf("POSSIBLE\n");
                    printf("00001\n");
                    printf("00000\n");
                    printf("00000\n");
                    printf("00000\n");
                    printf("00000\n");
               }
               else if(m==2){
                    printf("POSSIBLE\n");
                    printf("00011\n");
                    printf("00000\n");
                    printf("00000\n");
                    printf("00001\n");
                    printf("00000\n");
               }
               else if(m==3){
                    printf("POSSIBLE\n");
                    printf("00111\n");
                    printf("00000\n");
                    printf("00001\n");
                    printf("00001\n");
                    printf("00000\n");
               }
               else if(m==4){
                    printf("POSSIBLE\n");
                    printf("01111\n");
                    printf("00001\n");
                    printf("00001\n");
                    printf("00001\n");
                    printf("00000\n");
               }
               else if(m==5){
                    printf("POSSIBLE\n");
                    printf("01111\n");
                    printf("00001\n");
                    printf("00011\n");
                    printf("00001\n");
                    printf("00000\n");
               }
               else if(m==6){
                    printf("POSSIBLE\n");
                    printf("01111\n");
                    printf("00011\n");
                    printf("00011\n");
                    printf("00001\n");
                    printf("00000\n");
               }
               else if(m==7){
                    printf("POSSIBLE\n");
                    printf("01111\n");
                    printf("00101\n");
                    printf("00011\n");
                    printf("00001\n");
                    printf("00000\n");
               }
               else if(m==8){
                    printf("POSSIBLE\n");
                    printf("01111\n");
                    printf("00111\n");
                    printf("00011\n");
                    printf("00001\n");
                    printf("00000\n");
               }
               else 
                    printf("IMPOSSIBLE\n");
          }
          else if(b==6){
               if(m==1){
                    printf("POSSIBLE\n");
                    printf("000001\n");
                    printf("000000\n");
                    printf("000000\n");
                    printf("000000\n");
                    printf("000000\n");
                    printf("000000\n");
               }
               else if(m==2){
                    printf("POSSIBLE\n");
                    printf("000011\n");
                    printf("000000\n");
                    printf("000000\n");
                    printf("000000\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==3){
                    printf("POSSIBLE\n");
                    printf("000111\n");
                    printf("000000\n");
                    printf("000000\n");
                    printf("000001\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==4){
                    printf("POSSIBLE\n");
                    printf("001111\n");
                    printf("000000\n");
                    printf("000001\n");
                    printf("000001\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==5){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("000001\n");
                    printf("000001\n");
                    printf("000001\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==6){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("000001\n");
                    printf("000001\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==7){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("000001\n");
                    printf("000011\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==8){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("000011\n");
                    printf("000011\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==9){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("000101\n");
                    printf("000011\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==10){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("000111\n");
                    printf("000011\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==11){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("000111\n");
                    printf("000101\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==12){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("000111\n");
                    printf("000111\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==13){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("001001\n");
                    printf("000111\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==14){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("001011\n");
                    printf("000111\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==15){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("001101\n");
                    printf("000111\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else if(m==16){
                    printf("POSSIBLE\n");
                    printf("011111\n");
                    printf("001111\n");
                    printf("000111\n");
                    printf("000011\n");
                    printf("000001\n");
                    printf("000000\n");
               }
               else 
                    printf("IMPOSSIBLE\n");
          }
     }

     return 0;
}      