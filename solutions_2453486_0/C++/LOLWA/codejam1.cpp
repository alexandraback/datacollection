using namespace std;
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
#include<cctype>
#include<list>
#include<set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define f(i,n) for(i=0;i<n;i++)
#define fr(i,n,x) for(i=x;i<=n;i++)
#define w(t) while(t--)
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(a,b)  { return (b==0)?a:gcd(b,a%b); }
#define lcm(a,b)  { return a*b/gcd(a,b);  }
#define  sc(a)   scanf("%lld",&a)
#define  p(a)   printf("%lld\n",&a)
#define  str(s)   cin>>s
#define  ps(s)     cout<<s<<endl
#define  print(s)  printf("%s\n",s.c_str())
#define lt(v,k) list<int>v[k]
#define ll long long
long long  int i,j,k,t,n1,n2,n,m,c=0;
 int main()
{
freopen("C:\\Users\\dell\\Desktop\\input.txt","r",stdin)   ;
freopen("C:\\Users\\dell\\Desktop\\output.txt","w",stdout);
char s[4][4];
ll cntx=0,cnto=0,cnt=0,cnz=0;

c=1;
sc(t);
while(t--)
//while(sc(a))
{
              cntx=0,cnto=0,cnt=0,cnz=0;
for(i=0;i<4;i++)
{
                for(j=0;j<4;j++)
                {
                                cin>>s[i][j];
                                }}
bool flag=false;

printf("Case #%d: ",c);
c++;
if(!flag)
{i=0;
    while(!flag&&i<4)
    {
            cntx=0;cnto=0;cnt=0;         
                        
for(j=0;j<4;j++)
{if(s[i][j]=='X')
cntx++;
if(s[i][j]=='O')
cnto++;
       if(s[i][j]=='T')
       cnt++; if(s[i][j]=='.')cnz++;        
                }
i++;
 if(cntx+cnt==4){printf("X won\n");flag=true;}              
 else if(cnto+cnt==4){printf("O won\n");flag=true;}

}}
  

if(!flag)
{i=0;
 

    while(!flag&&i<4)
    { cntx=0;cnto=0;cnt=0;
                     
                        
for(j=0;j<4;j++)
{if(s[j][i]=='X')
cntx++;
if(s[j][i]=='O')
cnto++;
       if(s[j][i]=='T')
       cnt++; if(s[j][i]=='.')cnz++;        
                }
i++;
 if(cntx+cnt==4){printf("X won\n");flag=true;}              
 else if(cnto+cnt==4){printf("O won\n");flag=true;}

}}








if(!flag)
{



  cntx=0;cnt=0;cnto=0;
for(i=0;i<4;i++)

{if(s[i][i]=='X')
cntx++;
if(s[i][i]=='O')
cnto++;
       if(s[i][i]=='T')
       cnt++; if(s[i][i]=='.')cnz++;        
                }
                //cout<<cnto<<endl;
 if(cntx+cnt==4){printf("X won\n");flag=true;}              
 else if(cnto+cnt==4){printf("O won\n");flag=true;}

}

if(!flag)
{cntx=0;cnto=0;cnt=0;n=4;
    for(i=0;i<n;i++)
         {
                         
         if(s[i][n-1-i]=='X')
cntx++;
if(s[i][n-1-i]=='O')
cnto++;
       if(s[i][n-1-i]=='T')
       cnt++; 
       if(s[i][n-1-i]=='.')cnz++;        
                }
 if(cntx+cnt==4){printf("X won\n");flag=true;}              
 else if(cnto+cnt==4){printf("O won\n");flag=true;}
 }
         
        
         
if(!flag&&cnz>0)printf("Game has not completed\n");
else
if(!flag&&(cnz==0))printf("Draw\n");


}
  return 0;
}
