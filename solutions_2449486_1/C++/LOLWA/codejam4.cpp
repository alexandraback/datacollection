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
#define q(n) cin>>n
#define b(n) scanf("%I64d",&n);
typedef vector<int> vi;
typedef pair<string,int> ps;
typedef pair<int,int>pi;
typedef vector<pi> vii;
typedef vector<vii> vvii;
//vvii G(2501);
//vi d(1000,100000000);

long long  int i,j,k,t,n1,n2,n,m,c=0;
 
 //list<int> l[100001];
 /*
 class abc
 {
 long int v1;
 long int v2;
 string s;
 };
 abc arr[1000001];   */
 //long long  arr[1001][1001];

int a[101][101];
int rmax[110],cmax[110];
int main()
{
freopen("C:\\Users\\dell\\Desktop\\input.txt","r",stdin)   ;
freopen("C:\\Users\\dell\\Desktop\\output.txt","w",stdout);
sc(t);
n1=0;
w(t)
//while(sc(a))
{
  n1++;
  f(i,110)
  {
     rmax[i]=0;
     cmax[i]=0;
  }
        
  sc(n);sc(m);
  f(i,n)
  {
     f(j,m)
     {
        cin>>a[i][j];

        if(a[i][j]>rmax[i])
           rmax[i]=a[i][j];

        if(a[i][j]>cmax[j])
           cmax[j]=a[i][j];
     }
  }
  
  


 int cnt=0;
 
 bool flag=true;                              
for(i=0;i<n;i++)
{
                
for(j=0;j<m;j++)
{
           if((a[i][j]<rmax[i])&&(a[i][j]<cmax[j]))
           {
                                              cnt++;
                  
                  
                   }}}
                   
                   
cout<<"Case #"<<n1<<": ";                 
if(cnt==0)
cout<<"YES"<<endl;            
   else
   cout<<"NO"<<endl;                
                   
   }
  return 0;
}
