// 出来るだけ大きい数字においてたくさん消費するのが得策
// 大きい順に消費エネルギーを決めていく
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
typedef pair<long,long> P;
typedef long long lli;
#define REP(i,x)for(int i=0;i<(int)x;i++)
long E,R,N;
long V[10000];
P ord[10000];
long INF = 1LL << 60;
class RMQ{
  private:
    vector<long> val;
    int n;
  public:
    RMQ(int size){
      n=1;
      while(n<size)n<<=1;
      val=vector<long>(2*n,INF);
    }
    //x番目の要素をaに更新する
    void update(int x,long a){
      x+=n-1;
      val[x]=a;
      while(x>0){
        x=(x-1)/2;
        val[x]=min(val[x*2+1],val[x*2+2]);
      }
    }
    //a<=x<b
    long minimum(int a,int b,int k=0,int l=0,int r=-1){
      if(r==-1)r=n;
      if(r<=a||b<=l)return INF;
      if(a<=l&&r<=b){
        return val[k];
      }else{
        return min(minimum(a,b,k*2+1,l,(l+r)/2),minimum(a,b,k*2+2,(l+r)/2,r));
      }
    }
};
lli maxEs, minEs;
int main(){
  int T;
  cin>>T;
  for(int caze=1;caze<=T;caze++){
    cin>>E>>R>>N;
    REP(i,N){
      cin>>V[i];
      ord[i]=P(-V[i],i);
    }
    maxEs = E;
    minEs = 0;
    sort(ord,ord+N);
    RMQ minE(N),maxE(N); 
    lli ans = 0;
    for(int i=0;i<N;i++){
      int k = ord[i].second;
      long mi = max<lli>(0, -minE.minimum(k,N) + k * R); // 右にあるMIN直線の最大を得る
      long use= min<lli>(E, maxE.minimum(0,k) + k * R); // 左にあるmax直線の最小を得る
      // 0に正規化
      lli l = mi - (lli)R * k;
      maxE.update(k,l);

      lli l2 = use -  (lli)R * k;
      minE.update(k,-l2);
      ans -= (use - mi) * ord[i].first;
    }
    cout << "Case #"<<caze<<": "<<ans<<endl;

  }

}
