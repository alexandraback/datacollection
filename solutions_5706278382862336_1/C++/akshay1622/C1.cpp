#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
double a[100];
long long  gcd( long long  a, long long b){
 long long  t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
 
  return a;

}
int main()
{
 freopen("C1.txt","r",stdin);
 freopen("C1a.txt","w",stdout);
 a[0]=1;
 for(int i=1;i<45;++i)
 {a[i]=(double)(a[i-1]/2.0);}
 //for(int i=0;i<45;++i)
 //cout<<a[i]<<" ";
 int t;
 cin>>t;
 for(int i=1;i<=t;++i)
 {
  long long int p,q,x,ans,y;
  scanf("%lld/%lld",&p,&q);
  y=gcd(p,q);
  p=p/y;
  q=q/y;
  double z=double(p)/double(q);
  x=q;
  while(x>1)
  {
   if(x%2!=0)
   goto xy;
   else
   x/=2;        
  }
  //cout<<z<<" ";
  for(int j=0;j<=40;++j)
  if(z>=a[j])
  {ans=j;break;}
  printf("Case #%d: %d\n",i,ans);
  continue;
  xy:
  printf("Case #%d: impossible\n",i);        
 }    
}
