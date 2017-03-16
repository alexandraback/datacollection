// 出来るだけ大きい数字においてたくさん消費するのが得策
// 大きい順に消費エネルギーを決めていく
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;
typedef pair<int,int> P;
typedef long long lli;
#define REP(i,x)for(int i=0;i<(int)x;i++)
int E,R,N;
int V[10000];
int minE[10000],maxE[10000];
P ord[10000];
int main(){
  int T;
  cin>>T;
  for(int caze=1;caze<=T;caze++){
    cin>>E>>R>>N;
    REP(i,N){
      cin>>V[i];
      ord[i]=P(-V[i],i);
      minE[i]=0;
      maxE[i]=E;
    }
    sort(ord,ord+N);
    lli ans = 0;
    for(int i=0;i<N;i++){
      int k = ord[i].second;
      for(int use=maxE[k];use>=minE[k];use--){
        bool ok = true;
        int cpmin[10000],cpmax[10000];
        memcpy(cpmin,minE,sizeof(minE));
        memcpy(cpmax,maxE,sizeof(minE));
        int m = maxE[k];
        int mi = minE[k];
        minE[k]=use;
        maxE[k]=use;
        for(int j=1;j+k<N;j++){
          maxE[j+k]=min(maxE[j+k],mi + j * R);
          //if(maxE[j+k] < minE[j+k])ok=false;
        }
        for(int j=1;k-j>=0;j++){
          minE[k-j]=max(minE[k-j],use - j * R);
          //if(maxE[k-j] < minE[k-j])ok=false;
        }
        if(ok){
          ans -= (use - mi) * ord[i].first;
          break;
        }
        memcpy(minE,cpmin,sizeof(minE));
        memcpy(maxE,cpmax,sizeof(minE));
      }
    }
    cout << "Case #"<<caze<<": "<<ans<<endl;

  }

}
