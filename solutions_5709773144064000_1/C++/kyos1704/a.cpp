#include<iomanip>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void init(){
  return ;
}
double c,f,x;
void input(){
  cin>>c>>f>>x;
}
double ans;
void solve(){
  double n =2;
  ans = x/n;
  double pre = 0;
  while(pre<ans){
    ans = min(ans,(x/n)+pre);
    pre += c/n;
    n += f;
  }
}

void print(int n){
  cout<<"Case #"<<n<<": "<<fixed<<setprecision(20)<<ans<<endl;;
}


int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    init();
    input();
    solve();
    print(i+1);
  }
}
