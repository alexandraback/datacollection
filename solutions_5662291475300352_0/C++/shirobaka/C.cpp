#include <bits/stdc++.h>
using namespace std;
#define TR(i,v)       for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x)      cout<<#x<<" = "<<x<<endl
#define SIZE(p)       (int)(p).size()
#define MP(a,b)       make_pair((a),(b))
#define ALL(p)        (p).begin(),(p).end()
#define rep(i,n)      for(int i=0;i<(int)(n);++i)
#define REP(i,a,n)    for(int i=(a);i<(int)(n); ++i)
#define FOR(i,a,b)    for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,b,a)   for(int i=(int)(b);i>=(int)(a);--i)
#define CLR(x,y)      memset((x),(y),sizeof((x)))
#define eps 1e-9
typedef long long LL;
typedef pair<int,int> pii;
using namespace std;
int m1,m2,d1,d2,x,y,z;
void gao1(){
  int dis=720-d1;
  double t=(360-d2)*(m2*1.0/360.0);
  double over=dis*1.0/(360.0/(m1*1.0)) ;
  if(over>t+eps) 
    puts("0");
  else  
    puts("1");       
}
void gao2(){
  int dis =720-d2;
  double t=(360-d1)*(m1*1.0/360.0);
  double over=dis*1.0/(360.0/(m2*1.0)); 
  if(over>t+eps) 
    puts("0");
  else  
    puts("1");      
}
int main(){
  int T,n;scanf("%d",&T);
  FOR(cs,1,T){
    printf("Case #%d: ",cs);
    scanf("%d",&n);    
    if(n==1){
      scanf("%d%d%d",&x,&y,&z);
      if(y==1){
        puts("0");
        continue;
      }      
      else
        m1=z,m2=z+1,d1=x,d2=x;      
    }
    else{
      scanf("%d%d%d",&x,&y,&z);
      d1=x,m1=z;
      scanf("%d%d%d",&x,&y,&z);
      d2=x,m2=z;
    }    
    if(d1<d2)swap(m1,m2),swap(d1,d2);    
    if(m1<m2){
      gao1();
    }
    if(m1==m2)
      puts("0");
    if(m1>m2){
      gao2();
    }
  
  }
  return 0;
}