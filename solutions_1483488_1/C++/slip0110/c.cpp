#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
bool used[2000010];
int main(){
  int T;
  cin>>T;
  for(int t = 1 ; t <= T ; t++){
    int a,b;
    cin>>a>>b;
    memset(used,0,sizeof(used));
    int loop = 0;
    int ca = a;
    while(ca){
      ca/=10;
      loop++;
    }
    int ans = 0;
    for(int i = a ; i<=b;i++){
      if(used[i])continue;
      int count = 1;
      int cur = i;
      used[cur] = true;
      for(int j = 0 ; j < loop-1 ; j++){
        int tmp = cur % 10;
        cur /= 10;
        cur += (int)pow(10,loop-1) * tmp;
        if(a <= cur && cur<=b&&!used[cur]){
          count++;
          used[cur] = true;
        }
      }
      ans += count*(count-1)/2;
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
}
