#include <iostream>
#include <algorithm>
using namespace std;

#define ONE 4
#define QTI 1
#define QTJ 2
#define QTK 3
#define abs(x) (((x)>0)?(x):(-(x)))

int tt[][5]={
  {0,0,0,0,0},
  {0,-ONE,QTK,-QTJ,QTI},
  {0,-QTK,-ONE,QTI,QTJ},
  {0,QTJ,-QTI,-ONE,QTK},
  {0,QTI,QTJ,QTK,ONE}};

int qmult(int a, int b){
  int aa=abs(a),bb=abs(b);
  return tt[aa][bb]*(a/aa)*(b/bb);
}

#define MAX 10000
int qt[MAX];
#define q(tot) ((char)('i'-1+tot))

char s[MAX+10];
#define BASE 4

int main(){
  qt['i']=QTI; qt['j']=QTJ; qt['k']=QTK;
  int N,t,l,u,n,i,ok,tot,all;
  long long x,xx;
  cin>>t; for (u=0; u<t; u++){
    cin>>n>>x>>s;
    ok=1;
    
    for (all=ONE,i=0; i<n; i++) all=qmult(all,qt[s[i%n]]);
    for (tot=ONE,xx=x&3; xx; xx--) tot=qmult(tot,all);
    if (tot!=-ONE) ok=0;
    
    N=n*BASE; if (x<=BASE) N=n*(int)x;
    for (tot=ONE,i=0; i<N; i++){
      tot=qmult(tot,qt[s[i%n]]);
      if (tot==QTI) break;
    }
    if (i==N) ok=0;
    
    N=n*2*BASE; if (x<=(2*BASE)) N=n*(int)x;
    for (i++; i<N; i++){
      tot=qmult(tot,qt[s[i%n]]);
      if (QTK==tot) break;
    }
    if (i==N) ok=0;

    cout<<"Case #"<<(u+1)<<": "<<(ok?"YES":"NO")<<endl;
  }
  return 0;
}

