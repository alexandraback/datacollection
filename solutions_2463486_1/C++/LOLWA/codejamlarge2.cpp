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


ll a[41]={1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};
int main()
{
freopen("C:\\Users\\dell\\Desktop\\input.txt","r",stdin)   ;
freopen("C:\\Users\\dell\\Desktop\\output.txt","w",stdout);
//sc(t);
//w(t)
//while(sc(a))
m=1;

sc(t);
w(t)
{
 sc(n);sc(k);c=0;
 int index,in;
  n1=(ll)ceil(sqrt(n));
  n2=(ll)floor(sqrt(k));
  
              for(i=0;i<39;i++)
              {
                               
                        if(n1<=a[i]&&a[i]<=n2)
                        c++;     
                               
                               }
                    
                    printf("Case #%lld: ",m);
     m++;
                    
                    cout<<c<<endl;
                    
                    }
                    
  
  return 0;
}
