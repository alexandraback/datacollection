#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<set>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define fa(i,a,n) for(i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define MOD  1000000009ll
inline int nod(int n){
    int d=10;
    while(n/d)d*=10;
    return d;
    }
char f[2000009];

   
int main()
{freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   int t,i,j,n,k,m,p,l;
   
    in(t);l=1;
    while(l<=t){
    memset(f,0,sizeof(f));
    
    long long c=0;
    in(n);in(m);
    for(k=n;k<=m;k++)if(f[k]==0){f[k]=1;
                                int d=10,tm=k;
                                long long c1=1;
                                while(tm/d){
                                           int nm=nod(k/d)*(k%d)+(k/d);
                                           if(nm<=m&&nm>=n&&f[nm]==0){c1++;f[nm]=1;}
                                          
                                           d*=10;
                                           }
                                      //printf("%lld\n",C[c1]);     
                             c+=(c1*(c1-1))>>1ll;
                      }
    
    
    printf("Case #%d: %lld\n",l,c);
    
    l++;}
    
    
    return 0;}
