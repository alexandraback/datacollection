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
int qt[MAX],pows[100];
#define q(tot) ((char)('i'-1+tot))

char s[MAX+10];

int main(){
  qt['i']=QTI; qt['j']=QTJ; qt['k']=QTK;
  int N,t,l,u,n,i,ok,tot;
  long long x,xx;
  cin>>t; for (u=0; u<t; u++){
    cin>>n>>x>>s;
    ok=1;
    
    for (tot=ONE,i=0; i<n; i++) tot=qmult(tot,qt[s[i%n]]);
    pows[0]=tot;
    for (i=1; i<63; i++) pows[i]=qmult(pows[i-1],pows[i-1]);
    for (tot=ONE,xx=x,i=0; xx; i++,xx>>=1) if (xx&1) tot=qmult(tot,pows[i]);
    if (tot!=-ONE) ok=0;
    
    N=n*16; if (x<=16) N=n*(int)x;
    for (tot=ONE,i=0; i<N; i++){
      tot=qmult(tot,qt[s[i%n]]);
      if (tot==QTI) break;
    }
    if (i==N) ok=0;
    
    N=n*32; if (x<=32) N=n*(int)x;
    for (i++; i<N; i++){
      tot=qmult(tot,qt[s[i%n]]);
      if (QTK==tot) break;
    }
    if (i==N) ok=0;
//    if (x<=32 && i==(n*(int)x)-1) ok=0;

    cout<<"Case #"<<(u+1)<<": "<<(ok?"YES":"NO")<<endl;
  }
  return 0;
}

