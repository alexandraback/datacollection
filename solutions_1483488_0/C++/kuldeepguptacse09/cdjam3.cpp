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
int C[2000006][3];
 int Co(int n, int r)

{

   

 

    for (int i=0; i<=n; i++)

    {

        for (int k=0; k<=r && k<=i; k++)

            if (k==0 || k==i)

                C[i][k] = 1;

            else

                C[i][k] = (C[i-1][k-1] + C[i-1][k])%MOD;

    }

    return C[n][r];

}
   
int main()
{freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   int t,i,j,n,k,m,p,l;
    Co(2000000,2);
    in(t);l=1;
    while(l<=t){
    set<int> s;
    
    int c=0;
    in(n);in(m);fa(i,n,m+1)s.insert(i);
    while(!s.empty()){int c1=1;k=*(s.begin());s.erase(k);
                                int d=10,tm=k;
                                while(tm/d){
                                           int nm=nod(k/d)*(k%d)+(k/d);
                                           if(s.count(nm)==1){c1++;s.erase(nm);}
                                          
                                           d*=10;
                                           }
                             c+=C[c1][2];
                      }
    
    
    printf("Case #%d: %d\n",l,c);
    
    l++;}
    
    
    return 0;}
