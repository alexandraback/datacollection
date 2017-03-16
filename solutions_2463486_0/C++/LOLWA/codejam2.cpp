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
 long long a[1000001];
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




bool palin(ll bn)
{
if(0<bn&&bn<10)
return false;

ll r=bn,rem;
ll sum=0;
while(r>0)
{
rem=r%10;
sum=(sum*10+rem);          
r=r/10;
}

if(sum==bn)
return true;
return false;
}


int main()
{
freopen("C:\\Users\\dell\\Desktop\\input.txt","r",stdin)   ;
freopen("C:\\Users\\dell\\Desktop\\output.txt","w",stdout);
n1=1;
sc(t);
w(t)
//while(sc(a))
{
              
  sc(n);sc(k);
  c=int (sqrt(n));
  if(c*c==n)
  i=c;
  else
  i=c+1;
  ll count=0;
for(;i*i<=k;i++)
{if(i==1||i==2||i==3)
{count++;
         continue;            }
  if(palin(i)&&palin(i*i)){//cout<<i<<endl;
  count++;}
  
                }
                
printf("Case #%d: ",n1);
n1++;
                cout<<count<<endl;



}
  return 0;
}
