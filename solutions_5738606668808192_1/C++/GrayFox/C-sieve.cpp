#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

#define ANS(n, r) cout<<"Case #"<<n<<": "<<r<<endl
#define MAXN  (1l<<20l)-1
#define SQRT_MAXN  (1l<<10l)

bool *p;


int main(){
  p=new bool[MAXN];
  p[0]=false;
  p[1]=false;
  memset(p,1,sizeof(bool)*MAXN);
  for(long long i=4; i<MAXN; i+=2){
    p[i] = false;
  }
  for(long long i=3;i<SQRT_MAXN;i+=2){
    DBL(i)
    if(p[i]){
      for(long long j=i+i;j<MAXN;j+=i){
        DB(i) DBL(j)
        p[j]=false;
      }
    }
  }
  cout<<2<<endl;
  for(long long i=3;i<MAXN;i+=2){
    if(p[i]){
      cout<<i<<endl;
    }
  }
}
