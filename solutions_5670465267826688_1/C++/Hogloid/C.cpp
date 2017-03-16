#define DEB

#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

//const int INF=5e8;

int mult[5][5]={
  {0,0,0,0,0},
  {0,1,2,3,4},
  {0,2,-1,4,-3},
  {0,3,-4,-1,2},
  {0,4,3,-2,-1}
};

int n;
lint x;


int sum[10005];
char L[10005];

int calc(int a,int b){
  int sign=(a>0?1:-1)*(b>0?1:-1);
  return mult[abs(a)][abs(b)]*sign;
}

int getleft(int tot,int right){
  for(int i=-4;i<=4;++i) if(calc(i,right)==tot) return i;
}
int getright(int tot,int left){
  for(int i=-4;i<=4;++i) if(calc(left,i)==tot) return i;
}
int code[300];

int mpow(int a,lint k){
  int res=1;
  while(k>0){
    if(k&1) res=calc(res,a);
    a=calc(a,a);
    k>>=1;
  }
  return res;
}


bool solve(){
  scanf("%d%lld",&n,&x);
  scanf("%s",L);

  sum[0]=1;

  REP(i,n) sum[i+1]=calc(sum[i],code[L[i]]);

  int tot=mpow(sum[n],x);
  if(tot!=-1) return false;
  else{
    REP(i,n) REP(j,n){
      int val1=sum[i],val2;
      if(i<=j){
        val2=getright(sum[j],sum[i]);

        int val12=val1,val22;
        REP(p,4){
          val22=val2;
          REP(q,4){
            if(val12==2 && val22==3 && p+q+1<=x){
              return true;
            }
            val22=calc(val22,sum[n]);
          }
          val12=calc(sum[n],val12);
        }
      }else{
        val2=calc(getright(sum[n],sum[i]),sum[j]);
        int val12=val1,val22;
        REP(p,4){
          val22=val2;
          REP(q,4){
            if(val12==2 && val22==3 && p+q+2<=x){
              return true;
            }
            val22=calc(val22,sum[n]);
          }
          val12=calc(sum[n],val12);
        }
      }
    }
  }
  return false;
}
int main(){
  code['1']=1;
  code['i']=2;
  code['j']=3;
  code['k']=4;
  int t;scanf("%d",&t);
  REP(setn,t){
    printf("Case #%d: %s\n",setn+1,solve()?"YES":"NO");
  }




  return 0;

}



